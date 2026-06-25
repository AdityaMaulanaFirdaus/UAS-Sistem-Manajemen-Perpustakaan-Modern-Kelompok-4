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
    void loadDatabaseBuku() {
    daftarBuku[0].idBuku = "B01"; daftarBuku[0].judul = "Struktur Data C++";   daftarBuku[0].pengarang = "sasa";   daftarBuku[0].tersedia = true;
    daftarBuku[1].idBuku = "B02"; daftarBuku[1].judul = "Dasar Pemrograman";   daftarBuku[1].pengarang = "martin "; daftarBuku[1].tersedia = true;
    daftarBuku[2].idBuku = "B03"; daftarBuku[2].judul = "Logika Informatika";  daftarBuku[2].pengarang = "chou ";  daftarBuku[2].tersedia = true;
    daftarBuku[3].idBuku = "B04"; daftarBuku[3].judul = "pengenalan algoritma";  daftarBuku[3].pengarang = "budi ";  daftarBuku[3].tersedia = true;
    daftarBuku[4].idBuku = "B05"; daftarBuku[4].judul = "Pemrograman Berorientasi Objek";  daftarBuku[4].pengarang = "dewi ";  daftarBuku[4].tersedia = true;
    jumlahBuku = 5;
}

void tampilBuku() {
    cout << "\n========================================\n";
    cout << "        DAFTAR BUKU PERPUSTAKAAN        \n";
    cout << "========================================\n";
    if (jumlahBuku == 0) {
        cout << "Perpustakaan kosong.\n";
        return;
    }
    
    int dipinjam = 0;
    int tersedia = 0;

    for (int i = 0; i < jumlahBuku; i++) {
        cout << "ID: " << daftarBuku[i].idBuku 
             << " | Judul: " << daftarBuku[i].judul 
             << " | Pengarang: " << daftarBuku[i].pengarang 
             << " | Status: " << (daftarBuku[i].tersedia ? "Tersedia" : "Dipinjam") << endl;
        
        if (daftarBuku[i].tersedia) tersedia++;
        else dipinjam++;
    }
    
    cout << "----------------------------------------\n";
    cout << "Total Buku: " << jumlahBuku << " | Tersedia: " << tersedia << " | Dipinjam: " << dipinjam << "\n";
    cout << "========================================\n";
}

void cariBuku() {
    string kataKunci;
    cout << "\nMasukkan Judul atau ID Buku yang dicari: ";
    getline(cin, kataKunci);
    
    string keywordLower = toLowerManual(kataKunci);
    bool ketemu = false;
    
    for (int i = 0; i < jumlahBuku; i++) {
        string judulLower = toLowerManual(daftarBuku[i].judul);
        string idLower = toLowerManual(daftarBuku[i].idBuku);
        
        if (judulLower.find(keywordLower) != string::npos || idLower == keywordLower) {
            cout << "\n[Buku Ditemukan]\n";
            cout << "ID: " << daftarBuku[i].idBuku 
                 << " | Judul: " << daftarBuku[i].judul 
                 << " | Pengarang: " << daftarBuku[i].pengarang
                 << " | Status: " << (daftarBuku[i].tersedia ? "Tersedia" : "Dipinjam") << endl;
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Buku tidak ditemukan.\n";
}


// --- TUGAS 2 Modul Manajemen Koleksi Buku (Oleh: Sri Agnia) ---
void tambahBuku() {
    if (jumlahBuku >= MAX_BUKU) {
        cout << "\nKapasitas perpustakaan penuh!\n";
        return;
    }
    
    string idBaru;
    cout << "\nMasukkan ID Buku baru: "; 
    getline(cin, idBaru);

    for (int i = 0; i < jumlahBuku; i++) {
        if (toLowerManual(daftarBuku[i].idBuku) == toLowerManual(idBaru)) {
            cout << "\n[Error] ID Buku '" << idBaru << "' sudah digunakan oleh buku lain!\n";
            return;
        }
    }
    
    daftarBuku[jumlahBuku].idBuku = idBaru;
    cout << "Masukkan Judul Buku  : "; 
    getline(cin, daftarBuku[jumlahBuku].judul);
    cout << "Masukkan Pengarang   : "; 
    getline(cin, daftarBuku[jumlahBuku].pengarang);
    
    daftarBuku[jumlahBuku].tersedia = true;
    jumlahBuku++;
    cout << "\n>> Buku berhasil ditambahkan!\n";
}

void hapusBuku() {
    string id;
    cout << "\nMasukkan ID Buku yang ingin dihapus: "; 
    getline(cin, id);
    
    int indeks = -1;
    for (int i = 0; i < jumlahBuku; i++) {
        if (toLowerManual(daftarBuku[i].idBuku) == toLowerManual(id)) {
            indeks = i;
            break;
        }
    }
    if (indeks == -1) {
        cout << "Buku dengan ID tersebut tidak ditemukan.\n";
    } else {
        for (int i = indeks; i < jumlahBuku - 1; i++) {
            daftarBuku[i] = daftarBuku[i + 1];
        }
        jumlahBuku--;
        cout << "\n>> Buku berhasil dihapus!\n";
    }
}

void editBuku() {
    string id;
    cout << "\nMasukkan ID Buku yang ingin diedit: ";
    getline(cin, id);
    
    string idInputLower = toLowerManual(id);
    
    for (int i = 0; i < jumlahBuku; i++) {
        if (toLowerManual(daftarBuku[i].idBuku) == idInputLower) {
            cout << "\n[Buku Ditemukan]\n";
            cout << "Judul Lama    : " << daftarBuku[i].judul << endl;
            cout << "Pengarang Lama: " << daftarBuku[i].pengarang << endl;
            cout << "----------------------------------------\n";
            
            cout << "Masukkan Judul Baru    : ";
            getline(cin, daftarBuku[i].judul);
            cout << "Masukkan Pengarang Baru: ";
            getline(cin, daftarBuku[i].pengarang);
            
            cout << "\n>> Data buku berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Buku dengan ID tersebut tidak ditemukan.\n";
}


// --- TUGAS 3 Modul Sirkulasi & Algoritma Pengurutan (Oleh: Devina Putri) ---
void pinjamBuku() {
    string id;
    cout << "\nMasukkan ID Buku yang ingin dipinjam: "; 
    getline(cin, id);
    
    string idInputLower = toLowerManual(id);
    
    for (int i = 0; i < jumlahBuku; i++) {
        if (toLowerManual(daftarBuku[i].idBuku) == idInputLower) {
            if (daftarBuku[i].tersedia) {
                daftarBuku[i].tersedia = false;
                riwayatPeminjaman[jumlahRiwayat] = "Meminjam buku: " + daftarBuku[i].judul;
                jumlahRiwayat++;
                cout << "\n>> Berhasil meminjam buku: " << daftarBuku[i].judul << endl;
            } else {
                cout << "\n[Peringatan] Maaf, buku sedang dipinjam orang lain.\n";
            }
            return;
        }
    }
    cout << "ID Buku tidak terdaftar.\n";
}

void kembalikanBuku() {
    string id;
    cout << "\nMasukkan ID Buku yang ingin dikembalikan: "; 
    getline(cin, id);
    
    string idInputLower = toLowerManual(id);
    
    for (int i = 0; i < jumlahBuku; i++) {
        if (toLowerManual(daftarBuku[i].idBuku) == idInputLower) {
            if (!daftarBuku[i].tersedia) {
                if (jumlahRiwayat < MAX_BUKU) {
                    int lamaPinjam = 0;
                    cout << "Berapa hari buku ini dipinjam? : ";
                    cin >> lamaPinjam;
                    cin.ignore();

                    daftarBuku[i].tersedia = true;
                    int denda = 0;
                    string infoDenda = "";

                    if (lamaPinjam > 7) {
                        denda = (lamaPinjam - 7) * 5000;
                        infoDenda = " (Terlambat " + angkaKeStringManual(lamaPinjam - 7) + " hari, Denda: Rp" + angkaKeStringManual(denda) + ")";
                        cout << "\n[Peringatan] Anda terlambat mengembalikan buku! Denda: Rp" << denda << endl;
                    }

                    riwayatPeminjaman[jumlahRiwayat] = "Mengembalikan buku: " + daftarBuku[i].judul + infoDenda;
                    jumlahRiwayat++;
                    cout << "\n>> Terima kasih, buku \"" << daftarBuku[i].judul << "\" telah dikembalikan.\n";
                } else {
                    cout << "\n[Error] Riwayat transaksi penuh!\n";
                }
            } else {
                cout << "\n[Peringatan] Buku ini sudah ada di perpustakaan.\n";
            }
            return;
        }
    }
    cout << "ID Buku tidak terdaftar.\n";
}

void sortingBuku() {
    for (int i = 0; i < jumlahBuku - 1; i++) {
        for (int j = 0; j < jumlahBuku - i - 1; j++) {
            if (daftarBuku[j].judul > daftarBuku[j + 1].judul) {
                NodeBuku temp = daftarBuku[j];
                daftarBuku[j] = daftarBuku[j + 1];
                daftarBuku[j + 1] = temp;
            }
        }
    }
    cout << "\n>> Daftar buku berhasil diurutkan berdasarkan judul (A-Z)!\n";
    tampilBuku();
}



// --- TUGAS 4 Modul Laporan & Rekomendasi Sistem (Oleh: Rezki) ---
void rekomendasiBuku() {
    cout << "\n========================================\n";
    cout << "        REKOMENDASI BUKU MINGGU INI      \n";
    cout << "========================================\n";
    if (jumlahBuku > 0) {
        cout << " -> " << daftarBuku[0].judul << " (Paling banyak dicari)\n";
    } else {
        cout << " Belum ada rekomendasi.\n";
    }
}

void riwayatBuku() {
    cout << "\n========================================\n";
    cout << "      RIWAYAT TRANSAKSI PERPUSTAKAAN    \n";
    cout << "========================================\n";
    if (jumlahRiwayat == 0) {
        cout << " Belum ada riwayat transaksi.\n";
        return;
    }
    for (int i = 0; i < jumlahRiwayat; i++) {
        cout << " " << i + 1 << ". " << riwayatPeminjaman[i] << endl;
    }
}

void hapusRiwayat() {
    jumlahRiwayat = 0;
    cout << "\n>> Semua riwayat transaksi berhasil dihapus!\n";
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
