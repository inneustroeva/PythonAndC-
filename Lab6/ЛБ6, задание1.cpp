#include <iostream>
#include <cmath>

double f(double x1, double x2) {
    return x1 * x1 + 3 * x2 * x2 + cos(x1 + x2);
}

double df_dx1(double x1, double x2) {
    return 2 * x1 - sin(x1 + x2);
}

double df_dx2(double x1, double x2) {
    return 6 * x2 - sin(x1 + x2);
}

void coordinateDescent(double& x1, double& x2, double alpha, double epsilon, int max_iterations) {
    for (int i = 0; i < max_iterations; ++i) {
        double prev_x1 = x1;
        double prev_x2 = x2;
        x1 = prev_x1 - alpha * df_dx1(prev_x1, prev_x2);
        x2 = prev_x2 - alpha * df_dx2(prev_x1, prev_x2);
        if (std::abs(x1 - prev_x1) < epsilon && std::abs(x2 - prev_x2) < epsilon) {
            break;  // Выход из цикла, если изменения координат стали малыми
        }
    }
}

int main() {
    double x1 = 0.5;  // Начальная точка
    double x2 = 0.5;
    double alpha = 0.1;  // Шаг градиентного спуска
    double epsilon = 0.0001;  // Критерий остановки
    int max_iterations = 1000;  // Максимальное количество итераций

    coordinateDescent(x1, x2, alpha, epsilon, max_iterations);

    std::cout << "Минимум функции достигается в точке: (" << x1 << ", " << x2 << ")\n";
    std::cout << "Значение функции в этой точке: " << f(x1, x2) << "\n";

    return 0;
}
