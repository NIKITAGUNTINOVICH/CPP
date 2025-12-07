#include <iostream>
using namespace std;

class Bucket {
public:
    int volume;  // объем ведра в литрах
    int used;    // сколько литров уже налито

    Bucket(int vol, int us = 0) : volume(vol), used(us) {
        // Гарантируем, что used не превышает volume
        if (used > volume) {
            used = volume;
        }
    }

    // Метод для опустошения ведра
    void flush() {
        used = 0;
    }

    // Метод для наполнения ведра
    int fill(int v) {
        // Вычисляем доступный объем
        int available = volume - used;

        // Если достаточно места
        if (available >= v) {
            used += v;
            return 0;  // вся жидкость поместилась
        }
        // Если недостаточно места
        else {
            used = volume;  // заполняем полностью
            return v - available;  // возвращаем остаток
        }
    }
};

int main() {
    // ПРОВерка тест кодом
    Bucket test_01(12, 3);
    cout << "1) " << test_01.volume << ", " << test_01.used << "\n"; // 12, 3

    int rest = test_01.fill(14);
    cout << "2) " << test_01.used << ", " << rest << "\n";  // 12, 5

    test_01.flush();
    rest = test_01.fill(8);
    cout << "3) " << test_01.used << ", " << rest << "\n";   // 8, 0

    return 0;
}
