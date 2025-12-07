#include <iostream>
#include <iomanip>  

double squared_sum(double a, double b) {
    double sum = a + b;
    return sum * sum;  // или (a + b) * (a + b)
}

int main() {
    setlocale(LC_ALL, "Russian");
    double x, y;
    std::cout << "Введите два дробных числа: ";
    std::cin >> x >> y;

    double result = squared_sum(x, y);
    std::cout << result << "\n";

    return 0;
}
