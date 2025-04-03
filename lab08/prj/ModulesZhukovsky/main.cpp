#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Функція обчислення S
double s_calculation(double x, double y, double z) {
    // Перевірка ділення на 0
    double denominator = sin(z * y);
    if (denominator == 0) {
        cerr << "Помилка: ділення на нуль (sin(zy) = 0)" << endl;
        return numeric_limits<double>::quiet_NaN(); // Повертає NaN у разі помилки
    }

    // Обчислення виразу
    double term1 = 0.5 * (y * y + (2 * z) / sqrt(7 * M_PI) + x);
    double term2 = -sqrt(exp(abs(x)));
    double term3 = sqrt(abs(y - z)) / denominator;

    // Остаточне значення S
    return term1 + term2 + term3;
}

int main() {
    double x, y, z;

    // Ввід даних
    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть y: ";
    cin >> y;
    cout << "Введіть z: ";
    cin >> z;

    // Виклик функції
    double result = s_calculation(x, y, z);

    // Вивід результату
    if (!isnan(result)) {
        cout << "Результат: S = " << result << endl;
    } else {
        cout << "Помилка в обчисленнях." << endl;
    }

    return 0;
}
