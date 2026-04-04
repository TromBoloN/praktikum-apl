#include <iostream>
using namespace std;

struct Menu
{
    string nama;
    float harga;
};

int main()
{
    // string var = "Hey";
    // string *ptr = &var;
    // *ptr = "Tes";
    // cout << ptr << ": Alamatnya\n";
    // cout << *ptr << ": Hasil alamatnya";

    Menu nasgor;
    Menu *nasgorPtr = &nasgor;

    nasgor.nama = "Nasi Goreng Cumi Hitam Pak Kris";
    nasgor.harga = 15000;
    cout << nasgor.nama << " " << nasgor.harga << endl;

    nasgorPtr->nama = "Nasi Goreng Mawut";
    nasgorPtr->harga = 13000;

    cout << nasgor.nama << " " << nasgor.harga << endl;
    return 0;
}