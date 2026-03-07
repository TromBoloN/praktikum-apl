#include <iostream>
using namespace std;

struct Menu
{
    string nama;
    int harga;
    bool tersedia;
};

int main()
{

    Menu daftarMenu[3] = {
        {"Nasi Goreng", 15000, true},
        {"Mie Ayam", 12000, true},
        {"Es Teh", 5000, false}};

    cout << "=== DAFTAR MENU KANTIN ===\n\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "Menu ke-" << i + 1 << endl;
        cout << "Nama     : " << daftarMenu[i].nama << endl;
        cout << "Harga    : Rp" << daftarMenu[i].harga << endl;

        cout << "Status   : ";
        if (daftarMenu[i].tersedia)
        {
            cout << "Tersedia";
        }
        else
        {
            cout << "Habis";
        }

        cout << "\n-------------------------\n";
    }

    return 0;
}