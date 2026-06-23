#include <iostream>
#include <string>

using namespace std;

// Struktur Data Utama
struct Buku {
    string idBuku;
    string judul;
    string pengarang;
    bool tersedia;
};

// Global Variable Koleksi Data
const int MAX_BUKU = 100;
Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;

string riwayatPeminjaman[MAX_BUKU];
int jumlahRiwayat = 0;


// --- TUGAS ANGGOTA 3: Data Awal, Tampil, & Cari ---
void loadDatabaseBuku() {
    // Tulis data awal bawaan di sini
    cout << "\n-----Fitur Database Buku-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void tampilBuku() {
    // Tulis logika menampilkan buku dan statistik di sini
    cout << "\n-----Fitur Tampil Buku-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void cariBuku() {
    // Tulis logika pencarian buku berdasarkan Judul atau ID di sini
    cout << "\n-----Fitur Cari Buku-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}


// --- TUGAS ANGGOTA 2: Tambah & Hapus ---
void tambahBuku() {
    // Tulis logika tambah data buku (termasuk validasi ID unik) di sini
    cout << "\n-----Fitur Tambah Buku-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void hapusBuku() {
    // Tulis logika hapus data buku berdasarkan ID di sini
    cout << "\n-----Fitur Hapus Buku-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}


// --- TUGAS ANGGOTA 4: Pinjam, Kembali, & Sorting ---
void pinjamBuku() {
    // Tulis logika pinjam buku dan pencatatan riwayat di sini
    cout << "\n-----Fitur Pinjam Buku-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void kembalikanBuku() {
    // Tulis logika kembalikan buku dan pencatatan riwayat di sini
    cout << "\n-----Fitur Kembalikan Buku-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void sortingBuku() {
    // Tulis logika urutkan buku berdasarkan judul (A-Z) di sini
    cout << "\n-----Fitur Sorting Buku-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}


// --- TUGAS ANGGOTA 5: Rekomendasi, Riwayat, & Hapus Riwayat ---
void rekomendasiBuku() {
    // Tulis logika rekomendasi buku di sini
    cout << "\n-----Fitur Rekomendasi Buku-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void riwayatBuku() {
    // Tulis logika menampilkan riwayat transaksi di sini
    cout << "\n-----Fitur Tampil Riwayat-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}

void hapusRiwayat() {
    // Tulis logika untuk mengosongkan riwayat transaksi di sini
    cout << "\n-----Fitur Hapus Semua Riwayat-----" << endl;
    cout << "Fitur ini masih dalam pengembangan...\n";
}


// --- MENU UTAMA ---
int main() {
    loadDatabaseBuku(); 
    int pilihan;
    
    do {
        cout << "\n========================================\n";
        cout << "      SISTEM MANAJEMEN PERPUSTAKAAN     \n";
        cout << "========================================\n";
        cout << " [1] Tampilkan Semua Buku & Statistik\n";
        cout << " [2] Cari Buku\n";
        cout << " [3] Tambah Buku Baru\n";
        cout << " [4] Hapus Buku\n";
        cout << " [5] Pinjam Buku\n";
        cout << " [6] Kembalikan Buku\n";
        cout << " [7] Urutkan Buku (A-Z)\n";
        cout << " [8] Rekomendasi \n";
        cout << " [9] Lihat Riwayat\n";
        cout << " [10] Hapus Semua Riwayat\n";
        cout << " [11] Keluar Sistem\n";
        cout << "========================================\n";
        cout << " Pilih menu (1-11): "; cin >> pilihan;
        
        // Membersihkan buffer input agar getline() di dalam fungsi tidak terlewat
        cin.ignore();
        
        switch (pilihan) {
            case 1: 
                tampilBuku(); 
                break;
            case 2:
                cariBuku(); 
                break;
            case 3: 
                tambahBuku(); 
                break;
            case 4: 
                hapusBuku(); 
                break;
            case 5: 
                pinjamBuku(); 
                break;
            case 6: 
                kembalikanBuku(); 
                break;
            case 7:
                sortingBuku(); 
                break;
            case 8: 
                rekomendasiBuku(); 
                break;
            case 9: 
                riwayatBuku(); 
                break;
            case 10: 
                hapusRiwayat(); 
                break; 
            case 11:
                cout << "\n>> Keluar dari sistem. Terima kasih!\n";
                break;
            default:
                cout << "\n[Peringatan] Pilihan tidak valid! Masukkan angka 1-11.\n";
                break;
        }
    } while (pilihan != 11);
    
    return 0;
}
