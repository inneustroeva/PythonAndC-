#include <iostream>
#include <cmath>
#include <vector>

double LagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi) {
    double result = 0.0;
    int n = x.size();
    
    for (int i = 0; i < n; ++i) {
        double term = y[i];
        for (int j = 0; j < n; ++j) {
            if (j != i)
                term = term * (xi - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}

int main() {
    const double pi = 3.14159265358979323846;

    // Заданные точки
    std::vector<double> x = {0.1 * pi, 0.2 * pi, 0.3 * pi, 0.4 * pi};
    std::vector<double> y;
    for (double xi : x) {
        y.push_back(sin(xi));
    }

    // Точка для интерполяции
    double xi = 0.25 * pi;
    
    // Интерполяция Лагранжа
    double interpolated_value = LagrangeInterpolation(x, y, xi);
    double true_value = sin(xi);
    double error = std::abs(interpolated_value - true_value);
    
    std::cout << "Интерполированное значение в x=0.25*pi: " << interpolated_value << std::endl;
    std::cout << "Истинное значение в x=0.25*pi: " << true_value << std::endl;
    std::cout << "Погрешность интерполяции: " << error << std::endl;

    return 0;
}
