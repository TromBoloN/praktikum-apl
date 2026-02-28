#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    // Tes
    int umur;
    string name;
    cout << "Hello World " << name << endl;
    cout << "Masukkan Namamu";
    getline(cin, name);
    cout << "Ohh umur mu ini ya " << name << endl;

    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of long: " << sizeof(long);

    return 0;
}
