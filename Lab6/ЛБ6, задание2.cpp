#include <iostream>
#include <cmath>
#include <vector>

// Функция для вычисления значения функции в точке (x1, x2)
double f(const std::vector<double>& x) {
    double x1 = x[0];
    double x2 = x[1];
    return 7 * x1 * x1 + 2 * x1 * x2 + 5 * x2 * x2 + x1 - 10 * x2;
}

// Функция для вычисления градиента функции в точке (x1, x2)
std::vector<double> grad_f(const std::vector<double>& x) {
    double x1 = x[0];
    double x2 = x[1];
    double df_dx1 = 14 * x1 + 2 * x2 + 1;
    double df_dx2 = 2 * x1 + 10 * x2 - 10;
    return {df_dx1, df_dx2};
}

// Функция для одномерной минимизации (поиск оптимального alpha)
double minimize_scalar(double (*func)(double, const std::vector<double>&, const std::vector<double>&), const std::vector<double>& x, const std::vector<double>& grad) {
    double a = 0.0;
    double b = 1.0;
    double tol = 1e-6;
    double golden_ratio = (1 + std::sqrt(5)) / 2;

    double c = b - (b - a) / golden_ratio;
    double d = a + (b - a) / golden_ratio;

    while (std::abs(b - a) > tol) {
        if (func(c, x, grad) < func(d, x, grad)) {
            b = d;
        } else {
            a = c;
        }
        c = b - (b - a) / golden_ratio;
        d = a + (b - a) / golden_ratio;
    }

    return (a + b) / 2;
}

// Функция для вычисления значения функции для одномерной минимизации
double func(double alpha, const std::vector<double>& x, const std::vector<double>& grad) {
    return f({x[0] - alpha * grad[0], x[1] - alpha * grad[1]});
}

// Функция для выполнения метода наискорейшего спуска
std::vector<double> steepest_descent(std::vector<double> x, double epsilon, int max_iterations) {
    for (int i = 0; i < max_iterations; ++i) {
        std::vector<double> grad = grad_f(x);
        double alpha = minimize_scalar(func, x, grad);
        std::vector<double> x_new = {x[0] - alpha * grad[0], x[1] - alpha * grad[1]};
        if (std::sqrt((x_new[0] - x[0]) * (x_new[0] - x[0]) + (x_new[1] - x[1]) * (x_new[1] - x[1])) < epsilon) {
            break;
        }
        x = x_new;
    }
    return x;
}

int main() {
    std::vector<double> x_initial = {0.0, 0.0};
    double epsilon = 0.0001;
    int max_iterations = 1000;

    std::vector<double> x_optimal = steepest_descent(x_initial, epsilon, max_iterations);
    std::cout << "Минимум функции достигается в точке: (" << x_optimal[0] << ", " << x_optimal[1] << ")\n";
    std::cout << "Значение функции в этой точке: " << f(x_optimal) << "\n";

    return 0;
}
