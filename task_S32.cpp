#include <iostream>
#include <cstring>
#include <cctype>

int main() {
    setlocale(LC_ALL, "Russian");
    char str[1000]; //

    std::cout << "Введите строку: ";
    std::cin.getline(str, sizeof(str)); // Ввод строки с пробелами

    int len = strlen(str);

    // Проходим по строке с помощью указателя
    for (char* p = str; *p != '\0'; ++p) {
        if (*p >= 'a' && *p <= 'z') {
            // Строчные буквы a-z
            *p = (*p == 'z') ? 'a' : *p + 1;
        } else if (*p >= 'A' && *p <= 'Z') {
            // Заглавные буквы A-Z
            *p = (*p == 'Z') ? 'A' : *p + 1;
        }
        // Не буквы остаются без изменений
    }

    std::cout << "Результат: " << str << std::endl;

    return 0;
}
