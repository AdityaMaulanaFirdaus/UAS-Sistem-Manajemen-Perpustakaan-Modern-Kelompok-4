# 📚 Sistem Manajemen Perpustakaan Modern (SMPM) - Kelompok 4

> **Proyek UAS Praktikum Algoritma dan Struktur Data**
> Sebuah sistem otomasi tata kelola data literatur terintegrasi berbasis *desktop console* (C++) yang menerapkan arsitektur data linear *Array of Struct* yang dikombinasikan dengan algoritma sorting sekuensial, sistem *case-insensitive*, manajemen denda, dan pelacakan riwayat berbasis *buffer array* statis untuk efisiensi pelacakan sirkulasi buku.

---

## 📂 Struktur Folder Proyek
* `src/` : Berisi file source code utama (`Main.cpp`).
* `docs/` : Berisi dokumen laporan tugas akhir kelompok.

---

## 👥 Tim Pengembang & Kontribusi Kode (Contributors)

Proyek ini dikembangkan secara kolaboratif menggunakan Git Branching Workflow dengan membagi program ke dalam modul independen berbentuk sub-menu, yang diintegrasikan oleh Lead Developer melalui sinkronisasi data global:

### 01. [Aditya Maulana Firdaus] — Lead Developer & UI Architect
* **NIM:** [2503010003]
* **Modul:** `UI Menu Architecture, Core Logic, & System Integration`
* **Tanggung Jawab:** Merancang arsitektur menu utama bertingkat (*Sub-Menu System*), membangun fondasi *Array of Struct* (`Buku`), membuat fungsi helper teks & konversi matematika (`toLowerManual` dan `angkaKeStringManual`) untuk mencegah *runtime error* pada compiler, serta mengintegrasikan seluruh fungsi anggota kelompok tanpa adanya *merge conflict*.

### 02. [Nazwa Allia Kusmana] — Software Engineer (Data Initialization & Information Specialist)
* **NIM:** [2503010036]
* **Modul:** `Database Initialization, Lookups, & Visualizations`
* **Tanggung Jawab:** Mengelola fungsi pencatatan koleksi data bawaan via `loadDatabaseBuku()`, menyusun fungsi `tampilBuku()` yang dilengkapi kalkulasi statistik ketersediaan buku secara *real-time*, serta membangun mesin pencarian berbasis pencocokan parsial teks (*string find traversal*) pada fungsi `cariBuku()`.

### 03. [Sri Agnia] — Software Engineer (Data Modification Specialist)
* **NIM:** [2503010040]
* **Modul:** `Data Insertion, Deletion, & Modification (CRUD)`
* **Tanggung Jawab:** Mengimplementasikan fungsi `tambahBuku()` dengan validasi keamanan ID unik (mencegah *duplicate primary key*), menyusun logika pergeseran indeks (*index shifting traversal*) pada fungsi `hapusBuku()`, serta merancang fungsi `editBuku()` untuk memperbarui judul dan pengarang secara dinamis.

### 04. [Devina Putri Nur Aliah] — Software Engineer (Circulation & Sorting Specialist)
* **NIM:** [2503010045]
* **Modul:** `Circulation System, Fine Management, & Sorting Algorithm`
* **Tanggung Jawab:** Merancang fungsi sirkulasi `pinjamBuku()` dan `kembalikanBuku()` yang terikat dengan perubahan status boolean koleksi, mengimplementasikan algoritma hitung denda keterlambatan otomatis sebesar **Rp20.000,-/hari**, serta menerapkan algoritma **Bubble Sort** pada `sortingBuku()` untuk penataan alfabetis judul (A-Z) dengan kompleksitas waktu $O(n^2)$.

### 05. [Rezki Ahmad Fauzi] — Software Engineer & Technical Writer
* **NIM:** [2503010018]
* **Modul:** `Recommendation Systems, Transaction Logs, & Documentation`
* **Tanggung Jawab:** Menyusun fungsi penarik rekomendasi buku terpopuler `rekomendasiBuku()`, mengelola *buffer array* untuk pelacakan aktivitas peminjaman lewat `riwayatBuku()`, membangun fitur pembersihan memori transaksi `hapusRiwayat()`, serta bertanggung jawab penuh atas dokumentasi laporan teknis UAS.

---

## 🚀 Fitur Utama & Representasi Struktur Data

| No | Fitur Aplikasi | Struktur Data Terpilih | Algoritma / Prinsip Kerja | Keunggulan & Alasan Pemilihan Teknik |
| :--- | :--- | :--- | :--- | :--- |
| **1** | **Database Koleksi** | **Array of Struct (`Buku`)** | *Direct Indexing Access* | Memetakan entitas data majemuk (ID, Judul, Pengarang, Status) dalam satu larik memori bertetangga, mempermudah akses indeks secara instan. |
| **2** | **Sirkulasi Buku** | **Boolean State Tracking** | *State Flag Switching* | Mengubah status internal `.tersedia` (`true`/`false`) secara cepat saat terjadi transaksi peminjaman tanpa merusak data fundamental buku. |
| **3** | **Pengurutan Judul** | **Array** | **Bubble Sort (A-Z)** | Mengurutkan tumpukan buku berdasarkan alfabet judul. Sangat stabil untuk kapasitas koleksi skala menengah ($MAX\_BUKU = 100$). |
| **4** | **Log Transaksi** | **Linear Array Buffer** | *Sequential Logging* | Mencatat alur masuk-keluar buku secara kronologis ke dalam array `riwayatPeminjaman` untuk transparansi audit perpustakaan. |
| **5** | **Manajemen Denda** | **Primitive Data Logic** | *Conditional Calculation* | Melakukan evaluasi kondisi penalti `if (lamaPinjam > 7)` untuk menghitung denda Rp20.000,- per hari secara matematis. |
| **6** | **Case-Insensitive** | **String Char Manipulation** | *ASCII Upper-to-Lower Traversal* | Mentransformasikan setiap karakter string kapital ke huruf kecil via ASCII (+32) untuk menjamin akurasi pencarian dan transaksi tanpa sensitivitas *case*. |

---

## 🔗 Sinkronisasi & Inter-Module Integration (Kelebihan Sistem)

Aplikasi ini menerapkan interaksi hulu-ke-hilir antar fungsi yang dinamis, memastikan setiap modul bekerja sebagai satu kesatuan ekosistem:

1. **Sirkulasi ➡️ Laporan Finansial & Riwayat (`kembalikanBuku()` ➡️ `riwayatPeminjaman`):** Setiap kali sirkulasi pengembalian mendeteksi keterlambatan oleh modul Anggota 4, sistem mengonversi data nominal denda secara manual dan mengirimkan log kronologis terformat ke dalam modul Anggota 5.
2. **Sorting ➡️ Refreshed UI (`sortingBuku()` ➡️ `tampilBuku()`):** Setelah algoritma Bubble Sort milik Anggota 4 selesai merestrukturisasi urutan memori array, fungsi tersebut secara otomatis memanggil fungsi `tampilBuku()` milik Anggota 2 untuk langsung menyajikan visualisasi data terurut kepada pengguna.
3. **Input Stream Safety (`main()` ➡️ `getline()`):** Penempatan pembersihan buffer `cin.ignore()` oleh Ketua Kelompok di jantung kendali menu `main()` menjamin bahwa fungsi pencarian input kalimat (`getline`) pada modul Anggota 2, 3, dan 4 tidak akan mengalami *skipping bug*.

---

## 🗺️ Alur & Arsitektur Menu Utama Aplikasi

Eksekusi program terpusat pada perulangan `do-while` di fungsi `main()` dengan pembagian sub-menu fungsional (Modul Terintegrasi) sebagai berikut:

* **[1] Menu Manajemen Data & Koleksi Buku (Tugas Anggota 2, 3 & 4)**
  * *Tampilkan Semua Buku & Statistik:* Menyajikan tabel buku aktif beserta kalkulasi ketersediaan buku secara *real-time*.
  * *Cari Buku:* Membuka pencarian buku secara linear berbasis kesamaan judul atau ID secara *case-insensitive*.
  * *Urutkan Semua Daftar Buku (A-Z):* Menyortir urutan memori buku alfabetis menggunakan algoritma Bubble Sort.
  * *Lihat Rekomendasi Buku Minggu Ini:* Menampilkan rekomendasi buku terpopuler dalam sistem.
  * *Tambah Buku Baru:* Melakukan *insert* entitas buku baru ke dalam array dengan proteksi duplikasi *primary key*.
  * *Hapus Buku Lama:* Mengeliminasi data buku menggunakan skema *index shifting traversal*.
  * *Edit Informasi Buku:* Memperbarui data judul dan pengarang dari ID buku tertentu.
* **[2] Menu Transaksi Peminjaman (Tugas Anggota 4)**
  * *Pinjam Buku:* Memvalidasi ID buku dan mengubah bendera status ketersediaan menjadi *false*.
  * *Kembalikan Buku (Cek Denda):* Mengembalikan status buku menjadi *true* serta menghitung pinalti keterlambatan (Rp20.000,-/hari jika pinjam > 7 hari).
* **[3] Menu Laporan Riwayat Transaksi (Tugas Anggota 5)**
  * *Lihat Semua Riwayat Transaksi:* Membuka isi *buffer array* catatan log masuk-keluar buku secara kronologis.
  * *Hapus Semua Catatan Riwayat:* Melakukan *reset clearance* pointer jumlah riwayat transaksi kembali ke angka nol.
* **[4] Keluar Sistem:** Menutup alur perulangan program secara aman.
