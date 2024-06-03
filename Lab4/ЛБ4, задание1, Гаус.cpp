#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Функция для вывода матрицы
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << setw(10) << val << " ";
        }
        cout << endl;
    }
}

// Функция для решения системы уравнений методом Гаусса
void gaussianElimination(vector<vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        // Прямой ход
        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k <= n; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    // Обратный ход
    vector<double> result(n);
    for (int i = n - 1; i >= 0; --i) {
        result[i] = matrix[i][n] / matrix[i][i];
        for (int j = i - 1; j >= 0; --j) {
            matrix[j][n] -= matrix[j][i] * result[i];
        }
    }
    // Вывод решения
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << result[i] << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<vector<double>> matrix = { {-8, 5, 8, -6, -144},
                                     {2, 7, -8, 1, 25},
                                     {-5, -4, 1, -6, -21},
                                     {5, -9, -2, 8, 103} };

    gaussianElimination(matrix);

    return 0;
}