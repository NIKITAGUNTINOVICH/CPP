#include <iostream>
using namespace std;

int main() {
    int a = 17;
    int b = 5;

    cout << "a / b = " << a / b << endl;   // 3
    cout << "a % b = " << a % b << endl;   // 2

    // Отрицательные числа
    int c = -17;
    int d = 5;

    cout << "c / d = " << c / d << endl;   // -3 (округление к нулю!)
    cout << "c % d = " << c % d << endl;   // -2

    // Важно: знак остатка совпадает со знаком делимого (a % b)
    cout << "17 % -5 = " << 17 % -5 << endl;   // 2
    cout << "-17 % -5 = " << -17 % -5 << endl; // -2

    return 0;
}
