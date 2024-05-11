#include <iostream>
#include <cmath>


double f(double x) {
    return exp(-x) - sqrt(x - 1);
}

double findRoot(double a, double b, double epsilon) {
    double c;

    while ((b - a) >= epsilon) {
        c = (a + b) / 2;

        if (f(c) == 0.0) {
            break;
        }
        else if (f(c) * f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    return c;
}

int main() {
    setlocale(LC_CTYPE, "");
    double a = 0.1; // начало интервала
    double b = 1.20; // конец интервала
    double epsilon = 1e-6; // заданная точность

    double root = findRoot(a, b, epsilon);

    std::cout << "Корень уравнения: " << root << std::endl;

    return 0;
};
