# HYDROSENSE-IoT 🌱

**Sistem pemantauan dan kendali hidroponik berbasis ESP32 dan IoT.**

Repository ini menyediakan dokumentasi rancangan, firmware starter ESP32, dan simulator dashboard berbasis browser.

> **Status:** prototipe akademik/starter kit. Data pada simulator bersifat sintetis. Konversi sensor pada firmware belum dikalibrasi dan pin merupakan contoh. Sesuaikan dengan komponen serta wiring fisik sebelum digunakan.

## Fitur rancangan
- Pemantauan pH, TDS, suhu air, dan level air.
- Koneksi Wi-Fi dan dashboard Blynk IoT.
- Kontrol pompa/lampu melalui relay.
- Mode manual dan contoh aturan otomatis.
- Simulator browser tanpa instalasi.

## Struktur
```
firmware/HYDROSENSE_ESP32.ino
simulator/index.html
docs/ARCHITECTURE.md
docs/COMPONENTS_AND_WIRING.md
docs/BLYNK_SETUP.md
docs/TEST_PLAN.md
README.md
```

## Coba simulator
Buka [simulator/index.html](simulator/index.html) atau unduh file tersebut lalu buka di browser. Tampilan simulator tidak terhubung ke hardware.

## Firmware ESP32
1. Instal Arduino IDE dan board package ESP32.
2. Pasang library Blynk jika memakai dashboard Blynk.
3. Buka `firmware/HYDROSENSE_ESP32.ino`.
4. Isi kredensial Wi-Fi dan Blynk secara lokal.
5. Verifikasi pin, jenis sensor, tegangan, dan logika relay.
6. Kalibrasi sensor sebelum menggunakan hasil pembacaan.

## Datastream Blynk
| Virtual pin | Fungsi |
|---|---|
| V0 | pH |
| V1 | TDS (ppm) |
| V2 | Suhu air (perlu implementasi sensor suhu aktual) |
| V3 | Level air |
| V4 | Status/kontrol pompa |
| V5 | Status/kontrol lampu |
| V6 | Mode otomatis |

Lihat [panduan Blynk](docs/BLYNK_SETUP.md), [arsitektur](docs/ARCHITECTURE.md), [komponen dan wiring](docs/COMPONENTS_AND_WIRING.md), serta [rencana pengujian](docs/TEST_PLAN.md).

## Keselamatan dan batasan
- Jangan hubungkan pompa atau beban AC langsung ke GPIO. Gunakan driver/relay dengan rating, isolasi, proteksi, dan enclosure yang sesuai.
- ESP32 menggunakan logika 3,3 V. Pastikan tegangan keluaran sensor aman untuk ADC.
- Kalibrasi sensor pH/TDS dengan larutan standar. Rumus contoh bukan pengganti kalibrasi.
- Uji fail-safe level air dan kondisi sensor gagal sebelum mode otomatis.
- Jangan commit password Wi-Fi atau Blynk Auth Token. Gunakan placeholder dan secrets lokal.

## Lisensi
Belum ditentukan. Hubungi pemilik repository sebelum penggunaan ulang di luar pembelajaran.

**Dokumentasi:** [GitHub HYDROSENSE-IoT](https://github.com/mbul92529-alt/HYDROSENSE-IoT)
