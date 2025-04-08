#include "ModulesZhukovsky.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

int main() {
    char choice;
    bool continueProgram = true;

    while (continueProgram) {
        std::cout << "Введіть ваш вибір (u, t, r, e): ";
        std::cin >> choice;

        switch (choice) {
            case 'u': {
                double x, y, z;
                std::cout << "Введіть x, y, z для s_calculation: ";
                std::cin >> x >> y >> z;
                double result = s_calculation(x, y, z);
                std::cout << "Результат: " << result << std::endl;
                break;
            }
            case 't': {
                int test1, test2, exam;
                std::cout << "Введіть бали за тест1, тест2 та іспит: ";
                std::cin >> test1 >> test2 >> exam;
                char grade = calculateRating(test1, test2, exam);
                std::cout << "Оцінка: " << grade << std::endl;
                break;
            }
            case 'r': {
                double size_cm;
                std::cout << "Введіть розмір взуття в сантиметрах: ";
                std::cin >> size_cm;
                std::string shoeSize = convertShoeSize(size_cm);
                std::cout << "Розмір взуття: " << shoeSize << std::endl;
                break;
            }
            case 'e': {
                unsigned int N;
                std::cout << "Введіть ціле беззнакове число: ";
                std::cin >> N;

                if (N > 50000000) {
                    std::cout << "Некоректне число. Повинно бути менше або рівне 50000000.\n";
                } else {
                    // Обчислення кількості бітів та виведення результату
                    std::cout << "Кількість бітів (в залежності від D10): " << binaryBitCount(N) << "\n";
                }
                break;
            }
            default:
                // Відтворення звукового сигналу про помилкове введення
                std::cout << "\a" << "Неправильне введення!" << std::endl;
                break;
        }

        char addChoice;
        std::cout << "Бажаєте продовжити? Введіть 'w' або 'i' для виходу, будь-який інший символ для продовження: ";
        std::cin >> addChoice;

        if (addChoice == 'w' || addChoice == 'i') {
            continueProgram = false;
        }
    }

    return 0;
}
