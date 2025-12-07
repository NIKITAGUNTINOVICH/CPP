#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");

    std::string digits[10] = {"ноль", "один", "два", "три", "четыре",
                               "пять", "шесть", "семь", "восемь", "девять"};
    int n;
    std::cin >> n;

    if (n >= 0 && n <= 9)
        std::cout << digits[n] << std::endl;
    else
        std::cout << "Число вне диапазона 0–9\n";

    return 0;
}
