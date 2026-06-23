# 📚 Sistem Manajemen Perpustakaan Modern (SMPM) - Kelompok 4

> **Proyek UAS Praktikum Algoritma dan Struktur Data**
> Sebuah sistem otomasi tata kelola data literatur terintegrasi berbasis *desktop console* (C++) yang menerapkan arsitektur data linear *Array of Struct* yang dikombinasikan dengan algoritma sorting sekuensial dan manajemen riwayat berbasis *buffer array* statis untuk efisiensi pelacakan sirkulasi buku.

---

## 📂 Struktur Folder Proyek
* `src/` : Berisi file source code utama (`main.cpp`).
* `docs/` : Berisi dokumen laporan tugas akhir kelompok.

---

## 👥 Tim Pengembang & Kontribusi Kode (Contributors)

Proyek ini dikembangkan secara kolaboratif menggunakan Git Branching Workflow dengan membagi program ke dalam modul independen yang diintegrasikan oleh Lead Developer melalui sinkronisasi data global:

### 01. [Nama Ketua Kelompok] — Lead Developer & Git Administrator
* **NIM:** [Masukkan NIM]
* **Modul:** `Core Architecture & Git Integration`
* **Tanggung Jawab:** Setup repositori utama, penanganan aturan *branching*, integrasi akhir seluruh modul anggota, validasi stabilitas *runtime*, serta koordinasi penyusunan kode agar terbebas dari *merge conflict*.

### 02. [Nama Anggota 2] — Software Engineer (Data Modification Specialist)
* **NIM:** [Masukkan NIM]
* **Modul:** `Data Insertion & Deletion`
* **Tanggung Jawab:** Mengimplementasikan fungsi `tambahBuku()` dengan validasi keamanan ID unik (mencegah *duplicate primary key*), serta menyusun logika pergeseran indeks (*index shifting traversal*) pada fungsi `hapusBuku()` untuk menjaga kontinuitas memori *array*.

### 03. [Nama Anggota 3] — Software Engineer (Database & Lookup Specialist)
* **NIM:** [Masukkan NIM]
* **Modul:** `Database Initialization & Search Engine`
* **Tanggung Jawab:** Mengelola fungsi pencatatan koleksi awal via `loadDatabaseBuku()`, menyusun fungsi `tampilBuku()` yang dilengkapi kalkulasi statistik ketersediaan buku secara *real-time*, serta membangun mesin pencari berbasis linear pada fungsi `cariBuku()`.

### 04. [Nama Anggota 4] — Software Engineer (Circulation & Sorting Specialist)
* **NIM:** [Masukkan NIM]
* **Modul:** `Circulation System & Sorting Algorithm`
* **Tanggung Jawab:** Merancang fungsi sirkulasi `pinjamBuku()` dan `kembalikanBuku()` yang terikat dengan perubahan status boolean koleksi, serta menerapkan algoritma **Bubble Sort** pada `sortingBuku()` untuk penataan urutan alfabetis judul (A-Z) dengan kompleksitas waktu $O(n^2)$.

### 05. [Nama Anggota 5] — Software Engineer & Technical Writer
* **NIM:** [Masukkan NIM]
* **Modul:** `Recommendation, Transaction Logs, & Documentation`
* **Tanggung Jawab:** Menyusun fungsi penarik rekomendasi buku terpopuler `rekomendasiBuku()`, mengelola *buffer array* untuk pelacakan aktivitas lewat `riwayatBuku()`, fitur pembersihan memori transaksi `hapusRiwayat()`, serta bertanggung jawab atas dokumentasi laporan teknis UAS.

---

## 🚀 Fitur Utama & Representasi Struktur Data

| No | Fitur Aplikasi | Struktur Data Terpilih | Algoritma / Prinsip Kerja | Keunggulan & Alasan Pemilihan Teknik |
| :--- | :--- | :--- | :--- | :--- |
| **1** | **Database Koleksi** | **Array of Struct (`Buku`)** | *Direct Indexing Access* | Memetakan entitas data majemuk (ID, Judul, Pengarang, Status) dalam satu larik memori bertetangga, mempermudah akses indeks secara instan. |
| **2** | **Sirkulasi Buku** | **Boolean State Tracking** | *State Flag Switching* | Mengubah status internal `.tersedia` (`true`/`false`) secara cepat saat terjadi transaksi peminjaman tanpa merusak data fundamental buku. |
| **3** | **Pengurutan Judul** | **Array** | **Bubble Sort (A-Z)** | Mengurutkan tumpukan buku berdasarkan alfabet judul. Sangat stabil untuk kapasitas koleksi skala menengah ($MAX\_BUKU = 100$). |
| **4** | **Log Transaksi** | **Linear Array Buffer** | *Sequential Logging* | Mencatat alur masuk-keluar buku secara kronologis ke dalam array `riwayatPeminjaman` untuk transparansi audit perpustakaan. |

---

## 🔗 Sinkronisasi & Inter-Module Integration (Kelebihan Sistem)

Aplikasi ini menerapkan interaksi hulu-ke-hilir antar fungsi yang dinamis, memastikan setiap modul bekerja sebagai satu kesatuan ekosistem:

1. **Sirkulasi ➡️ Riwayat Transaksi (`pinjamBuku()` / `kembalikanBuku()` ➡️ `riwayatPeminjaman`):** Setiap kali sirkulasi berhasil dilakukan oleh modul Anggota 4, sistem akan langsung mengirimkan *string log* terformat ke dalam array riwayat milik Anggota 5 dan menaikkan pointer `jumlahRiwayat`.
2. **Sorting ➡️ Refreshed UI (`sortingBuku()` ➡️ `tampilBuku()`):** Setelah algoritma Bubble Sort milik Anggota 4 selesai merestrukturisasi urutan memori array, fungsi tersebut secara otomatis memanggil fungsi `tampilBuku()` milik Anggota 3 untuk langsung menyajikan visualisasi data terurut kepada pengguna tanpa intervensi manual.
3. **Input Stream Safety (`main()` ➡️ `getline()`):** Penempatan pembersihan buffer `cin.ignore()` oleh Anggota 2 di jantung menu `main()` menjamin bahwa fungsi pencarian input kalimat (`getline`) pada modul Anggota 2, 3, dan 4 tidak akan terlewati (*skipping bug*) akibat sisa karakter *newline* (`\n`).

---

## 🗺️ Alur & Arsitektur Menu Utama Aplikasi

Eksekusi program terpusat pada perulangan `do-while` di fungsi `main()` dengan peta fungsionalitas menu sebagai berikut:

* **[1] Tampilkan Semua Buku & Statistik:** Menyajikan tabel seluruh buku aktif beserta total buku yang tersedia dan sedang dipinjam secara *real-time*.
* **[2] Cari Buku:** Membuka pencarian buku secara linear berbasis ID unik ataupun kesamaan judul buku.
* **[3] Tambah Buku Baru:** Gerbang input data buku baru yang dilengkapi validasi pencegahan duplikasi ID (*primary key*).
* **[4] Hapus Buku:** Mengeliminasi buku dari database menggunakan metode pergeseran indeks ke kiri (*index shifting*).
* **[5] Pinjam Buku:** Mengubah status buku menjadi tidak tersedia dan otomatis mendaftarkannya ke log riwayat transaksi.
* **[6] Kembalikan Buku:** Mengembalikan status buku menjadi tersedia kembali di perpustakaan.
* **[7] Urutkan Buku (A-Z):** Menyortir seluruh buku berdasarkan alfabetis judul menggunakan algoritma Bubble Sort.
* **[8] Rekomendasi:** Menampilkan buku rekomendasi terpopuler yang tersedia di dalam sistem perpustakaan.
* **[9] Lihat Riwayat:** Menampilkan seluruh urutan kronologis aktivitas peminjaman dan pengembalian buku.
* **[10] Hapus Semua Riwayat:** Melakukan *reset* instan atau pengosongan total pada *buffer array* log transaksi.
* **[11] Keluar Sistem:** Menghentikan perulangan aplikasi secara aman.

---
