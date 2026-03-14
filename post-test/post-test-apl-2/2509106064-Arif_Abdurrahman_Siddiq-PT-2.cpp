#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Review
{
    string teksReview;
    float rating;
    string reviewer;
};

struct Buku
{
    string judul;
    string penulis;
    string genre;
    Review detail;
};

int main()
{
    struct User
    {
        string username;
        string password;
    } admin = {"arif", "064"};

    Buku daftarBuku[100] = {
        {"Harry Potter", "J.K. Rowling", "Fantasy", {"-", 0, "-"}},
        {"Solo Leveling", "Chugong", "Action", {"-", 0, "-"}},
        {"Lord of the Rings", "J.R.R Tolkien", "Fantasy", {"-", 0, "-"}},
        {"The Devotion of Suspect X", "Keigo Higashino", "Crime Fiction", {"-", 0, "-"}},
        {"Wuthering Heights", "Emily Bronte", "Romance", {"-", 0, "-"}},
        {"The Metamorphosis", "Franz Kafka", "Absurdist Fiction", {"-", 0, "-"}}};

    int jumlahData = 6;

    string userInput, pwInput;
    int percobaanLogin = 0;
    bool loginBerhasil = false;

    while (percobaanLogin < 3)
    {
        cout << "=== LOGIN SISTEM REVIEW BUKU ===" << endl;
        cout << "Masukkan Nama : ";
        cin >> userInput;
        cout << "Masukkan NIM : ";
        cin >> pwInput;

        if (userInput == admin.username && pwInput == admin.password)
        {
            loginBerhasil = true;
            break;
        }
        else
        {
            percobaanLogin++;
            cout << "Login Gagal. Sisa Percobaan: " << 3 - percobaanLogin << "\n"
                 << endl;
        }
    }

    if (!loginBerhasil)
    {
        cout << "Melebihi batas login. Program berhenti." << endl;
        return 0;
    }

    int pilihan;

    while (true)
    {
        system("cls");
        cout << "\n======================================" << endl;
        cout << "   SISTEM REVIEW BUKU & FANFICTION   " << endl;
        cout << "======================================" << endl;
        cout << "1. Tambah Review" << endl;
        cout << "2. Lihat Review" << endl;
        cout << "3. Ubah Review" << endl;
        cout << "4. Hapus Review" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih Menu 1-5: ";
        cin >> pilihan;

        if (pilihan == 5)
        {
            cout << "Keluar dari sistem." << endl;
            break;
        }

        switch (pilihan)
        {

        case 1:
        {
            system("cls");
            cout << "\n==== DAFTAR BUKU TERSEDIA ====" << endl;

            for (int i = 0; i < jumlahData; i++)
            {
                cout << i + 1 << ". "
                     << daftarBuku[i].judul
                     << " - " << daftarBuku[i].penulis
                     << " (" << daftarBuku[i].genre << ")"
                     << endl;
            }

            int pilihBuku;
            cout << "Pilih nomor buku untuk direview: ";
            cin >> pilihBuku;
            float rating;

            if (pilihBuku > 0 && pilihBuku <= jumlahData)
            {
                cin.ignore();

                cout << "Tulis review : ";
                getline(cin, daftarBuku[pilihBuku - 1].detail.teksReview);

                cout << "Rating (1-5) : ";
                cin >> rating;
                while (rating < 0 || rating > 5)
                {
                    cout << "Rating harus antara 0 sampai 5!" << endl;
                    cout << "Masukkan rating lagi : ";
                    cin >> rating;
                }

                daftarBuku[pilihBuku - 1].detail.rating = rating;
                daftarBuku[pilihBuku - 1].detail.reviewer = userInput;
                cout << "Review berhasil ditambahkan" << endl;
            }
            else
            {
                cout << "Pilihan tidak ada" << endl;
            }

            break;
        }

        case 2:
        {
            cout << "\n==== DAFTAR REVIEW ====\n";

            cout << left
                 << setw(5) << "No"
                 << setw(25) << "Judul"
                 << setw(20) << "Penulis"
                 << setw(12) << "Genre"
                 << setw(8) << "Rating"
                 << setw(15) << "Reviewer"
                 << setw(30) << "Review"
                 << endl;

            for (int i = 0; i < jumlahData; i++)
            {
                cout << left
                     << setw(5) << i + 1
                     << setw(25) << daftarBuku[i].judul
                     << setw(20) << daftarBuku[i].penulis
                     << setw(12) << daftarBuku[i].genre
                     << setw(8) << daftarBuku[i].detail.rating
                     << setw(15) << daftarBuku[i].detail.reviewer
                     << setw(30) << daftarBuku[i].detail.teksReview
                     << endl;
            }
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            system("cls");

            break;
        }

        case 3:
        {
            int indexUpdate;

            cout << "\nNomor buku yang reviewnya ingin diubah: ";
            cin >> indexUpdate;
            float rating;

            if (indexUpdate > 0 && indexUpdate <= jumlahData)
            {
                if (daftarBuku[indexUpdate - 1].detail.reviewer == userInput)
                {
                    cin.ignore();

                    cout << "Review baru : ";
                    getline(cin, daftarBuku[indexUpdate - 1].detail.teksReview);

                    cout << "Rating baru : ";
                    cin >> rating;
                    while (rating < 0 || rating > 5)
                    {
                        cout << "Rating harus antara 0 sampai 5!" << endl;
                        cout << "Masukkan rating lagi : ";
                        cin >> rating;
                    }

                    daftarBuku[indexUpdate - 1].detail.rating = rating;
                    cout << "Review berhasil diperbarui." << endl;
                }
                else
                {
                    cout << "Hanya bisa menghapus rating sendiri" << endl;
                }
            }
            else
            {
                cout << "Nomor tidak valid." << endl;
            }

            break;
        }

        case 4:
        {
            int indexHapus;

            cout << "\nNomor data yang akan dihapus: ";
            cin >> indexHapus;

            if (indexHapus > 0 && indexHapus <= jumlahData)
            {
                if (daftarBuku[indexHapus - 1].detail.reviewer == userInput)
                {
                    daftarBuku[indexHapus - 1].detail.teksReview = "-";
                    daftarBuku[indexHapus - 1].detail.rating = 0;
                    daftarBuku[indexHapus - 1].detail.reviewer = "-";

                    cout << "Review berhasil dihapus." << endl;
                }
                else
                {
                    cout << "Hanya bisa menghapus review sendiri." << endl;
                }
            }
            else
            {
                cout << "Nomor data tidak ada" << endl;
            }

            break;
        }

        default:
            cout << "Pilihan diketahui" << endl;
        }
    }

    return 0;
}