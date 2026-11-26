#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "HYDROSENSE"
#define BLYNK_AUTH_TOKEN "PASTE_YOUR_BLYNK_AUTH_TOKEN_HERE"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define PH_PIN 34
#define TDS_PIN 35
#define DHT_PIN 15
#define DHT_TYPE DHT22
#define TRIG_PIN 5
#define ECHO_PIN 18
#define PUMP_PIN 26
#define LIGHT_PIN 27

DHT dht(DHT_PIN, DHT_TYPE);
BlynkTimer timer;

bool pumpOn = false;
bool lightOn = false;

float readPH() {
  int raw = analogRead(PH_PIN);
  // SIMULATION ONLY: map potentiometer position to a plausible pH range.
  return 4.0 + (raw / 4095.0) * 5.0;
}

float readTDS() {
  int raw = analogRead(TDS_PIN);
  // SIMULATION ONLY: map potentiometer position to a plausible TDS range.
  return (raw / 4095.0) * 1200.0;
}

float readWaterLevel() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;
  float distanceCm = duration * 0.0343 / 2.0;
  // Container depth assumed to be 30 cm for this demonstration.
  float level = (30.0 - distanceCm) / 30.0 * 100.0;
  return constrain(level, 0, 100);
}

void sendSensorData() {
  float ph = readPH();
  float tds = readTDS();
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float waterLevel = readWaterLevel();

  if (isnan(temperature)) temperature = 0;
  if (isnan(humidity)) humidity = 0;

  Serial.printf("pH: %.2f | TDS: %.0f ppm | Temp: %.1f C | Level: %.0f%%\n",
                ph, tds, temperature, waterLevel);

  Blynk.virtualWrite(V0, ph);
  Blynk.virtualWrite(V1, tds);
  Blynk.virtualWrite(V2, temperature);
  Blynk.virtualWrite(V3, waterLevel);
  Blynk.virtualWrite(V4, pumpOn ? 1 : 0);
  Blynk.virtualWrite(V5, lightOn ? 1 : 0);
}

BLYNK_WRITE(V6) {
  pumpOn = param.asInt();
  digitalWrite(PUMP_PIN, pumpOn ? HIGH : LOW);
}

BLYNK_WRITE(V7) {
  lightOn = param.asInt();
  digitalWrite(LIGHT_PIN, lightOn ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(LIGHT_PIN, LOW);
  dht.begin();

  Serial.println("HYDROSENSE Wokwi simulation starting...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
