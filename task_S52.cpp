#include <iostream>

// 1) int
void print(int a) {
    std::cout << a << '\n';
}

// 2) float
void print(float a) {
    std::cout << a << '\n';
}

// 3) char
void print(char a) {
    std::cout << a << '\n';
}

// 4) int и int
void print(int a, int b) {
    std::cout << a << ' ' << b << '\n';
}

// --- Проверка ---
int main() {
    print(42);          // → 42
    print(3.14f);       // → 3.14
    print('A');         // → A
    print(10, 20);      // → 10 20

    return 0;
}
