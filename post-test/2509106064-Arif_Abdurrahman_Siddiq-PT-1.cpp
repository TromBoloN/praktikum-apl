#include <iostream>
#include <string>
using namespace std;

int main()
{
    string username = "arif";
    string password = "064";
    string userLogin, passLogin;
    int cobaLogin = 0;
    bool loginBerhasil = false;

    cout << "========= PROGRAM KONVERSI WAKTU =========\n";
    while (cobaLogin < 3 && loginBerhasil == false)
    {
        cout << "\n======== LOGIN ========\n";
        cout << "Nama : ";
        cin >> userLogin;
        cout << "Password : ";
        cin >> passLogin;

        if (userLogin == username && passLogin == password)
        {
            loginBerhasil = true;
            cout << "\nLogin berhasil. Selamat datang, " << userLogin << "\n";
        }
        else
        {
            cobaLogin++;
            cout << "\nLogin gagal. Percobaan: " << cobaLogin;
        }
    }
    if (loginBerhasil == false)
    {
        cout << "\nTerlalu banyak percobaan.\n";
        return 0;
    }

    int menu;
    double inputWaktu;
    do
    {
        cout << "\n=========== MENU UTAMA ===========\n";
        cout << "\n1. Konversi Jam   -> Menit dan Detik\n";
        cout << "2. Konversi Menit -> Jam dan Detik\n";
        cout << "3. Konversi Detik -> Jam dan Menit\n";
        cout << "4. Keluar\n";
        cout << "\n==================================\n";
        cout << "Pilih menu (1-4): ";
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            cout << "\nMasukkan Jam: ";
            cin >> inputWaktu;
            double menit = inputWaktu * 60;
            double detik = inputWaktu * 3600;

            cout << "\n======== HASIL KONVERSI ========\n";
            cout << inputWaktu << " Jam = " << menit << " Menit dan " << detik << " Detik\n";
            break;
        }
        case 2:
        {
            cout << "\nMasukkan Menit: ";
            cin >> inputWaktu;
            double jam = inputWaktu / 60;
            double detik = inputWaktu * 60;

            cout << "\n======== HASIL KONVERSI ========\n";
            cout << inputWaktu << " Menit = " << jam << " Jam dan " << detik << " Detik\n";
            break;
        }
        case 3:
        {
            cout << "\nMasukkan Detik: ";
            cin >> inputWaktu;
            double jam = inputWaktu / 3600;
            double menit = inputWaktu / 60;

            cout << "\n======== HASIL KONVERSI ========\n";
            cout << inputWaktu << " Detik = " << jam << " Jam dan " << menit << " Menit\n";
            break;
        }
        case 4:
        {
            cout << "\nBerhasil keluar. program akan berhenti.\n";
            break;
        }
        default:
        {
            cout << "\nInput tidak valid. Pilih 1-4.\n";
            break;
        }
        }

    } while (menu != 4);
    return 0;
}