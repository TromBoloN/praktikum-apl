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
    string *username;
    string *password;
};

void barisRapi(int n)
{
    for (int i = 0; i < n; i++)
        cout << "=";
    cout << endl;
}

void tampilBuku(Buku buku[], int index, int jumlah)
{
    if (index == jumlah)
        return;

    cout << index + 1 << ". "
         << buku[index].judul << " - "
         << buku[index].penulis << " ("
         << buku[index].genre << ")" << endl;

    tampilBuku(buku, index + 1, jumlah);
}

bool login(User *admin, string &username)
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

        if (username == *admin->username && password == *admin->password)
            return true;

        percobaan++;
        cout << "Login Gagal. Sisa Percobaan: " << 3 - percobaan << endl
             << endl;
    }

    return false;
}

// 1. Sorting Huruf desc (Judul)
void sortJudulDesc(Buku buku[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (buku[j].judul < buku[j + 1].judul)
                swap(buku[j], buku[j + 1]);
        }
    }
}

// 2. Sorting Angka asc (Rating)
void sortRatingAsc(Buku buku[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (buku[j].detail.rating > buku[j + 1].detail.rating)
                swap(buku[j], buku[j + 1]);
        }
    }
}

// 3. Sorting Bebas (Judul ASC)
void sortJudulAsc(Buku buku[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (buku[j].judul > buku[j + 1].judul)
                swap(buku[j], buku[j + 1]);
        }
    }
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
         << setw(28) << "Judul"
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
             << setw(28) << buku[i].judul
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
    string adminUser = "arif";
    string adminPass = "064";
    User admin = {&adminUser, &adminPass};

    Buku daftarBuku[] =
        {
            {"Harry Potter", "J.K Rowling", "Fantasy", {"Seru banget", 5, "Budi"}},
            {"Solo Leveling", "Chugong", "Action", {"Overpowered tapi keren", 4.5, "Andi"}},
            {"Lord of the Rings", "Tolkien", "Fantasy", {"Klasik epic", 5, "Rina"}},
            {"The Hobbit", "Tolkien", "Fantasy", {"Petualangan santai", 4, "Sari"}},
            {"Attack on Titan", "Isayama", "Action", {"Plot twist gila", 5, "Doni"}},
            {"Death Note", "Tsugumi Ohba", "Thriller", {"Mind game keren", 4.8, "Rizky"}},
            {"Naruto", "Masashi Kishimoto", "Action", {"Nostalgia", 4.2, "Fajar"}},
            {"One Piece", "Oda", "Adventure", {"Dunia luas banget", 5, "Asep"}},
            {"Tokyo Ghoul", "Ishida", "Dark", {"Agak sedih", 4, "Dewi"}},
            {"Demon Slayer", "Gotouge", "Action", {"Visual bagus", 4.3, "Lina"}}};

    int jumlahData = sizeof(daftarBuku) / sizeof(daftarBuku[0]);
    string user;

    if (!login(&admin, user))
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
        cout << "5. Sorting\n";
        cout << "6. Keluar\n";

        cout << "Pilih 1-6: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            tambahReview(daftarBuku, jumlahData, user);
            break;

        case 2:
            lihatReview(daftarBuku, jumlahData);
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

        case 5:
        {
            int pilihSort;
            do
            {
                system("cls");

                cout << "\n=== MENU SORTING ===\n";
                cout << "1. Judul DESC\n";
                cout << "2. Rating ASC\n";
                cout << "3. Judul ASC\n";
                cout << "4. Kembali\n";
                cout << "Pilih: ";
                cin >> pilihSort;

                switch (pilihSort)
                {
                case 1:
                    sortJudulDesc(daftarBuku, jumlahData);
                    break;

                case 2:
                    sortRatingAsc(daftarBuku, jumlahData);
                    break;

                case 3:
                    sortJudulAsc(daftarBuku, jumlahData);
                    break;

                case 4:
                    break;

                default:
                    cout << "Pilihan tidak valid\n";
                }

                if (pilihSort >= 1 && pilihSort <= 3)
                {
                    cout << "\nSetelah Sorting:\n";
                    lihatReview(daftarBuku, jumlahData);

                    cin.ignore();
                    cin.get();
                }

            } while (pilihSort != 4);

            break;
        }
        }

    } while (pilih != 6);
}