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

struct User
{
    string username;
    string password;
};

void barisRapi(int n)
{
    for (int i = 0; i < n; i++)
        cout << "=";
    cout << endl;
}

void tampilBuku(Buku buku[], int index, int jumlah) // Rekursif ini
{
    if (index == jumlah)
        return;

    cout << index + 1 << ". "
         << buku[index].judul << " - "
         << buku[index].penulis << " ("
         << buku[index].genre << ")" << endl;

    tampilBuku(buku, index + 1, jumlah);
}

bool login(User admin, string &username)
{
    string password;
    int percobaan = 0;

    while (percobaan < 3)
    {
        cout << "=== LOGIN SISTEM REVIEW BUKU ===" << endl;
        cout << "Masukkan Nama : ";
        cin >> username;
        cout << "Masukkan NIM : ";
        cin >> password;

        if (username == admin.username && password == admin.password)
            return true;

        percobaan++;
        cout << "Login Gagal. Sisa Percobaan: " << 3 - percobaan << endl
             << endl;
    }

    return false;
}

void tambahReview(Buku buku[], int jumlahData, string user)
{
    system("cls");

    cout << "==== DAFTAR BUKU TERSEDIA ====" << endl;

    tampilBuku(buku, 0, jumlahData);

    int pilih;
    cout << "Pilih nomor buku: ";
    cin >> pilih;

    if (pilih < 1 || pilih > jumlahData)
    {
        cout << "Pilihan tidak ada" << endl;
        return;
    }

    cin.ignore();

    cout << "Tulis review: ";
    getline(cin, buku[pilih - 1].detail.teksReview);

    float rating;
    cout << "Rating (1-5): ";
    cin >> rating;

    while (rating < 0 || rating > 5)
    {
        cout << "Rating harus 0-5: ";
        cin >> rating;
    }

    buku[pilih - 1].detail.rating = rating;
    buku[pilih - 1].detail.reviewer = user;

    cout << "Review berhasil ditambahkan\n";
}

void lihatReview(Buku buku[], int jumlahData)
{
    cout << "\n==== DAFTAR REVIEW ====\n";

    cout << left
         << setw(5) << "No"
         << setw(35) << "Judul"
         << setw(20) << "Penulis"
         << setw(20) << "Genre"
         << setw(8) << "Rating"
         << setw(15) << "Reviewer"
         << setw(30) << "Review"
         << endl;

    for (int i = 0; i < jumlahData; i++)
    {
        cout << left
             << setw(5) << i + 1
             << setw(35) << buku[i].judul
             << setw(20) << buku[i].penulis
             << setw(20) << buku[i].genre
             << setw(8) << buku[i].detail.rating
             << setw(15) << buku[i].detail.reviewer
             << setw(30) << buku[i].detail.teksReview
             << endl;
    }
}

void ubahReview(Buku buku[], int jumlahData, string user)
{
    int index;

    cout << "Nomor buku: ";
    cin >> index;

    if (index < 1 || index > jumlahData)
    {
        cout << "Nomor tidak valid\n";
        return;
    }

    if (buku[index - 1].detail.reviewer != user)
    {
        cout << "Hanya bisa edit review sendiri\n";
        return;
    }

    cin.ignore();

    cout << "Review baru: ";
    getline(cin, buku[index - 1].detail.teksReview);

    float rating;
    cout << "Rating baru: ";
    cin >> rating;

    while (rating < 0 || rating > 5)
    {
        cout << "Rating harus 0-5: ";
        cin >> rating;
    }

    buku[index - 1].detail.rating = rating;

    cout << "Review berhasil diperbarui\n";
}

void hapusReview(Buku buku[], int jumlahData, string user)
{
    int index;

    cout << "Nomor buku: ";
    cin >> index;

    if (index < 1 || index > jumlahData)
    {
        cout << "Nomor tidak ada\n";
        return;
    }

    if (buku[index - 1].detail.reviewer != user)
    {
        cout << "Hanya bisa hapus review sendiri\n";
        return;
    }

    buku[index - 1].detail.teksReview = "-";
    buku[index - 1].detail.rating = 0;
    buku[index - 1].detail.reviewer = "-";

    cout << "Review berhasil dihapus\n";
}

int main()
{
    User admin = {"arif", "064"};

    Buku daftarBuku[100] =
        {
            {"Harry Potter", "J.K. Rowling", "Fantasy", {"-", 0, "-"}},
            {"Solo Leveling", "Chugong", "Action", {"-", 0, "-"}},
            {"Lord of the Rings", "J.R.R Tolkien", "Fantasy", {"-", 0, "-"}},
            {"The Devotion of Suspect X", "Keigo Higashino", "Crime Fiction", {"-", 0, "-"}},
            {"Wuthering Heights", "Emily Bronte", "Romance", {"-", 0, "-"}},
            {"The Metamorphosis", "Franz Kafka", "Absurdist Fiction", {"-", 0, "-"}}};

    int jumlahData = 6;

    string user;

    if (!login(admin, user))
    {
        cout << "Login gagal 3x. Program berhenti.";
        return 0;
    }

    int pilih;

    do
    {
        system("cls");

        barisRapi(38);
        cout << "SISTEM REVIEW BUKU\n";
        barisRapi(38);

        cout << "1. Tambah Review\n";
        cout << "2. Lihat Review\n";
        cout << "3. Ubah Review\n";
        cout << "4. Hapus Review\n";
        cout << "5. Keluar\n";

        cout << " Pilih 1-5: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            tambahReview(daftarBuku, jumlahData, user);
            break;

        case 2:
            lihatReview(daftarBuku, jumlahData);
            cout << "\nTekan enter...";
            cin.ignore();
            cin.get();
            break;

        case 3:
            lihatReview(daftarBuku, jumlahData);
            ubahReview(daftarBuku, jumlahData, user);
            break;

        case 4:
            lihatReview(daftarBuku, jumlahData);
            hapusReview(daftarBuku, jumlahData, user);
            break;
        }

    } while (pilih != 5);
}