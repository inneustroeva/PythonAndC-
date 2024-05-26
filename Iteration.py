
from math import exp, sqrt

def example_function(x):
    return exp(-x) - sqrt(x - 1)

def simple_iteration_method(x_0, epsilon):
    x = x_0
    iter = 0
    while True:
        x_new = exp(-2 * x) + 1

        if abs(x_new - x) < epsilon:
            print(f"Количество итераций: {iter}")
            return x_new

        x = x_new
        iter += 1

x_0 = 3  # начальное значение
epsilon = 1e-8  # точность
root = simple_iteration_method(x_0, epsilon)
print(f"Решение уравнения: x = {root}")
fun = example_function(root)
print(f"Значение функции: f({root}) = {fun}")