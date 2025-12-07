#include <iostream>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int a = 10;
    double b = 3.5;
    float c = 2.0f;
    long d = 100;

    cout << "Сложение (int + double): " << a << " + " << b << " = " << (a + b) << endl;
    cout << "Вычитание (long - int): " << d << " - " << a << " = " << (d - a) << endl;
    cout << "Умножение (double * float): " << b << " * " << c << " = " << (b * c) << endl;
    cout << "Деление (long / int): " << d << " / " << a << " = " << (static_cast<double>(d) / a) << endl;

    return 0;
}
