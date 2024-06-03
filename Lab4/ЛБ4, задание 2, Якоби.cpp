#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Russian");
    // Входные данные (матрица коэффициентов и вектор свободных членов)
    double A[3][3] = { {-10, -1, 3},
                      {8, 7, 2},
                      {6, 6, 2} };
    double b[3] = { -1, 0, 2 };

    // Начальное приближение
    double x[3] = { 0, 0, 0 };

    // Количество итераций
    int max_iter = 100;
    int iter = 0;

    // Точность
    double eps = 1e-6;

    // Решение системы методом Якоби
    while (iter < max_iter) {
        double x_new[3];
        for (int i = 0; i < 3; i++) {
            double sum = 0;
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        double diff = 0;
        for (int i = 0; i < 3; i++) {
            diff += std::abs(x_new[i] - x[i]);
        }

        if (diff < eps) {
            break;
        }

        for (int i = 0; i < 3; i++) {
            x[i] = x_new[i];
        }

        iter++;
    }

    // Вывод решения
    std::cout << "Решение СЛАУ:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "x" << i + 1 << " = " << x[i] << std::endl;
    }

    return 0;
}