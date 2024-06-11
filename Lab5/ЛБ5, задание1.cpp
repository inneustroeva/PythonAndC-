#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // Таблица значений
    std::vector<double> x = {-1.0, 0.0, 1.0, 2.0, 3.0};
    std::vector<double> y = {-0.5, 0.0, 0.5, 0.86603, 1.0};

    // Индекс точки, для которой нужно найти производные (x=1.0)
    int index = -1;
    for (size_t i = 0; i < x.size(); ++i) {
        if (x[i] == 1.0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cerr << "Точка с x=1.0 не найдена в массиве." << std::endl;
        return 1;
    }

    // Первая производная (центральная разность)
    double first_derivative;
    if (index > 0 && index < x.size() - 1) {
        first_derivative = (y[index + 1] - y[index - 1]) / (x[index + 1] - x[index - 1]);
    } else {
        first_derivative = std::nan("");  // Для точек на границе нужно использовать односторонние разности
    }

    // Вторая производная (центральная разность)
    double second_derivative;
    if (index > 1 && index < x.size() - 2) {
        second_derivative = (y[index + 1] - 2 * y[index] + y[index - 1]) / std::pow((x[index + 1] - x[index]), 2);
    } else {
        second_derivative = std::nan("");  // Для точек на границе нужно использовать односторонние разности
    }

    std::cout << "Первая производная в точке x=1: " << first_derivative << std::endl;
    std::cout << "Вторая производная в точке x=1: " << second_derivative << std::endl;

    return 0;
}
