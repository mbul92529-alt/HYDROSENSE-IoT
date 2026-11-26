# Rencana Pengujian HYDROSENSE

| ID | Pengujian | Prosedur | Kriteria lulus |
|---|---|---|---|
| T01 | Boot ESP32 | Nyalakan board tanpa aktuator | Board boot tanpa restart berulang |
| T02 | Wi-Fi | Gunakan SSID uji | Terhubung dan pulih setelah koneksi terputus |
| T03 | Sensor pH | Bandingkan buffer pH standar | Error sesuai target kalibrasi proyek |
| T04 | Sensor TDS | Bandingkan larutan standar | Hasil sesuai toleransi sensor |
| T05 | Suhu | Bandingkan termometer referensi | Selisih sesuai spesifikasi |
| T06 | Level air | Ubah kondisi sensor | Status terbaca benar |
| T07 | Proteksi pompa | Simulasikan level rendah | Pompa dipaksa OFF |
| T08 | Dashboard | Amati datastream | Nilai dan status tampil benar |
| T09 | Kontrol manual | Kirim perintah switch | Aktuator merespons sesuai logika |
| T10 | Mode otomatis | Uji kondisi batas | Aturan dan fail-safe bekerja |

## Bukti pengujian
Catat tanggal, versi firmware, board, tipe sensor, alat referensi, nilai aktual, hasil, dan foto. Jangan menyatakan sistem tervalidasi sebelum data pengujian nyata tersedia.

## Kriteria penerimaan
Semua pengujian keselamatan wajib lulus. Pengujian akurasi harus memiliki hasil kalibrasi dan toleransi terukur. Ulangi tes setelah perubahan wiring atau firmware.
