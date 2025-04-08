#include "ModulesZhukovsky.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <bitset>

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
