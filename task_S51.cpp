#include <iostream>
#include <string>

void reverse(const std::string& s) {
    for (int i = s.length() - 1; i >= 0; --i) {
        std::cout << s[i];
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);  // позволяет вводить строки с пробелами

    reverse(input);
    return 0;
}
