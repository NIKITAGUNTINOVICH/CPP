#include <iostream>
#include <iomanip>  // для setw (опционально, но улучшает выравнивание)

int main() {
    // Заголовок (1–10)
    std::cout << "\t";  // пустая клетка в левом верхнем углу
    for (int j = 1; j <= 10; ++j) {
        std::cout << j << "\t";
    }
    std::cout << "\n";

    // Строки таблицы
    for (int i = 1; i <= 10; ++i) {
        std::cout << i << "\t";  // метка строки
        for (int j = 1; j <= 10; ++j) {
            std::cout << i * j << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
