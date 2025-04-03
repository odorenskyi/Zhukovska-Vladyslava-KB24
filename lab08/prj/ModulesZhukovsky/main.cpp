#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// ������� ���������� S
double s_calculation(double x, double y, double z) {
    // �������� ������ �� 0
    double denominator = sin(z * y);
    if (denominator == 0) {
        cerr << "�������: ������ �� ���� (sin(zy) = 0)" << endl;
        return numeric_limits<double>::quiet_NaN(); // ������� NaN � ��� �������
    }

    // ���������� ������
    double term1 = 0.5 * (y * y + (2 * z) / sqrt(7 * M_PI) + x);
    double term2 = -sqrt(exp(abs(x)));
    double term3 = sqrt(abs(y - z)) / denominator;

    // ��������� �������� S
    return term1 + term2 + term3;
}

int main() {
    double x, y, z;

    // ��� �����
    cout << "������ x: ";
    cin >> x;
    cout << "������ y: ";
    cin >> y;
    cout << "������ z: ";
    cin >> z;

    // ������ �������
    double result = s_calculation(x, y, z);

    // ���� ����������
    if (!isnan(result)) {
        cout << "���������: S = " << result << endl;
    } else {
        cout << "������� � �����������." << endl;
    }

    return 0;
}
