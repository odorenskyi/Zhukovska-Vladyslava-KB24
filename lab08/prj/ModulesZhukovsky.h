#ifndef MODULESZHUKOVSKY_H
#define MODULESZHUKOVSKY_H

double s_calculation(double x, double y, double z);
void developer_info();

//lab 9
#include <string>
char calculateRating(int test1, int test2, int exam);
std::string convertShoeSize(double size_cm);
int binaryBitCount(unsigned int N);

//lab 10
void task10_1(const std::string& inputFilename, const std::string& outputFilename);
void task10_2(const std::string& outputFilename);
void task10_3(double x, double y, double z, unsigned int b);

#endif // MODULESZHUKOVSKY_H