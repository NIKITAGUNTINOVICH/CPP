#include <iostream>
#include <locale>
using namespace std;

class CreditCard {
public:
    int Number;     // номер карты (4 цифры)
    float Balance;  // баланс карты

    // Конструктор
    CreditCard(int num, float bal) : Number(num), Balance(bal) {
        // Проверяем, что номер состоит из 4 цифр
        if (num < 1000 || num > 9999) {
            cout << "Внимание: номер карты должен состоять из 4 цифр!" << endl;
        }
    }

    // Метод для пополнения баланса
    void Put(float amount) {
        if (amount > 0) {
            Balance += amount;
            cout << "На карту " << Number << " внесено: " << amount
                 << " руб. Новый баланс: " << Balance << " руб." << endl;
        } else {
            cout << "Ошибка: сумма пополнения должна быть положительной!" << endl;
        }
    }

    // Метод для снятия денег
    void Take(float amount) {
        if (amount <= 0) {
            cout << "Ошибка: сумма снятия должна быть положительной!" << endl;
        } else if (amount > Balance) {
            cout << "Ошибка: недостаточно средств на карте " << Number
                 << "! Запрашиваемая сумма: " << amount
                 << " руб., доступно: " << Balance << " руб." << endl;
        } else {
            Balance -= amount;
            cout << "С карты " << Number << " снято: " << amount
                 << " руб. Новый баланс: " << Balance << " руб." << endl;
        }
    }

    // Метод для отображения информации о карте
    void Display() const {
        cout << "Карта №" << Number << ", баланс: " << Balance << " руб." << endl;
    }
};

// Функция для перевода денег между картами
void Transfer(CreditCard& C1, CreditCard& C2, float V) {
    cout << "\n=== Попытка перевода " << V << " руб. с карты №"
         << C1.Number << " на карту №" << C2.Number << " ===" << endl;

    // Проверка: не перевод на ту же карту
    if (C1.Number == C2.Number) {
        cout << "Ошибка: это одна и та же карта! Перевод невозможен." << endl;
        return;
    }

    // Проверка: положительная сумма перевода
    if (V <= 0) {
        cout << "Ошибка: сумма перевода должна быть положительной!" << endl;
        return;
    }

    // Проверка: достаточно ли средств на карте-отправителе
    if (C1.Balance < V) {
        cout << "Ошибка перевода: недостаточно средств на карте №" << C1.Number << endl;
        cout << "Запрашиваемая сумма: " << V << " руб." << endl;
        cout << "Доступно: " << C1.Balance << " руб." << endl;
        return;
    }

    // Выполнение перевода
    float oldBalanceC1 = C1.Balance;
    float oldBalanceC2 = C2.Balance;

    C1.Balance -= V;  // Снимаем с карты-отправителя
    C2.Balance += V;  // Зачисляем на карту-получателя

    cout << "Перевод успешно выполнен!" << endl;
    cout << "Карта №" << C1.Number << ": " << oldBalanceC1 << " → " << C1.Balance << " руб." << endl;
    cout << "Карта №" << C2.Number << ": " << oldBalanceC2 << " → " << C2.Balance << " руб." << endl;
}

int main() {
    // Установка локали для корректного отображения кириллицы
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Создание нескольких карт для демонстрации
    cout << "=== СОЗДАНИЕ КАРТ ===" << endl;
    CreditCard card1(1234, 500);
    CreditCard card2(5678, 300);
    CreditCard card3(9012, 100);

    card1.Display();
    card2.Display();
    card3.Display();

    // Демонстрация работы функции Transfer

    cout << "\n=== ТЕСТ 1: Успешный перевод ===" << endl;
    Transfer(card1, card2, 200);
    card1.Display();
    card2.Display();

    cout << "\n=== ТЕСТ 2: Перевод на ту же карту ===" << endl;
    Transfer(card1, card1, 50);

    cout << "\n=== ТЕСТ 3: Недостаточно средств ===" << endl;
    Transfer(card3, card1, 500);

    cout << "\n=== ТЕСТ 4: Отрицательная сумма перевода ===" << endl;
    Transfer(card1, card2, -100);

    cout << "\n=== ТЕСТ 5: Нулевая сумма перевода ===" << endl;
    Transfer(card1, card2, 0);

    cout << "\n=== ТЕСТ 6: Еще один успешный перевод ===" << endl;
    Transfer(card2, card3, 150);

    cout << "\n=== ФИНАЛЬНЫЕ БАЛАНСЫ ===" << endl;
    card1.Display();
    card2.Display();
    card3.Display();

    // Демонстрация с указателями
    cout << "\n=== РАБОТА С УКАЗАТЕЛЯМИ ===" << endl;
    CreditCard* ptr1 = &card1;
    CreditCard* ptr2 = &card3;

    // Передача по указателям (разыменовываем их)
    Transfer(*ptr1, *ptr2, 100);

    return 0;
}
