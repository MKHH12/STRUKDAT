#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

// Struktur untuk node dalam linked list
struct kereta
{
    int kode;
    string nama_kereta;
    string tujuan;
    int ketersediaan;
    string jam;
    int harga;
    kereta *next; // Tambahkan anggota ini untuk penjelajahan daftar tertaut
};

struct Pesanan
{
    string nama_kereta;
    int jumlah_tiket;
    int total_harga;
    int kode_kereta;
    string nama;
    string no_hp;
};

// Struktur untuk node dalam linked list
struct Node
{
    kereta data;
    Node *next;
    Node *prev;
};

struct PesananNode
{
    Pesanan data; // Include Pesanan structure
    PesananNode *next;
};

int jumlah_pesanan = 0;
PesananNode *headPesanan = nullptr;
kereta *headkereta = nullptr;

struct User
{
    string username;
    string password;
    bool isAdmin;
    User *next;

    User(const string &_username, const string &_password, bool _isAdmin)
        : username(_username), password(_password), isAdmin(_isAdmin), next(nullptr) {}
};

queue<pair<string, pair<string, bool>>> registrationQueue;

int banyak_data = 0;

// Fungsi-fungsi untuk mengelola linked list
void tambahData(Node *&head, int &jumlahData)
{
    void saveDataToFile(Node * head);
    Node *newNode = new Node;

    // Validasi input Kode kereta
    cout << "Masukkan Kode kereta: ";
    while (!(cin >> newNode->data.kode))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Kode kereta hanya boleh mengandung angka." << endl;
        cout << "Masukkan Kode kereta (angka): ";
    }

    cin.ignore(); // Menghapus karakter newline dalam buffer

    // Validasi input Nama kereta
    cout << "Masukkan Nama kereta: ";
    while (true)
    {
        getline(cin, newNode->data.nama_kereta);
        bool isInvalid = false;
        for (char c : newNode->data.nama_kereta)
        {
            if (!isalpha(c))
            {
                isInvalid = true;
                break;
            }
        }
        if (!isInvalid)
        {
            break; // Keluar dari loop jika tidak ada karakter selain huruf
        }
        cout << "Input tidak valid. Nama kereta hanya boleh mengandung huruf." << endl;
        cout << "Masukkan Nama kereta :";
    }

    // Validasi input Tujuan
    cout << "Masukkan Tujuan: ";
    while (true)
    {
        getline(cin, newNode->data.tujuan);
        bool isInvalid = false;
        for (char c : newNode->data.tujuan)
        {
            if (!isalpha(c))
            {
                isInvalid = true;
                break;
            }
        }
        if (!isInvalid)
        {
            break; // Keluar dari loop jika tidak ada karakter selain huruf
        }
        cout << "Input tidak valid. Nama kereta hanya boleh mengandung huruf." << endl;
        cout << "Masukkan Tujuan :";
    }

    // Validasi input Ketersediaan
    cout << "Masukkan Ketersediaan: ";
    while (!(cin >> newNode->data.ketersediaan))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Ketersedian hanya boleh mengandung angka." << endl;
        cout << "Masukkan Ketersediaan (angka): ";
    }

    cin.ignore(); // Menghapus karakter newline dalam buffer

    // Validasi input Jam Keberangkatan
    cout << "Masukkan Jam Keberangkatan: ";
    getline(cin, newNode->data.jam);

    // Validasi input Harga Tiket
    cout << "Masukkan Harga Tiket: ";
    while (!(cin >> newNode->data.harga))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Harga Tiket hanya boleh mengandung angka." << endl;
        cout << "Masukkan Kode kereta (angka): ";
    }

    cin.ignore(); // Menghapus karakter newline dalam buffer

    newNode->next = head;
    newNode->prev = nullptr; // Mengatur prev menjadi nullptr karena ini adalah node pertama
    if (head)
    {
        head->prev = newNode; // Mengatur prev dari node sebelumnya ke newNode
    }
    head = newNode;
    jumlahData++;
    saveDataToFile(head);
    cout << "Data berhasil ditambahkan!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");
}

// Fungsi untuk menambahkan node di akhir linked list
void tambahDataDiAkhir(Node *&head, int &jumlahData)
{

    void saveDataToFile(Node * head);
    Node *newNode = new Node;
    cout << "Masukkan Kode kereta: ";
    while (!(cin >> newNode->data.kode))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Kode kereta hanya boleh mengandung angka." << endl;
        cout << "Masukkan Kode kereta (angka): ";
    }

    cin.ignore(); // Menghapus karakter newline dalam buffer

    cout << "Masukkan Nama kereta: ";
    while (true)
    {
        getline(cin, newNode->data.nama_kereta);
        bool isInvalid = false;
        for (char c : newNode->data.nama_kereta)
        {
            if (!isalpha(c))
            {
                isInvalid = true;
                break;
            }
        }
        if (!isInvalid)
        {
            break; // Keluar dari loop jika tidak ada karakter selain huruf
        }
        cout << "Input tidak valid. Nama kereta hanya boleh mengandung huruf." << endl;
        cout << "Masukkan Nama kereta :";
    }

    cout << "Masukkan Tujuan: ";
    while (true)
    {
        getline(cin, newNode->data.tujuan);
        bool isInvalid = false;
        for (char c : newNode->data.tujuan)
        {
            if (!isalpha(c))
            {
                isInvalid = true;
                break;
            }
        }
        if (!isInvalid)
        {
            break; // Keluar dari loop jika tidak ada karakter selain huruf
        }
        cout << "Input tidak valid. Nama kereta hanya boleh mengandung huruf." << endl;
        cout << "Masukkan Tujuan :";
    }

    cout << "Masukkan Ketersediaan: ";
    while (!(cin >> newNode->data.ketersediaan))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Ketersedian hanya boleh mengandung angka." << endl;
        cout << "Masukkan Ketersediaan (angka): ";
    }

    cin.ignore(); // Menghapus karakter newline dalam buffer

    cout << "Masukkan Jam Keberangkatan: ";
    getline(cin, newNode->data.jam);

    cout << "Masukkan Harga Tiket: ";
    while (!(cin >> newNode->data.harga))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Harga Tiket hanya boleh mengandung angka." << endl;
        cout << "Masukkan Kode kereta (angka): ";
    }

    cin.ignore(); // Menghapus karakter newline dalam buffer

    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        newNode->prev = current;
        current->next = newNode;
    }

    jumlahData++;
    saveDataToFile(head);
    cout << "Data berhasil ditambahkan di akhir!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");
}

//fungsi untuk membuat daftar tiket dalam user
void tampil_user(Node *head)
{
    string ulang;
    void tampilkanData(Node * head);
    void push_pesanan(string nama_kereta, int jumlah_tiket, int total_harga, int kode_kereta, string nama, string no_hp);
    void savePesananToFile(PesananNode * headPesanan);
    while (true)
    {
        tampilkanData(head);
        cout << "Ingin Memesan Tiket (y/t)? ";
        cin >> ulang;

        if (ulang == "y" || ulang == "Y")
        {
            int kode_kereta, jumlah_tiket, total_harga;
            string nama_kereta, nama, no_hp, pesan_lagi;
            bool found_kereta = false;

            do
            {
                cout << "Masukkan Kode Kereta yang ingin dipesan: ";
                cin >> kode_kereta;
                cout << endl;
                if (cin.fail())
                {
                    cout << "Input tidak valid. Silakan masukkan angka." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                found_kereta = false;
                Node *current = head;
                while (current != nullptr)
                {
                    if (current->data.kode == kode_kereta)
                    {
                        found_kereta = true;
                        if (current->data.ketersediaan > 0)
                        {
                            cout << "Masukkan Nama lengkap anda: ";
                            fflush(stdin);
                            getline(cin, nama);

                            if (!isalpha(nama[0]))
                            {
                                cerr << "=========================================" << endl;
                                cerr << "Input tidak valid. Silakan masukkan huruf." << endl;
                                cerr << "=========================================" << endl;
                                cin.clear();
                                this_thread::sleep_for(chrono::seconds(2));
                                system("cls");
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                return;
                            }

                            cout << "Masukkan No HP: ";
                            cin >> no_hp;

                            cout << "Masukkan jumlah tiket yang ingin dipesan: ";
                            cin >> jumlah_tiket;
                            if (cin.fail())
                            {
                                cout << "=========================================" << endl;
                                cout << "Input tidak valid. Silakan masukkan angka." << endl;
                                cout << "=========================================" << endl;
                                cin.clear();
                                this_thread::sleep_for(chrono::seconds(1));
                                system("cls");
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                continue;
                            }

                            if (current->data.ketersediaan >= jumlah_tiket)
                            {
                                total_harga = jumlah_tiket * current->data.harga;
                                cout << "Total Harga: Rp " << total_harga << endl;
                                cout << "Pesanan berhasil. Silakan melakukan pembayaran." << endl;
                                current->data.ketersediaan -= jumlah_tiket;

                                // Add the pesanan to the linked list
                                push_pesanan(current->data.nama_kereta, jumlah_tiket, total_harga, kode_kereta, nama, no_hp);
                                savePesananToFile(headPesanan);
                                cout << "Ingin Memesan Tiket lagi (y/t)? ";
                                cin >> pesan_lagi;

                                if (pesan_lagi == "y" || pesan_lagi == "Y")
                                {
                                    system("cls");
                                    break;
                                }
                                else
                                {
                                    system("cls");
                                    return;
                                }
                            }
                            else
                            {
                                cout << "Tiket tidak tersedia." << endl;
                                this_thread::sleep_for(chrono::seconds(2));
                                system("cls");
                                return;
                            }
                        }
                        else
                        {
                            cout << "Tiket tidak tersedia." << endl;
                            this_thread::sleep_for(chrono::seconds(2));
                            system("cls");
                            return;
                        }
                    }
                    current = current->next;
                }

                if (!found_kereta)
                {
                    cout << "Kode kereta tidak ditemukan. Silakan coba lagi." << endl;
                }

            } while (!found_kereta);
        }
        else
        {
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            break;
        }
    }
}

//Fungsi menampilkan tampilan booking di user
void tampilkanBooking(PesananNode *headPesanan)
{
    if (!headPesanan)
    {
        cout << "===================================" << endl;
        cout << " Maaf Anda Belum Melakukan Booking " << endl;
        cout << "===================================" << endl;
        cout << " *mohon melakukan Booking " << endl;
        cout << "===================================" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");
        return;
    }

    PesananNode *current = headPesanan;
    cout << "Berikut adalah daftar pesanan yang telah dibuat:" << endl;
    int total_harga_semua_pesanan = 0;
    int nomorData = 1;

    while (current)
    {
        cout << "==============================================" << endl;
        cout << "No" << nomorData << ":" << endl;
        cout << "Nama Kereta: " << current->data.nama_kereta << endl;
        cout << "Nama Pemesan: " << current->data.nama << endl;
        cout << "No HP: " << current->data.no_hp << endl;
        cout << "Jumlah Tiket: " << current->data.jumlah_tiket << endl;
        cout << "Total Harga: Rp " << current->data.total_harga << endl;
        cout << "==============================================" << endl;
        total_harga_semua_pesanan += current->data.total_harga;

        current = current->next;
        nomorData++;
    }
    cout << "Total Harga Yang harus di bayar: Rp " << total_harga_semua_pesanan << endl; // mencetak total harga semua pesanan
}

//Fungsi untuk menyertakan panggilan dari 
void push_pesanan(string nama_kereta, int jumlah_tiket, int total_harga, int kode_kereta, string nama, string no_hp)
{
    PesananNode *newPesanan = new PesananNode;
    newPesanan->data.nama_kereta = nama_kereta;
    newPesanan->data.jumlah_tiket = jumlah_tiket;
    newPesanan->data.total_harga = total_harga;
    newPesanan->data.kode_kereta = kode_kereta;
    newPesanan->data.nama = nama;
    newPesanan->data.no_hp = no_hp;
    newPesanan->next = nullptr;

    if (headPesanan == nullptr)
    {
        headPesanan = newPesanan;
    }
    else
    {
        PesananNode *current = headPesanan;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newPesanan;
    }
}

//Fungsi untuk membuat tampilan pada menu 
void tampil_admin(Node *head)
{
    string ulang;
    void tampilkanData(Node * head);

    while (true)
    {
        tampilkanData(head);
        cout << "Ingin kembali (y/t)? ";
        cin >> ulang;
        if (ulang == "y" || ulang == "Y")
        {
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            break;
        }
        else
        {
            cout << "Terima kasih." << endl;
            exit(0);
        }
    }
}

// Fungsi untuk menampilkan data kereta
void tampilkanData(Node *head)
{

    if (!head)
    {
        cout << "Belum ada data kereta yang tersedia." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");
        return;
    }

    Node *current = head;
    cout << "Daftar Data kereta:" << endl;
    int nomorData = 1; // Tambahkan variabel nomorData

    while (current)
    {
        cout << "==============================================" << endl;
        cout << "Data ke-" << nomorData << ":" << endl; // Menambahkan nomorData ke output
        cout << "Kode kereta: " << current->data.kode << endl;
        cout << "Nama kereta: " << current->data.nama_kereta << endl;
        cout << "Tujuan: " << current->data.tujuan << endl;
        cout << "Ketersediaan: " << current->data.ketersediaan << endl;
        cout << "Jam Keberangkatan: " << current->data.jam << endl;
        cout << "Harga Tiket: " << current->data.harga << endl;

        current = current->next;
        nomorData++; // Tingkatkan nomorData
    }

    cout << "==============================================" << endl;
}


//Fungsi buat mengupdate atau merubah data tiket pada ADMIN
void updateData(Node *head)
{
    void saveDataToFile(Node * head);
    if (!head)
    {
        cout << "Belum ada data kereta yang tersedia." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");
        return;
    }

    int kodekereta;
    cout << "Masukkan kode kereta yang akan diupdate: ";
    cin >> kodekereta;

    Node *current = head;
    Node *prev = nullptr; // Pointer untuk mengakses elemen sebelumnya

    while (current)
    {
        if (current->data.kode == kodekereta)
        {
            cout << "Data saat ini:" << endl;
            cout << "==============================================" << endl;
            cout << "Kode kereta: " << current->data.kode << endl;
            cout << "Nama kereta: " << current->data.nama_kereta << endl;
            cout << "Tujuan: " << current->data.tujuan << endl;
            cout << "Ketersediaan: " << current->data.ketersediaan << endl;
            cout << "Jam Keberangkatan: " << current->data.jam << endl;
            cout << "Harga Tiket: " << current->data.harga << endl;

            cout << "==============================================" << endl;

            cout << "Masukkan Kode kereta baru: ";
            while (!(cin >> current->data.kode))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Masukkan Kode kereta (angka): ";
            }

            cin.ignore(); // Menghapus karakter newline dalam buffer

            cout << "Masukkan Nama kereta baru: ";
            getline(cin, current->data.nama_kereta);

            cout << "Masukkan Tujuan baru: ";
            getline(cin, current->data.tujuan);

            cout << "Masukkan Ketersediaan baru: ";
            while (!(cin >> current->data.ketersediaan))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Masukkan Ketersediaan (angka): ";
            }

            cin.ignore(); // Menghapus karakter newline dalam buffer

            cout << "Masukkan Jam Keberangkatan baru: ";
            getline(cin, current->data.jam);

            cout << "Masukkan Harga Tiket baru: ";
            while (!(cin >> current->data.harga))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Masukkan Harga Tiket (angka): ";
            }

            cin.ignore(); // Menghapus karakter newline dalam buffer

            saveDataToFile(head);
            cout << "Data berhasil diupdate!" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            return;
        }

        prev = current;
        current = current->next;
    }

    cout << "Data dengan kode kereta " << kodekereta << " tidak ditemukan." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");
}

// Fungsi untuk menghapus data kereta
void hapusData(Node *&head, int &jumlahData)
{
    void saveDataToFile(Node * head);

    if (head)
    {
        int kode_kereta;
        cout << "Masukkan Kode Kereta yang akan dihapus: ";
        cin >> kode_kereta;

        Node *current = head;
        Node *prev = nullptr;
        bool found = false;

        while (current != nullptr)
        {
            if (current->data.kode == kode_kereta)
            {
                found = true;
                if (prev == nullptr)
                {
                    // Hapus node di awal
                    head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }

                delete current;
                jumlahData--;

                saveDataToFile(head);
                cout << "Data kereta berhasil dihapus!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                system("cls");
                break;
            }

            prev = current;
            current = current->next;
        }

        if (!found)
        {
            cout << "Kode Kereta tidak ditemukan." << endl;
        }
    }
    else
    {
        cout << "Belum ada data kereta yang tersedia." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");
    }
}

void shellSort(Node *&head)
{
    if (!head || !head->next)
    {
        return; // Tidak perlu sorting jika tidak ada data atau hanya ada satu data
    }

    int jumlahData = 0;
    Node *current = head;

    // Menghitung jumlah data dalam linked list
    while (current)
    {
        jumlahData++;
        current = current->next;
    }

    // Menggunakan pengecilan interval dengan faktor 2
    for (int interval = jumlahData / 2; interval > 0; interval /= 2)
    {
        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            Node *prev = nullptr;
            current = head;

            // Lakukan Bubble Sort pada interval yang ditentukan
            for (int i = 0; i < interval; i++)
            {
                if (!current)
                {
                    break;
                }
                prev = current;
                current = current->next;
            }

            while (current)
            {
                if (prev->data.kode > current->data.kode)
                {
                    // Tukar data jika kondisi terpenuhi
                    kereta temp = prev->data;
                    prev->data = current->data;
                    current->data = temp;
                    swapped = true;
                }
                prev = current;
                current = current->next;
            }
        }
    }

    // Menutup linked list yang sudah diurutkan
    Node *lastNode = head;
    while (lastNode->next)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = nullptr;
}

//Fungsi pengurutan  data berdasarkan dari besar ke kecil
void shellSortDescending(Node *&head)
{
    if (!head || !head->next)
    {
        return; // Tidak perlu sorting jika tidak ada data atau hanya ada satu data
    }

    int jumlahData = 0;
    Node *current = head;

    // Menghitung jumlah data dalam linked list
    while (current)
    {
        jumlahData++;
        current = current->next;
    }

    // Menggunakan pengecilan interval dengan faktor 2
    for (int interval = jumlahData / 2; interval > 0; interval /= 2)
    {
        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            Node *prev = nullptr;
            current = head;

            // Lakukan Bubble Sort pada interval yang ditentukan
            for (int i = 0; i < interval; i++)
            {
                if (!current)
                {
                    break;
                }
                prev = current;
                current = current->next;
            }

            while (current)
            {
                if (prev->data.kode < current->data.kode)
                { // Mengganti operator perbandingan menjadi '<'
                    // Tukar data jika kondisi terpenuhi
                    kereta temp = prev->data;
                    prev->data = current->data;
                    current->data = temp;
                    swapped = true;
                }
                prev = current;
                current = current->next;
            }
        }
    }

    // Menutup linked list yang sudah diurutkan
    Node *lastNode = head;
    while (lastNode->next)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = nullptr;
}
// Fungsi untuk mengurutkan data berdasarkan nama
void shellSortByName(Node *&head)
{
    if (!head || !head->next)
    {
        return; // Tidak perlu sorting jika tidak ada data atau hanya ada satu data
    }

    int jumlahData = 0;
    Node *current = head;

    // Menghitung jumlah data dalam linked list
    while (current)
    {
        jumlahData++;
        current = current->next;
    }

    // Menggunakan pengecilan interval dengan faktor 2
    for (int interval = jumlahData / 2; interval > 0; interval /= 2)
    {
        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            Node *prev = nullptr;
            current = head;

            // Lakukan Bubble Sort pada interval yang ditentukan
            for (int i = 0; i < interval; i++)
            {
                if (!current)
                {
                    break;
                }
                prev = current;
                current = current->next;
            }

            while (current)
            {
                // Membandingkan berdasarkan nama kereta (string)
                if (prev->data.nama_kereta > current->data.nama_kereta)
                {
                    // Tukar data jika kondisi terpenuhi
                    kereta temp = prev->data;
                    prev->data = current->data;
                    current->data = temp;
                    swapped = true;
                }
                prev = current;
                current = current->next;
            }
        }
    }

    // Menutup linked list yang sudah diurutkan
    Node *lastNode = head;
    while (lastNode->next)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = nullptr;
}

// Fungsi untuk mengurutkan data berdasarkan nama dengan konsep descending
void shellSortDescendingByName(Node *&head)
{
    if (!head || !head->next)
    {
        return; // Tidak perlu sorting jika tidak ada data atau hanya ada satu data
    }

    int jumlahData = 0;
    Node *current = head;

    // Menghitung jumlah data dalam linked list
    while (current)
    {
        jumlahData++;
        current = current->next;
    }

    // Menggunakan pengecilan interval dengan faktor 2
    for (int interval = jumlahData / 2; interval > 0; interval /= 2)
    {
        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            Node *prev = nullptr;
            current = head;

            // Lakukan Bubble Sort pada interval yang ditentukan
            for (int i = 0; i < interval; i++)
            {
                if (!current)
                {
                    break;
                }
                prev = current;
                current = current->next;
            }

            while (current)
            {
                // Membandingkan berdasarkan nama kereta (string)
                if (prev->data.nama_kereta < current->data.nama_kereta)
                { // Mengganti operator perbandingan menjadi '<'
                    // Tukar data jika kondisi terpenuhi
                    kereta temp = prev->data;
                    prev->data = current->data;
                    current->data = temp;
                    swapped = true;
                }
                prev = current;
                current = current->next;
            }
        }
    }

    // Menutup linked list yang sudah diurutkan
    Node *lastNode = head;
    while (lastNode->next)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = nullptr;
}
// Function untuk mengurutkan sebuah data dari admin
void sorting(Node *&head)
{
    int subpilihan2;

    do
    {
        cout << "1. Sorting Kode kereta secara Ascending" << endl;
        cout << "2. Sorting Kode kereta secara Descending" << endl;
        cout << "3. Sorting Nama kereta secara Ascending" << endl;
        cout << "4. Sorting Nama kereta secara Descending" << endl;
        cout << "5. Kembali ke menu utama" << endl;
        cout << "Pilihan: ";
        cin >> subpilihan2;

        switch (subpilihan2)
        {

        case 1:
            shellSort(head); // Memanggil fungsi Shell Sort
            cout << "Data kereta berhasil diurutkan secara ascending berdasarkan Kode." << endl;
            tampilkanData(head); // Menampilkan data yang sudah diurutkan
            break;

        case 2:
            shellSortDescending(head); // Memanggil fungsi Shell Sort
            cout << "Data kereta berhasil diurutkan secara Descending berdasarkan Kode." << endl;
            tampilkanData(head); // Menampilkan data yang sudah diurutkan
            break;

        case 3:
            shellSortByName(head); // Memanggil fungsi Shell Sort
            cout << "Data kereta berhasil diurutkan secara ascending berdasarkan Nama." << endl;
            tampilkanData(head); // Menampilkan data yang sudah diurutkan
            break;

        case 4:
            shellSortDescendingByName(head); // Memanggil fungsi Shell Sort
            cout << "Data kereta berhasil diurutkan secara ascending berdasarkan Nama." << endl;
            tampilkanData(head); // Menampilkan data yang sudah diurutkan
            break;

        case 5:
            cout << "Kembali ke menu utama." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

    } while (subpilihan2 != 5);
}

Node *boyerMooreSearch(Node *head, int target)
{
    Node *current = head;
    while (current)
    {
        if (current->data.kode == target)
        {
            return current; // Return node yang ditemukan
        }
        current = current->next;
    }
    return nullptr; // Return nullptr jika tidak ditemukan
}

//Fungsi untuk mencari sebuah ID dari Tiket Kereta tersebut
void searchingID(Node *head)
{

    int kodekereta;
    cout << "Masukkan Kode kereta yang akan dicari: ";
    while (!(cin >> kodekereta) || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Kode kereta hanya boleh mengandung angka." << endl;
        cout << "Masukkan Kode kereta (angka): ";
    }

    Node *result = boyerMooreSearch(head, kodekereta);

    if (result)
    {
        cout << "==============================================" << endl;
        cout << "Data ditemukan:" << endl;
        cout << "Kode kereta: " << result->data.kode << endl;
        cout << "Nama kereta: " << result->data.nama_kereta << endl;
        cout << "Tujuan: " << result->data.tujuan << endl;
        cout << "Ketersediaan: " << result->data.ketersediaan << endl;
        cout << "Jam Keberangkatan: " << result->data.jam << endl;
        cout << "Harga Tiket: " << result->data.harga << endl;
        cout << "==============================================" << endl;
    }
    else
    {
        cout << "==============================================" << endl;
        cout << "Data dengan Kode kereta " << kodekereta << " tidak ditemukan." << endl;
        cout << "==============================================" << endl;
    }
}

Node *nameSearch(Node *head, const string &target)
{
    Node *current = head;
    while (current)
    {
        if (current->data.nama_kereta == target)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

//Fungsi pencarian data dengan berdasarkan nama
void searchingName(Node *head)
{
    string namakereta;
    cout << "Masukkan Nama kereta yang akan dicari: ";

    while (true)
    {
        cin.ignore(); // Membersihkan karakter newline (\n) dari buffer
        getline(cin, namakereta);

        bool isInvalid = false;
        for (char c : namakereta)
        {
            if (!isalpha(c) && !isspace(c))
            { // Memastikan hanya huruf dan spasi diizinkan
                isInvalid = true;
                break;
            }
        }

        if (!isInvalid)
        {
            break; // Keluar dari loop jika namakereta sesuai
        }

        cout << "Input tidak valid. Nama kereta hanya boleh mengandung huruf dan spasi." << endl;
        cout << "Masukkan Nama kereta: ";
    }

    Node *result = nameSearch(head, namakereta);

    if (result)
    {
        cout << "==============================================" << endl;
        cout << "Data ditemukan:" << endl;
        cout << "Kode kereta: " << result->data.kode << endl;
        cout << "Nama kereta: " << result->data.nama_kereta << endl;
        cout << "Tujuan: " << result->data.tujuan << endl;
        cout << "Ketersediaan: " << result->data.ketersediaan << endl;
        cout << "Jam Keberangkatan: " << result->data.jam << endl;
        cout << "Harga Tiket: " << result->data.harga << endl;
        cout << "==============================================" << endl;
    }
    else
    {
        cout << "==============================================" << endl;
        cout << "Data dengan Nama kereta '" << namakereta << "' tidak ditemukan." << endl;
        cout << "==============================================" << endl;
    }
}

// Fungsi Pencarian utama dari menu admin
void searching(Node *head)
{
    int subpilihan3;

    do
    {
        cout << "1. Searching Kode kereta" << endl;
        cout << "2. Sorting Nama kereta" << endl;
        cout << "3. Kembali ke menu utama" << endl;
        cout << "Pilihan: ";
        cin >> subpilihan3;

        switch (subpilihan3)
        {

        case 1:

            searchingID(head);
            break;

        case 2:
            searchingName(head);
            break;

        case 3:
            cout << "Kembali ke menu utama." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

    } while (subpilihan3 != 3);
}

//Fungsi untuk menyediakan menu akses dan operasi khusus bagi administrator (admin) program
void menuadmin(Node *head)
{
    int jumlahData = banyak_data;
    int pilihan;

    do
    {
        cout << "\t\t\t\t\t====================================" << endl;
        cout << "\t\t\t\t\t##  Sistem Manajemen Data kereta  ##" << endl;
        cout << "\t\t\t\t\t====================================" << endl;
        cout << "\t\t\t\t\t1. Tambah Data kereta di Awal/Akhir" << endl;
        cout << "\t\t\t\t\t2. Tampilkan Data kereta" << endl;
        cout << "\t\t\t\t\t3. Update Data kereta" << endl;
        cout << "\t\t\t\t\t4. Hapus Data kereta" << endl;
        cout << "\t\t\t\t\t5. Cari Data kereta" << endl;
        cout << "\t\t\t\t\t6. Urutkan Data kereta" << endl;
        cout << "\t\t\t\t\t7. Keluar" << endl;
        cout << "\t\t\t\t\t====================================" << endl;
        cout << "\t\t\t\t\t====================================" << endl;
        cout << "\t\t\t\t\tPilihan: ";
        cin >> pilihan;
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");

        kereta data; // Data baru yang akan ditambahkan

        switch (pilihan)
        {
        case 1:
            cout << "\t\t\t\t\t====================================" << endl;
            cout << "\t\t\t\t\t##      Tambah Data kereta       ##" << endl;
            cout << "\t\t\t\t\t====================================" << endl;
            cout << "\t\t\t\t\t1. Tambah Data kereta di Awal" << endl;
            cout << "\t\t\t\t\t2. Tambah Data kereta di Akhir" << endl;
            cout << "\t\t\t\t\t3. Kembali ke menu utama" << endl;
            cout << "\t\t\t\t\t====================================" << endl;
            cout << "\t\t\t\t\t====================================" << endl;
            cout << "\t\t\t\t\tPilihan: ";
            int subPilihan;
            cin >> subPilihan;
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            switch (subPilihan)
            {
            case 1:
                tambahData(head, jumlahData);
                break;
            case 2:
                tambahDataDiAkhir(head, jumlahData);
                break;
            case 3:
                cout << "Kembali ke menu utama." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                system("cls");
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
            }
            break;
        case 2:
            tampil_admin(head);
            break;
        case 3:
            updateData(head);
            break;
        case 4:
            hapusData(head, jumlahData);
            break;
        case 5:
            searching(head);
            break;
        case 6:
            sorting(head);
            break;
        case 7:
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 7);

    // Hapus semua node dari linked list sebelum keluar
    Node *current = head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}
//Fungsi untuk menyediakan menu akses dan operasi khusus bagi customer (user) program
void menuuser(Node *head)
{

    int pilihan;

    do
    {
        cout << "                                               ===================" << endl;
        cout << "                                               ##  Daftar Menu  ##" << endl;
        cout << "                                               ===================" << endl;
        cout << "                                               1. Daftar Tiket\n";
        cout << "                                               2. Daftar Booking\n";
        cout << "                                               3. Log out\n";
        cout << "                                               ===================" << endl;
        cout << "                                               ===================" << endl;
        cout << "                                               Pilihan: ";

        cin >> pilihan;
        cin.clear();
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");

        if (cin.fail())
        {
            cout << "Input tidak valid. Silakan masukkan angka." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (pilihan)
        {
        case 1:
            tampil_user(head);
            break;
        case 2:
            tampilkanBooking(headPesanan);
            break;
        case 3:
            return;

        default:
            cout << "Pilihan tidak tersedia." << endl;
        }
    } while (pilihan != 3);
}

User *findUser(User *head, const string &username)
{
    User *current = head;
    while (current != nullptr)
    {
        if (current->username == username)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
//Fungsi untuk memproses antrian pendaftaran pengguna baru (users) yng telah mendaftar dan menunggu untuk diverifikasi atau diproses lebih lanjut.
void processRegistrationQueue(User *&head)
{
    while (!registrationQueue.empty())
    {
        pair<string, pair<string, bool>> registrationRequest = registrationQueue.front();
        registrationQueue.pop();

        const string &username = registrationRequest.first;
        const string &password = registrationRequest.second.first;
        bool isAdmin = registrationRequest.second.second;

        if (findUser(head, username) != nullptr)
        {
            cout << "Nama pengguna " << username << " sudah digunakan. Pendaftaran ditolak." << endl;
        }
        else
        {
            User *newUser = new User(username, password, isAdmin);
            newUser->next = head;
            head = newUser;

            cout << "Pendaftaran pengguna " << username << " berhasil." << endl;
        }
    }
}

// Fungsi untuk melakukan pendaftaran pengguna
void registerUser(User *&head, const string &username, const string &password, bool isAdmin)
{
    // Enqueue the registration request
    registrationQueue.push({username, {password, isAdmin}});
    cout << "Registrasi pengguna dalam antrian. Silakan tunggu admin mengonfirmasi." << endl;
}

// Fungsi untuk melakukan login
User *loginUser(User *head, const string &username, const string &password)
{
    User *user = findUser(head, username);
    if (user == nullptr)
    {
        cout << "Nama pengguna tidak ditemukan. Silakan coba lagi." << endl;
        return nullptr;
    }

    if (user->password == password)
    {
        cout << "Login berhasil. Selamat datang, " << username << "!" << endl;
        return user;
    }
    else
    {
        cout << "Login gagal. Kata sandi salah. Silakan coba lagi." << endl;
        return nullptr;
    }
}


//Fungsi untuk menyimpan data pesanan tiket ke dalam sebuah file eksternal. 
void savePesananToFile(PesananNode *headPesanan)
{
    ofstream file("pesanan.txt");
    if (!file)
    {
        cout << "Gagal membuka file pesanan.txt" << endl;
        return;
    }

    PesananNode *current = headPesanan;
    while (current)
    {
        file << current->data.nama_kereta << ","
             << current->data.jumlah_tiket << ","
             << current->data.total_harga << ","
             << current->data.kode_kereta << ","
             << current->data.nama << ","
             << current->data.no_hp << endl;
        current = current->next;
    }

    file.close();
    cout << "Data berhasil disimpan ke dalam file pesanan.txt" << endl;
}


//Fungsi untuk membaca data pesanan tiket dari file eksternal dan memuatnya ke dalam linked list PesananNode.
void loadPesananFromFile(PesananNode *&headPesanan, int &jumlah_pesanan)
{
    ifstream file("pesanan.txt");
    if (!file)
    {
        cout << "Gagal membuka file pesanan.txt" << endl;
        return;
    }

    PesananNode *current = headPesanan;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    string line;
    while (getline(file, line))
    {
        istringstream ss(line);
        string token;

        Pesanan pesanan;
        getline(ss, token, ',');
        pesanan.nama_kereta = token;

        getline(ss, token, ',');
        pesanan.jumlah_tiket = stoi(token);

        getline(ss, token, ',');
        pesanan.total_harga = stoi(token);

        getline(ss, token, ',');
        pesanan.kode_kereta = stoi(token);

        getline(ss, token, ',');
        pesanan.nama = token;

        getline(ss, token, ',');
        pesanan.no_hp = token;

        PesananNode *newPesanan = new PesananNode;
        newPesanan->data = pesanan;
        newPesanan->next = nullptr;

        current->next = newPesanan;
        current = newPesanan;
    }

    file.close();
}

//Fungsi digunakan untuk menyimpan data kereta ke dalam file eksternal
void saveDataToFile(Node *head)
{
    ofstream file("data_kereta.txt");
    if (!file)
    {
        cout << "Gagal membuka file data_kereta.txt" << endl;
        return;
    }

    Node *current = head;
    while (current)
    {
        file << current->data.kode << ","
             << current->data.nama_kereta << ","
             << current->data.tujuan << ","
             << current->data.ketersediaan << ","
             << current->data.jam << ","
             << current->data.harga << endl;
        current = current->next;
    }

    file.close();
    cout << "Data berhasil disimpan ke dalam file data_kereta.txt" << endl;
}

//Fungsi digunakan untuk memuat data kereta dari file eksternal ke dalam linked list
void loadDataFromFile(Node *&head, int &jumlahData)
{
    ifstream file("data_kereta.txt");
    if (!file)
    {
        return;
    }

    string line;
    while (getline(file, line))
    {
        istringstream ss(line);
        kereta data;
        string token;

        getline(ss, token, ',');
        data.kode = stoi(token);

        getline(ss, data.nama_kereta, ',');
        getline(ss, data.tujuan, ',');
        getline(ss, token, ',');
        data.ketersediaan = stoi(token);

        getline(ss, data.jam, ',');
        getline(ss, token, ',');
        data.harga = stoi(token);

        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr; // New node is always the last node, so its next is nullptr
        newNode->prev = nullptr;

        if (head == nullptr)
        {
            head = newNode; // If the list is empty, the new node becomes the head
        }
        else
        {
            // Otherwise, find the last node and connect it to the new node
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }

        jumlahData++;
    }

    file.close();
}

int main()
{
    int jumlah_pesanan = 0;
    int jumlahData = banyak_data;
    Node *head = nullptr;
    User *users = nullptr;

    // Mendaftarkan admin
    registerUser(users, "admin", "admin", true);
    loadDataFromFile(head, jumlahData);
    loadPesananFromFile(headPesanan, jumlah_pesanan);

        int choice;
    User *currentUser = nullptr;

    cout << "\t\t\t\t\t     PROJEK AKHIR " << endl;
    cout << "\t\t\t\t\t1. Fahturahman (129)" << endl;
    cout << "\t\t\t\t\t2. Muhammad Khairrudin (128)" << endl;
    cout << "\t\t\t\t\t3. Muhammad Subhan Aprisal (132)" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");

    do
    {
        cout << "\t\t\t\t\t|=============================|" << endl;
        cout << "\t\t\t\t\t|=======SELAMAT DATANG========|" << endl;
        cout << "\t\t\t\t\t|=============================|" << endl;
        cout << "\t\t\t\t\t|=========TiketLoket==========|" << endl;
        cout << "\t\t\t\t\t|=============================|" << endl;
        cout << "\t\t\t\t\t1. Login" << endl;
        cout << "\t\t\t\t\t2. Daftar" << endl;
        cout << "\t\t\t\t\t3. Keluar" << endl;
        cout << "\t\t\t\t\tPilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string username, password;
            cout << "\t\t\t\t\tMasukkan nama pengguna: ";
            cin >> username;
            cout << "\t\t\t\t\tMasukkan kata sandi: ";
            cin >> password;

            currentUser = loginUser(users, username, password);

            if (currentUser != nullptr)
            {

                cout << "Login berhasil. Selamat datang, " << username << "!" << endl;

                if (currentUser->isAdmin)
                {
                    this_thread::sleep_for(chrono::seconds(1));
                    system("cls");
                    menuadmin(head);
                }
                else
                {
                    this_thread::sleep_for(chrono::seconds(1));
                    system("cls");
                    menuuser(head);
                }
            }
            else
            {
                cout << "Login gagal. Silakan coba lagi." << endl;
            }
            break;
        }
        case 2:
        {
            string username, password;
            cout << "Masukkan nama pengguna baru: ";
            cin >> username;
            cout << "Masukkan kata sandi baru: ";
            cin >> password;
            registerUser(users, username, password, false);
            break;
        }
        case 3:
            cout << "Terima kasih. Sampai jumpa!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }

        this_thread::sleep_for(chrono::seconds(3));
        system("cls");
        processRegistrationQueue(users);

    } while (choice != 3);

    // Membersihkan memori
    while (users != nullptr)
    {
        User *temp = users;
        users = users->next;
        delete temp;
    }

    return 0;
}