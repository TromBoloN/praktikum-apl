#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct dataReview
{
    string namaUser;
    string isiReview;
};

struct dataBuku
{
    string judulBuku;
    string penulisBuku;

    dataReview reviewBuku[10];
    int jumlahReview = 0;
};

struct dataUser
{
    string nama;
    string nim;
    string role;
};

int main()
{
    dataUser akun[100] = {
        {"arif", "064", "user"},
        {"admin", "123", "admin"}};

    dataBuku daftarBuku[100] = {
        {"Laskar Pelangi", "Andrea Hirata"},
        {"Bumi", "Tere Liye"},
        {"Negeri 5 Menara", "Ahmad Fuadi"},
        {"Dilan 1990", "Pidi Baiq"},
        {"Ayat-Ayat Cinta", "Habiburrahman El Shirazy"}};

    int jumlahBuku = 5;
    int jumlahUser = 2;

    int pilihanUtama;
    int pilihanMenu;
    int percobaanLogin;
    int indexBuku;

    string inputNama;
    string inputNim;

    int indexLogin = -1;

    while (true)
    {
        system("cls");
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihanUtama;
        cin.ignore();
        system("cls");

        if (pilihanUtama == 3)
        {
            break;
        }

        if (pilihanUtama == 2)
        {
            cout << "\n===== REGISTER USER =====\n";

            cout << "Nama Baru: ";
            getline(cin, akun[jumlahUser].nama);

            cout << "NIM Baru: ";
            getline(cin, akun[jumlahUser].nim);

            akun[jumlahUser].role = "user";
            jumlahUser++;

            cout << "\nAkun berhasil dibuat! Silakan login.\n";
            cout << "Tekan Enter untuk kembali...";
            cin.get();
            continue;
        }

        if (pilihanUtama == 1)
        {
            for (percobaanLogin = 0; percobaanLogin < 3; percobaanLogin++)
            {
                cout << "\nLOGIN\n";

                cout << "Nama: ";
                getline(cin, inputNama);

                cout << "NIM: ";
                getline(cin, inputNim);

                indexLogin = -1;

                for (int i = 0; i < jumlahUser; i++)
                {
                    if (inputNama == akun[i].nama &&
                        inputNim == akun[i].nim)
                    {
                        indexLogin = i;
                        break;
                    }
                }

                if (indexLogin != -1)
                {
                    system("cls");
                    break;
                }

                cout << "Login gagal! Sisa percobaan: "
                     << 2 - percobaanLogin << endl;
            }

            if (percobaanLogin == 3)
            {
                return 0;
            }

            do
            {
                if (akun[indexLogin].role == "admin")
                {
                    system("cls");
                    cout << "\n======= MENU ADMIN =======\n";
                    cout << "1. Tambah Buku\n";
                    cout << "2. Lihat Buku\n";
                    cout << "3. Ubah Buku\n";
                    cout << "4. Hapus Buku\n";
                    cout << "5. Logout\n";
                    cout << "Pilihan: ";
                    cin >> pilihanMenu;
                    cin.ignore();
                    cout << "\n";

                    if (pilihanMenu == 1)
                    {
                        cout << "Judul Buku: ";
                        getline(cin, daftarBuku[jumlahBuku].judulBuku);

                        cout << "Penulis Buku: ";
                        getline(cin, daftarBuku[jumlahBuku].penulisBuku);

                        jumlahBuku++;
                    }

                    else if (pilihanMenu == 2)
                    {
                        cout << "===== Daftar Buku =====\n";
                        for (int i = 0; i < jumlahBuku; i++)
                        {
                            cout << i + 1 << ". "
                                 << daftarBuku[i].judulBuku
                                 << " | Karya : "
                                 << daftarBuku[i].penulisBuku << endl;
                        }

                        cout << "\nTekan Enter untuk lanjut...";
                        cin.get();
                    }

                    else if (pilihanMenu == 3)
                    {
                        for (int i = 0; i < jumlahBuku; i++)
                        {
                            cout << i + 1 << ". "
                                 << daftarBuku[i].judulBuku << endl;
                        }

                        cout << "Nomor Buku: ";
                        cin >> indexBuku;
                        cin.ignore();
                        indexBuku--;

                        cout << "Judul Baru: ";
                        getline(cin, daftarBuku[indexBuku].judulBuku);
                    }

                    else if (pilihanMenu == 4)
                    {
                        for (int i = 0; i < jumlahBuku; i++)
                        {
                            cout << i + 1 << ". "
                                 << daftarBuku[i].judulBuku << endl;
                        }

                        cout << "Nomor Buku: ";
                        cin >> indexBuku;
                        cin.ignore();
                        indexBuku--;

                        for (int i = indexBuku; i < jumlahBuku - 1; i++)
                        {
                            daftarBuku[i] = daftarBuku[i + 1];
                        }

                        jumlahBuku--;
                    }

                    else
                    {
                        cout << "Input tidak valid\n";
                        cin.get();
                    }
                }

                else if (akun[indexLogin].role == "user")
                {
                    system("cls");
                    cout << "\n======= MENU USER =======\n";
                    cout << "1. Isi Review\n";
                    cout << "2. Lihat Semua Review\n";
                    cout << "3. Logout\n";
                    cout << "Pilihan: ";
                    cin >> pilihanMenu;
                    cin.ignore();

                    if (pilihanMenu == 1)
                    {
                        for (int i = 0; i < jumlahBuku; i++)
                        {
                            cout << i + 1 << ". "
                                 << daftarBuku[i].judulBuku << endl;
                        }

                        cout << "Pilih Nomor Buku: ";
                        cin >> indexBuku;
                        cin.ignore();

                        if (indexBuku < 1 || indexBuku > jumlahBuku)
                        {
                            cout << "Nomor buku tidak ada!\n";
                            cin.get();
                            continue;
                        }

                        indexBuku--;

                        int r = daftarBuku[indexBuku].jumlahReview;

                        cout << "Nama: ";
                        getline(cin, daftarBuku[indexBuku].reviewBuku[r].namaUser);

                        cout << "Review: ";
                        getline(cin, daftarBuku[indexBuku].reviewBuku[r].isiReview);

                        daftarBuku[indexBuku].jumlahReview++;
                    }

                    else if (pilihanMenu == 2)
                    {
                        system("cls");

                        for (int i = 0; i < jumlahBuku; i++)
                        {
                            cout << i + 1 << ". "
                                 << daftarBuku[i].judulBuku << endl;

                            if (daftarBuku[i].jumlahReview == 0)
                            {
                                cout << " Belum ada review.\n";
                            }
                            else
                            {
                                for (int j = 0; j < daftarBuku[i].jumlahReview; j++)
                                {
                                    cout << " User: "
                                         << daftarBuku[i].reviewBuku[j].namaUser << endl;

                                    cout << " Review: "
                                         << daftarBuku[i].reviewBuku[j].isiReview << endl;
                                }
                            }

                            cout << "======================================\n";
                        }

                        cout << "Tekan Enter untuk kembali...";
                        cin.get();
                    }

                    else if (pilihanMenu == 3)
                    {
                        break;
                    }

                    else
                    {
                        cout << "Input tidak valid\n";
                        cin.get();
                    }
                }

            } while ((akun[indexLogin].role == "admin" && pilihanMenu != 5) ||
                     (akun[indexLogin].role == "user" && pilihanMenu != 3));
        }
    }

    return 0;
}