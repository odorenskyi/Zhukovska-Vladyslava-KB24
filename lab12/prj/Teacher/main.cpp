#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <filesystem>
#include <algorithm>
#include "ModulesZhukovska.h"

using namespace std;
namespace fs = std::filesystem;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "╔══════════════════════════════════════════════════════╗\n";
    cout << "║  Програму створила Жуковська Владислава, КБ-24       ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n\n";

    // Функція для обробки помилки шляху
    auto wrongPathError = [](const string& fileName, const string& reason) {
        ofstream testResult(fileName);
        for (int i = 0; i < 100; ++i) cout << '\a';
        testResult << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
        testResult << "Порушено вимогу: " << reason << endl;
        testResult.close();
    };

    // Перевірка шляху до main.cpp
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);
    string pathStr = exePath;
    string requiredPath = "\\lab12\\prj\\";
    string pathStrLower = pathStr;
    string requiredPathLower = requiredPath;
    transform(pathStrLower.begin(), pathStrLower.end(), pathStrLower.begin(), ::tolower);
    transform(requiredPathLower.begin(), requiredPathLower.end(), requiredPathLower.begin(), ::tolower);
    if (pathStrLower.find(requiredPathLower) == string::npos) {
        wrongPathError("TestResults.txt", "main.cpp або виконуваний файл має бути у каталозі \\lab12\\prj\\");
        cout << "Встановлені вимоги порушено! Див. TestResults.txt\n";
        return 0;
    }

    int testCount;
    cout << "Введіть кількість тестів: ";
    cin >> testCount;

    if (cin.fail() || testCount <= 0) {
        cout << "Некоректне число тестів! Натисніть Enter для завершення...";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
        return 1;
    }

    ofstream outfile("TestResults.txt");
    if (!outfile) {
        cerr << "Не вдалося відкрити файл для запису результатів: TestResults.txt" << endl;
        cout << "Натисніть Enter для завершення...";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
        return 1;
    }

    outfile << "╔════════╦════════════╦════════════╦════════════════════╦════════════════════╦════════════╗\n";
    outfile << "║ Тест   ║ a          ║ b          ║ Очікуване значення ║ Обчислене значення ║ Результат  ║\n";
    outfile << "╠════════╬════════════╬════════════╬════════════════════╬════════════════════╬════════════╣\n";

    for (int i = 0; i < testCount; ++i) {
        double a, b, expectedPerimeter;
        cout << "\n=== Тест " << (i + 1) << " ===\n";
        cout << "Введіть довжину a: ";
        cin >> a;
        cout << "Введіть довжину b: ";
        cin >> b;
        cout << "Введіть очікуваний периметр: ";
        cin >> expectedPerimeter;

        if (cin.fail()) {
            cout << "Некоректний ввід! Натисніть Enter для завершення...";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return 1;
        }

        // Створюємо об'єкт класу та обчислюємо периметр
        ClassLab12_Zhukovska rectangle(a, b);
        double computedPerimeter = rectangle.getPerimeter();
        
        string testResult = (fabs(computedPerimeter - expectedPerimeter) < 0.0001) ? "Passed" : "FAILED";
        
        outfile << "║ " << setw(6) << left << (i + 1)
                << " ║ " << setw(10) << left << a
                << " ║ " << setw(10) << left << b
                << " ║ " << setw(18) << left << expectedPerimeter
                << " ║ " << setw(18) << left << computedPerimeter
                << " ║ " << setw(10) << left << testResult << " ║\n";
    }

    outfile << "╚════════╩════════════╩════════════╩════════════════════╩════════════════════╩════════════╝\n";
    outfile.close();

    cout << "\n╔══════════════════════════════════════════════════════╗\n";
    cout << "║ Результати тестів збережено у файл TestResults.txt   ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n";

    cout << "Натисніть Enter для завершення...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();

    return 0;
}
