#include <iostream>
#include <fstream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    std::ifstream f("output.txt");
    int num, n = 1;

    while (f >> num) {
        std::cout << n << ". Число: " << num << "\n";
        ++n;
    }

    return 0;
}
