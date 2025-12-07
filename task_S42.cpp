#include <iostream>
using namespace std;

// Функция сортировки по убыванию (пузырьковая сортировка)
void sort(int arr[10]) {
    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = 0; j < 10 - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) { // Обратите внимание: < для убывания
                // Меняем местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a[10];

    cout << "Введите 10 целых чисел: ";
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }

    // Либо использовать пример из задания:
    // int a[10] = {1, 8, 3, 6, 5, 4, 9, 2, 8, 12};

    sort(a);

    cout << "Отсортированный массив по убыванию: ";
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
