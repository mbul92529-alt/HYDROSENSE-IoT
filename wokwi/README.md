# HYDROSENSE — Simulasi Wokwi + Blynk

Folder ini berisi rangkaian virtual ESP32 untuk mencoba alur pemantauan hidroponik tanpa perangkat fisik.

## Komponen virtual
- ESP32 DevKit V1
- DHT22 untuk suhu dan kelembapan udara
- Dua potentiometer sebagai sensor pH dan TDS tiruan
- HC-SR04 sebagai simulasi pengukuran ketinggian air
- LED biru dan kuning sebagai indikator pompa dan lampu

## Menjalankan simulasi
1. Buka https://wokwi.com/.
2. Pilih **New Project → ESP32**.
3. Salin isi `sketch.ino`, `diagram.json`, dan `libraries.txt` dari folder ini ke proyek Wokwi.
4. Buat Template dan Device di https://blynk.cloud/.
5. Buat datastream virtual:
   - V0: pH (Double)
   - V1: TDS ppm (Double)
   - V2: Suhu air/lingkungan °C (Double; pada contoh ini DHT22 mengukur suhu udara)
   - V3: Level air % (Double)
   - V4: Status pompa (Integer)
   - V5: Status lampu (Integer)
   - V6: Tombol pompa (Integer, 0–1)
   - V7: Tombol lampu (Integer, 0–1)
6. Ganti `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, dan `BLYNK_AUTH_TOKEN` di sketch dengan nilai dari template/device Blynk.
7. Jalankan simulasi. Putar potentiometer untuk mengubah nilai pH/TDS, ubah jarak HC-SR04 untuk level air, dan gunakan tombol di dashboard Blynk untuk mengendalikan LED.

## Batasan penting
- pH dan TDS berasal dari pemetaan posisi potentiometer, bukan model kimia sensor sebenarnya.
- DHT22 mengukur suhu/kelembapan udara, bukan suhu larutan nutrisi.
- HC-SR04 hanya mencontohkan jarak ke permukaan air; sesuaikan asumsi tinggi wadah 30 cm di kode.
- LED hanya mewakili status pompa/lampu. Simulasi tidak menggerakkan pompa fisik.
- Ini adalah demonstrasi edukasi, bukan alat ukur terkalibrasi atau sistem kendali siap produksi.
- Jangan pernah mengunggah token Blynk atau kredensial Wi-Fi pribadi ke repository publik.
