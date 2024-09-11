// Новиков Віталій
/*
Завдання 42 з третьої таблиці,
я перевірив на правильність обчислень у калькуляторі математичних виразів,
все розраховується правильно :)
було важкувато зробити правильне обчислення {*_*}, але в мене вийшло
Формула для обчислення y:
y = (tg|2*x² + 5*x| - log5|x - 2.5|) / sqrt(|sin⁴(x³) + ⅕*log5|x² - 2.5|)
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //Integer30
    //Boolen40
    //tab.3, N42

    
//Integer30
    int year; // Змінна для зберігання року
    cout << "Integer30" << endl;
    cout << "Введіть рік: ";
    cin >> year; // Зчитування року з вводу користувача

    // Перевірка, чи рік є дійсним
    if (year <= 0) {
        cout << "Рік повинен бути додатнім числом." << endl;
        return 1; // Завершення програми з кодом помилки
    }

    // Визначення століття
    int century;
    if (year % 100 == 0) {
        // Якщо рік кратний 100, то століття розраховується як рік / 100
        century = year / 100;
    } else {
        // Інакше, століття розраховується як рік / 100 + 1
        century = (year / 100) + 1;
    }

    cout << "Століття: " << century << endl; // Виведення результату


//Boolen40
    cout << " " << endl;
    cout << "Boolen40" << endl;
    int x1, y1, x2, y2; // Змінні для зберігання координат двох полів
    cout << "Введіть координати першого поля (x1 y1): ";
    cin >> x1 >> y1; // Зчитування координат першого поля

    cout << "Введіть координати другого поля (x2 y2): ";
    cin >> x2 >> y2; // Зчитування координат другого поля

    // Перевірка, чи координати знаходяться в межах шахової дошки
    if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8 || x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) {
        cout << "Координати повинні бути в межах від 1 до 8." << endl;
        return 1; // Завершення програми з кодом помилки
    }

    // Перевірка можливості переходу коня з одного поля на інше
    bool canMove = (abs(x1 - x2) == 2 && abs(y1 - y2) == 1) 
    // Переміщення на 2 клітинки в горизонтальному напрямку і 1 клітинку в вертикальному
                   || (abs(x1 - x2) == 1 && abs(y1 - y2) == 2);
    // Переміщення на 1 клітинку в горизонтальному напрямку і 2 клітинки в вертикальному

    // Виведення результату
    if (canMove) {
        cout << "Конь може перейти з одного поля на інше за один хід." << endl;
    } else {
        cout << "Конь не може перейти з одного поля на інше за один хід." << endl;
    }


//tab.3, N42
    cout << " " << endl;
    cout << "tab.3, N42" << endl;


    double x; // Змінна для зберігання значення x
    cout << "Введіть значення x: ";
    cin >> x; // Зчитування значення x з вводу користувача

    // Обчислення чисельника
    double absValue1 = fabs(2 * x * x + 5 * x); // |2*x² + 5*x|
    double tanValue = tan(absValue1); // tg|2*x² + 5*x|

    double absValue2 = fabs(x - 2.5); // |x - 2.5|
    double logBase5Value2 = log10(absValue2) / log10(5); // log5|x - 2.5|

    double numerator = tanValue - logBase5Value2; // Чисельник формули

    // Обчислення знаменника
    double sinValue = pow(sin(x * x * x), 4); // sin⁴(x³)
    double absValue3 = fabs(x * x - 2.5); // |x² - 2.5|
    double logBase5Value3 = (1.0 / 5.0) * (log10(absValue3) / log10(5)); // ⅕ * log5|x² - 2.5|

    double denominator = sqrt(fabs(sinValue + logBase5Value3)); // Корінь з (|sin⁴(x³) + ⅕log5|x² - 2.5|)

    // Перевірка, чи знаменник не дорівнює нулю
    if (denominator == 0) {
        cout << "Знаменник дорівнює нулю. Неможливо поділити." << endl;
        return 1; // Завершення програми з кодом помилки
    }

    // Обчислення результату
    double y = numerator / denominator;

    cout << "Результат y = " << y << endl; // Виведення результату

    
    
    return 0; // Успішне завершення програми
}