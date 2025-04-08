#include "ModulesZhukovsky.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <cmath>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    developer_info();
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
                int bitCount = binaryBitCount(N);
                std::cout << "Кількість бітів: " << bitCount << std::endl;
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
