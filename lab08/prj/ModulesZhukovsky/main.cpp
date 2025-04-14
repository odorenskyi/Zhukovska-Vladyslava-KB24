#include "ModulesZhukovsky.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>
#include <bitset>
#include <locale>
#include <codecvt>
#include <sstream> // Для преобразования wstring в string

//lab 8
void developer_info() {
    std::cout << "© Жуковська Владислава" << std::endl;
}

double s_calculation(double x, double y, double z) {
    double part1 = (y * y + 2 * z) / std::sqrt(7 * M_PI + x);
    double firstTerm = 0.5 * part1;

    double secondTerm = std::sqrt(std::exp(std::abs(x)) + std::sqrt(std::abs(y - z)) / std::sin(z * y));

    return firstTerm - secondTerm;
    }

//lab9.1
char calculateRating(int test1, int test2, int exam) {

    int total = test1 + test2 + exam;

    if (total >= 90 && total <= 100) return 'A';
    if (total >= 82) return 'B';
    if (total >= 75) return 'C';
    if (total >= 67) return 'D';
    if (total >= 60) return 'E';
    if (total >= 35) return 'F';
    return 'FX';
}
//lab9.2
std::string convertShoeSize(double size_cm) {
    std::vector<std::pair<double, std::string>> sizeTable = {
        {20.5, "33"}, {21.0, "33 2/3"}, {21.5, "34"}, {22.0, "35"}, {22.5, "35 2/3"},
        {23.0, "36"}, {23.5, "36 2/3"}, {24.0, "37"}, {24.5, "38"}, {25.0, "38 2/3"},
        {25.5, "39"}, {26.0, "40"}, {26.5, "41"}, {27.0, "41.5"}, {27.5, "42"},
        {28.0, "42.5"}, {28.5, "43"}, {29.0, "44"}, {29.5, "45"}, {30.0, "46"},
        {30.5, "46.5"}, {31.0, "47"}, {31.5, "48"}, {32.0, "48.5"}
    };

    for (const auto& entry : sizeTable) {
        if (std::abs(size_cm - entry.first) < 0.01) {
            return entry.second;
        }
    }

    return "Unknown size";
}
//lab9.3
int binaryBitCount(unsigned int N) {
    if (((N >> 10) & 1) == 0) {
        // Count number of 0 bits in binary
        int count = 0;
        for (int i = 0; i < 32; ++i)
            if (((N >> i) & 1) == 0) count++;
        return count;
    } else {
        // Count number of 1 bits
        return std::bitset<32>(N).count();
    }
}

void task10_1(const std::string& inputFilename, const std::string& outputFilename) {
    // Internal helper functions
    auto checkFileExistence = [](const std::string& filename) {
        std::ifstream file(filename);
        return file.good();
    };

    auto readInputFile = [](const std::string& filename) {
        std::wifstream wif(filename);
        wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

        std::wstring content;
        std::wstring line;

        while (std::getline(wif, line)) {
            content += line + L"\n";
        }

        return content;
    };

    auto writeToOutputFile = [](const std::string& filename, const std::wstring& content) {
        std::wofstream wof(filename);
        wof.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

        if (wof.is_open()) {
            wof << content;
            wof.close();
        }
    };

    // Check if input file exists before processing
    if (!checkFileExistence(inputFilename)) {
        std::cout << "Помилка: Вхідний файл не знайдено!\n";
        return;
    }

    // Read input text
    std::wstring inputText = readInputFile(inputFilename);

    if (inputText.empty()) {
        std::cout << "Помилка: Вхідний файл порожній або не може бути прочитаний!\n";
        return;
    }

    std::wstring outputContent;

    // Author information
    outputContent += L"Авторська інформація:\n";
    outputContent += L"Ім'я й прізвище розробника модуля: Жуковська Владислава\n";
    outputContent += L"Установа/організація: ЦНТУ\n";
    outputContent += L"Місто, країна: Кропивницький, Україна\n";
    outputContent += L"Рік розробки: 2025\n\n";

    // Ukrainian alphabet
    outputContent += L"Всі літери української абетки:\n";
    outputContent += L"а б в г ґ д е є ж з и і ї й к л м н о п р с т у ф х ц ч ш щ ь ю я\n\n";

    // Check for errors in the poem
    outputContent += L"Перевірка помилок у вірші:\n";

    std::wstring poem = inputText;
    std::vector<std::wstring> errors;
    std::wstringstream wss(poem);
    std::wstring word;

    std::vector<std::wstring> correctWords = {
        L"Свята", L"моя", L"Ненько", L"я", L"вдячний", L"Тобі",
        L"Що", L"в", L"хаті", L"тепленько", L"і", L"сіль", L"є", L"і", L"хліб",
        L"За", L"те", L"що", L"ще", L"можу", L"свій", L"хрест", L"я", L"нести",
        L"О", L"Матінко", L"Божа", L"спаси", L"і", L"прости"
    };

    int wordIndex = 0;
    while (wss >> word) {
        // Remove punctuation from the word
        for (int i = 0; i < word.length(); ++i) {
            if (std::ispunct(word[i], std::locale())) {
                word.erase(i--, 1);
            }
        }

        if (wordIndex < correctWords.size() && word != correctWords[wordIndex]) {
            errors.push_back(L"Помилка у слові: \"" + word + L"\", очікується \"" + correctWords[wordIndex] + L"\"");
        }
        wordIndex++;
    }

    if (errors.empty()) {
        outputContent += L"Помилок у словах вірша не виявлено.\n\n";
    } else {
        for (const auto& error : errors) {
            outputContent += error + L"\n";
        }
        outputContent += L"\n";
    }

    // Write to output file
    writeToOutputFile(outputFilename, outputContent);

    std::cout << "Завдання 10.1 виконано. Результати записані у файл " << outputFilename << "\n";
}

// Implementation for Task 10.2
void task10_2(const std::string& outputFilename) {
    // Internal helper functions
    auto appendToOutputFile = [](const std::string& filename, const std::wstring& content) {
        std::wofstream wof(filename, std::ios::app);
        wof.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

        if (wof.is_open()) {
            wof << content;
            wof.close();
        }
    };

    auto getCurrentDateTime = []() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];

        localtime_s(&tstruct, &now);
        strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", &tstruct);

        std::string str(buf);
        std::wstring wstr(str.begin(), str.end());
        return wstr;
    };

    std::wstring content;

    content += L"\n--- Державні символи України ---\n";
    content += L"Згідно зі статтею 20 Конституції України:\n";
    content += L"1. Державний Прапор України — стяг із двох рівновеликих горизонтальних смуг синього і жовтого кольорів.\n";
    content += L"2. Великий Державний Герб України встановлюється з урахуванням малого Державного Герба України та герба Війська Запорізького.\n";
    content += L"3. Головним елементом великого Державного Герба України є Знак Княжої Держави Володимира Великого (малий Державний Герб України).\n";
    content += L"4. Державний Гімн України — національний гімн на музику М. Вербицького зі словами, затвердженими законом.\n";
    content += L"5. Опис державних символів України та порядок їх використання встановлюються законом.\n\n";

    // Add timestamp
    content += L"Дата і час дозапису інформації: " + getCurrentDateTime() + L"\n\n";

    // Append to output file
    appendToOutputFile(outputFilename, content);

    std::cout << "Завдання 10.2 виконано. Результати додані до файлу " << outputFilename << "\n";
}

void task10_3(double x, double y, double z, unsigned int b) {
    std::ofstream outputFile("output.txt", std::ios::app);
    if (!outputFile.is_open()) {
        std::cout << "Помилка при відкритті вихідного файлу" << std::endl;
        return;
    }
    
    // Виклик функції s_calculation з аргументами x, y, z
    double result = s_calculation(x, y, z);
    outputFile << "Результат функції s_calculation(" << x << ", " << y << ", " << z << ") = " << result << std::endl;
    
    // Конвертація числа b у двійковий код
    outputFile << "Число " << b << " у двійковому коді: ";
    
    // Використовуємо бітові операції для виведення двійкового представлення
    if (b == 0) {
        outputFile << "0";
    } else {
        // Знаходимо кількість значущих бітів
        int bits = 0;
        unsigned int temp = b;
        while (temp > 0) {
            bits++;
            temp >>= 1;
        }
        
        // Виводимо біти від старшого до молодшого
        for (int i = bits - 1; i >= 0; i--) {
            outputFile << ((b >> i) & 1);
        }
    }
    
    outputFile << std::endl;
    outputFile.close();
}
