#include <iostream>
#include <string>

using namespace std;

// Struktur Data Utama
struct NodeBuku {
    string idBuku;
    string judul;
    string pengarang;
    bool tersedia;
};

// Global Variable Koleksi Data
const int MAX_BUKU = 100;
NodeBuku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;

string riwayatPeminjaman[MAX_BUKU];
int jumlahRiwayat = 0;


// Mengubah angka menjadi string
string angkaKeStringManual(int angka) {
    if (angka == 0) return "0";
    string hasil = "";
    while (angka > 0) {
        char digit = (angka % 10) + '0';
        hasil = digit + hasil;
        angka /= 10;
    }
    return hasil;
}

// mengubah huruf kecil jadi bisa di baca 
string toLowerManual(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32; 
        }
    }
    return s;
}


// --- TUGAS 1 Modul Data Awal & Informasi Buku (Oleh: Nazwa Alia) ---
void loadDatabaseBuku() {
    // Tulis logika load data buku awal di sini
    cout << "\n----- Fitur Load Database Buku -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void tampilBuku() {
    // Tulis logika menampilkan semua buku dan statistik di sini
    cout << "\n----- Fitur Tampilkan Buku & Statistik -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void cariBuku() {
    // Tulis logika pencarian pintar di sini
    cout << "\n----- Fitur Cari Buku -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}


// --- TUGAS 2 Modul Manajemen Koleksi Buku (Oleh: Sri Agnia) ---
void tambahBuku() {
    // Tulis logika tambah buku baru di sini
    cout << "\n----- Fitur Tambah Buku Baru -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void hapusBuku() {
    // Tulis logika hapus data buku di sini
    cout << "\n----- Fitur Hapus Buku Lama -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void editBuku() {
    // Tulis logika edit informasi buku di sini
    cout << "\n----- Fitur Edit Informasi Buku -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}


// --- TUGAS 3 Modul Sirkulasi & Algoritma Pengurutan (Oleh: Devina Putri) ---
void pinjamBuku() {
    // Tulis logika transaksi peminjaman buku di sini
    cout << "\n----- Fitur Pinjam Buku -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void kembalikanBuku() {
    // Tulis logika transaksi pengembalian buku dan cek denda di sini
    cout << "\n----- Fitur Kembalikan Buku (Cek Denda) -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void sortingBuku() {
    // Tulis logika pengurutan buku (A-Z) berdasarkan judul di sini
    cout << "\n----- Fitur Urutkan Semua Daftar Buku (A-Z) -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}


// --- TUGAS 4 Modul Laporan & Rekomendasi Sistem (Oleh: Rezki) ---
void rekomendasiBuku() {
    // Tulis logika menampilkan rekomendasi buku di sini
    cout << "\n----- Fitur Lihat Rekomendasi Buku Minggu Ini -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void riwayatBuku() {
    // Tulis logika menampilkan semua riwayat transaksi di sini
    cout << "\n----- Fitur Lihat Semua Riwayat Transaksi -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void hapusRiwayat() {
    // Tulis logika menghapus semua catatan riwayat di sini
    cout << "\n----- Fitur Hapus Semua Catatan Riwayat -----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}


// --- MENU UTAMA ---
// --- Tugas 5 Arsitektur Menu Utama (UI), Sistem Logika Inti, dan Integrasi Kode (Oleh: Aditya Maulana F) ---
int main() {
    loadDatabaseBuku();
    int pilihanUtama, pilihanSub;
    
    do {
        cout << "\n========================================\n";
        cout << "      SISTEM MANAJEMEN PERPUSTAKAAN      \n";
        cout << "========================================\n";
        cout << " [1] Menu Manajemen Data & Koleksi Buku\n";
        cout << " [2] Menu Transaksi Peminjaman\n";
        cout << " [3] Menu Laporan Riwayat Transaksi\n";
        cout << " [4] Keluar Sistem\n";
        cout << "========================================\n";
        cout << " Pilih menu utama (1-4): "; 
        cin >> pilihanUtama;
        cin.ignore();
        
        switch (pilihanUtama) {
            case 1: 
                do {
                    cout << "\n--- SUB-MENU: MANAJEMEN DATA & KOLEKSI ---\n";
                    cout << " [1] Tampilkan Semua Buku & Statistik\n";
                    cout << " [2] Cari Buku (Pencarian Pintar)\n";
                    cout << " [3] Urutkan Semua Daftar Buku (A-Z)\n";
                    cout << " [4] Lihat Rekomendasi Buku Minggu Ini\n"; 
                    cout << " [5] Tambah Buku Baru\n";
                    cout << " [6] Hapus Buku Lama\n";
                    cout << " [7] Edit Informasi Buku\n";
                    cout << " [8] Kembali ke Menu Utama\n";
                    cout << " Pilih tindakan (1-8): "; cin >> pilihanSub; cin.ignore();
                    switch(pilihanSub) {
                        case 1: tampilBuku(); break;
                        case 2: cariBuku(); break;
                        case 3: sortingBuku(); break;
                        case 4: rekomendasiBuku(); break;
                        case 5: tambahBuku(); break;
                        case 6: hapusBuku(); break;
                        case 7: editBuku(); break;
                    }
                } while (pilihanSub != 8);
                break;
                
            case 2: 
                do {
                    cout << "\n--- SUB-MENU: TRANSAKSI PEMINJAMAN ---\n";
                    cout << " [1] Pinjam Buku\n";
                    cout << " [2] Kembalikan Buku (Cek Denda)\n";
                    cout << " [3] Kembali ke Menu Utama\n";
                    cout << " Pilih tindakan (1-3): "; cin >> pilihanSub; cin.ignore();
                    switch(pilihanSub) {
                        case 1: pinjamBuku(); break;
                        case 2: kembalikanBuku(); break;
                    }
                } while (pilihanSub != 3);
                break;
                
            case 3: 
                do {
                    cout << "\n--- SUB-MENU: LAPORAN RIWAYAT ---\n";
                    cout << " [1] Lihat Semua Riwayat Transaksi\n";
                    cout << " [2] Hapus Semua Catatan Riwayat\n";
                    cout << " [3] Kembali ke Menu Utama\n";
                    cout << " Pilih tindakan (1-3): "; cin >> pilihanSub; cin.ignore();
                    switch(pilihanSub) {
                        case 1: riwayatBuku(); break;
                        case 2: hapusRiwayat(); break;
                    }
                } while (pilihanSub != 3);
                break;
                
            case 4:
                cout << "\n>> Keluar dari sistem. Terima kasih!\n";
                break;
                
            default:
                cout << "\n[Peringatan] Pilihan tidak valid! Masukkan angka 1-4.\n";
                break;
        }
    } while (pilihanUtama != 4);
    
    return 0;
}
