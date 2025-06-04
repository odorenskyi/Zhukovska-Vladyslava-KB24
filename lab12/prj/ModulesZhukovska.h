#ifndef MODULESZHUKOVSKA_H_INCLUDED
#define MODULESZHUKOVSKA_H_INCLUDED

class ClassLab12_Zhukovska {
private:
    double a, b;  // довжини сторін

public:
    ClassLab12_Zhukovska(double a = 0.0, double b = 0.0);
    double getA() const;
    double getB() const;
    void setA(double a);
    void setB(double b);
    double getPerimeter() const;
};

ClassLab12_Zhukovska::ClassLab12_Zhukovska(double a, double b) : a(a), b(b) {}

double ClassLab12_Zhukovska::getA() const { return a; }
double ClassLab12_Zhukovska::getB() const { return b; }

void ClassLab12_Zhukovska::setA(double a) { this->a = a; }
void ClassLab12_Zhukovska::setB(double b) { this->b = b; }

double ClassLab12_Zhukovska::getPerimeter() const { return 2 * (a + b); }

#endif // MODULESZHUKOVSKA_H_INCLUDED
