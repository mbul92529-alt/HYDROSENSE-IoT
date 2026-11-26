/*
  HYDROSENSE-IoT | ESP32 starter firmware
  IMPORTANT: Example pin assignments and generic sensor conversions only.
  Calibrate sensors and verify the actual board/module datasheets before use.
*/
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "HYDROSENSE"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// EXAMPLE GPIO mapping — change to match your wiring.
constexpr int PH_PIN = 34;       // analog input only
constexpr int TDS_PIN = 35;      // analog input only
constexpr int WATER_TEMP_PIN = 4; // DS18B20 data; requires OneWire library
constexpr int WATER_LEVEL_PIN = 27;
constexpr int PUMP_RELAY_PIN = 26;
constexpr int LIGHT_RELAY_PIN = 25;

// Many relay boards are active LOW. Verify before connecting a load.
constexpr int RELAY_ON = LOW;
constexpr int RELAY_OFF = HIGH;

BlynkTimer timer;
bool autoMode = false;
bool pumpOn = false;
bool lightOn = false;

float readVoltage(int pin) {
  return analogRead(pin) * (3.3f / 4095.0f);
}

// Placeholder conversions: calibrate against certified buffer/standard solutions.
// pH slope/offset and TDS polynomial vary by sensor board and installation.
float readPH() {
  float voltage = readVoltage(PH_PIN);
  return 7.0f + ((2.50f - voltage) * 3.5f); // NOT calibrated
}
float readTDS() {
  float voltage = readVoltage(TDS_PIN);
  return voltage * 500.0f; // placeholder ppm scale; NOT calibrated
}
bool waterPresent() { return digitalRead(WATER_LEVEL_PIN) == HIGH; }

void setPump(bool on) {
  // Fail-safe: never run pump when water-level input indicates low/absent water.
  pumpOn = on && waterPresent();
  digitalWrite(PUMP_RELAY_PIN, pumpOn ? RELAY_ON : RELAY_OFF);
  Blynk.virtualWrite(V4, pumpOn);
}
void setLight(bool on) {
  lightOn = on;
  digitalWrite(LIGHT_RELAY_PIN, lightOn ? RELAY_ON : RELAY_OFF);
  Blynk.virtualWrite(V5, lightOn);
}

BLYNK_WRITE(V4) { if (!autoMode) setPump(param.asInt()); }
BLYNK_WRITE(V5) { setLight(param.asInt()); }
BLYNK_WRITE(V6) {
  autoMode = param.asInt();
  if (!autoMode) setPump(false);
}

void publishReadings() {
  float ph = readPH();
  float tds = readTDS();
  bool level = waterPresent();

  Blynk.virtualWrite(V0, ph);
  Blynk.virtualWrite(V1, tds);
  Blynk.virtualWrite(V3, level ? 1 : 0);

  if (!level) setPump(false);

  // Example control policy only. Tune thresholds for the crop and system.
  if (autoMode) {
    bool withinExampleRange = (ph >= 5.5f && ph <= 6.5f && tds >= 500 && tds <= 1200);
    setPump(level && withinExampleRange);
  }

  Serial.printf("pH=%.2f TDS=%.0f ppm water=%s pump=%s\n",
                ph, tds, level ? "OK" : "LOW", pumpOn ? "ON" : "OFF");
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  pinMode(WATER_LEVEL_PIN, INPUT);
  pinMode(PUMP_RELAY_PIN, OUTPUT);
  pinMode(LIGHT_RELAY_PIN, OUTPUT);
  digitalWrite(PUMP_RELAY_PIN, RELAY_OFF);
  digitalWrite(LIGHT_RELAY_PIN, RELAY_OFF);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(3000L, publishReadings);
}
void loop() {
  Blynk.run();
  timer.run();
}
