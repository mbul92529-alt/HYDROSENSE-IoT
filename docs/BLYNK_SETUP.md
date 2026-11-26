# Integrasi Blynk IoT

1. Buat template perangkat pada Blynk Console.
2. Tambahkan datastream bertipe Virtual Pin sesuai tabel berikut.
3. Buat device dari template dan salin Template ID, Template Name, serta Auth Token.
4. Masukkan nilai tersebut ke firmware lokal. Jangan commit token, SSID, atau password Wi-Fi ke repository publik.
5. Tambahkan widget gauge untuk V0–V2, indikator untuk V3, switch untuk V4–V5, dan switch mode untuk V6.
6. Unggah firmware ke ESP32 dan pastikan serial monitor menunjukkan koneksi berhasil.

| Virtual pin | Tipe | Kegunaan |
|---|---|---|
| V0 | Double | pH |
| V1 | Double | TDS ppm |
| V2 | Double | Suhu air — tambahkan implementasi sensor suhu sesuai modul |
| V3 | Integer | Level air |
| V4 | Integer | Kontrol/status pompa |
| V5 | Integer | Kontrol/status lampu |
| V6 | Integer | Mode otomatis |

## Keamanan
Gunakan placeholder pada file publik. Jika token pernah terunggah, reset token di console. Untuk penggunaan nyata, gunakan kredensial dari secrets lokal dan jangan membagikannya melalui screenshot atau laporan publik.

## Rujukan
- Dokumentasi Blynk: https://docs.blynk.io/
- Blynk library untuk Arduino: https://github.com/blynkkk/blynk-library
