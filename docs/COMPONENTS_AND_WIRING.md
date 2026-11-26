# Komponen dan Panduan Wiring

## Komponen yang direncanakan
| Komponen | Fungsi | Catatan |
|---|---|---|
| ESP32 DevKit | Pengendali dan konektivitas Wi-Fi | Pastikan varian board diketahui |
| Sensor pH + modul interface | Mengukur keasaman | Kalibrasi buffer pH 4/7/10 |
| Sensor TDS/EC | Mengukur konsentrasi terlarut | Kalibrasi larutan standar |
| Sensor suhu air | Mengukur suhu larutan | Firmware contoh menyisakan pin data |
| Sensor level air | Proteksi level minimum | Tentukan tipe NO/NC dan logika |
| Relay/driver | Mengendalikan beban | Sesuaikan tegangan dan arus |
| Pompa dan lampu | Aktuator hidroponik | Verifikasi spesifikasi beban |
| Catu daya | Menyuplai sistem | Pisahkan suplai logika dan beban bila diperlukan |

## Pemetaan pin contoh firmware
| Sinyal | GPIO contoh |
|---|---:|
| Analog pH | 34 |
| Analog TDS | 35 |
| Data suhu air | 4 |
| Level air | 27 |
| Relay pompa | 26 |
| Relay lampu | 25 |

**Penting:** ini bukan pinout final perangkat Anda. Cocokkan dengan board dan modul yang benar-benar digunakan. GPIO34/35 hanya input pada ESP32 klasik; rentang ADC dan attenuasi perlu dikonfigurasi sesuai board.

## Keselamatan listrik
- Jangan memasok motor/pompa dari pin GPIO.
- Gunakan driver transistor/MOSFET atau relay yang sesuai rating beban.
- Untuk beban AC, gunakan modul tertutup dan isolasi yang layak; pemasangan harus dilakukan teknisi kompeten.
- Pastikan ground dan referensi sinyal dirancang benar.
- Uji sistem tanpa beban, lalu dengan beban tegangan rendah yang aman sebelum instalasi akhir.

## Data yang harus dilengkapi dari prototipe
Model board, tipe sensor dan modul, tegangan kerja, pin final, tipe relay, spesifikasi pompa/lampu, serta foto wiring.
