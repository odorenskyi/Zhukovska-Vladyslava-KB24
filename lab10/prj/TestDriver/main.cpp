#include "ModulesZhukovsky.h"
#include <windows.h>
#include <iostream>
#include <limits>
#include <string>

// Функция для преобразования std::wstring в std::string
std::string toString(const std::wstring& wstr) {
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string str(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], size_needed, nullptr, nullptr);
    return str;
}

int main() {
    // Установка кодировки UTF-8 для консоли
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";
    int choice;

    do {
        std::cout << "Оберіть завдання для виконання:\n"
                  << "1 - Завдання 10.1\n"
                  << "2 - Завдання 10.2\n"
                  << "3 - Завдання 10.3\n"
                  << "0 - Вихід\n"
                  << "Ваш вибір: ";
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Помилка! Введіть коректне значення: ";
        }

        switch (choice) {
            case 1:
                std::cout << "Виконується завдання 10.1...\n";
                task10_1(inputFilename, outputFilename);
                std::cout << "Завдання 10.1 завершено.\n";
                break;

            case 2:
                std::cout << "Виконується завдання 10.2...\n";
                task10_2(outputFilename);
                std::cout << "Завдання 10.2 завершено.\n";
                break;

            case 3: {
                std::cout << "Виконується завдання 10.3...\n";
                double x, y, z;
                int b;

                std::cout << "Завдання 10.3 - введіть дані для обробки:\n";

                std::cout << "Введіть значення x: ";
                while (!(std::cin >> x)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Помилка! Введіть коректне значення для x: ";
                }

                std::cout << "Введіть значення y: ";
                while (!(std::cin >> y)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Помилка! Введіть коректне значення для y: ";
                }

                std::cout << "Введіть значення z: ";
                while (!(std::cin >> z)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Помилка! Введіть коректне значення для z: ";
                }

                std::cout << "Введіть додатне ціле число b: ";
                while (!(std::cin >> b) || b <= 0) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Помилка! Введіть додатне ціле число для b: ";
                }

                try {
                    task10_3(x, y, z, b);
                } catch (const std::exception& e) {
                    std::cerr << "Помилка під час виконання завдання 10.3: " << e.what() << "\n";
                }
                std::cout << "Завдання 10.3 завершено.\n";
                break;
            }

            case 0:
                std::cout << "Вихід з програми.\n";
                break;

            default:
                std::cout << "Невірний вибір. Будь ласка, спробуйте ще раз.\n";
        }
    } while (choice != 0);

    std::cout << "Ви успішно завершили виконання програми.\n";

    return 0;
}
