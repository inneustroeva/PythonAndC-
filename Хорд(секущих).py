#Метод хорд (секущих)
import math

def example_function(x):
    return math.exp(-x) - math.sqrt(x - 1)

def secant_method(f, x_0, x_1, epsilon, max_iter):
    iteration = 0

    while iteration < max_iter:
        x_2 = x_1 - f(x_1) * (x_1 - x_0) / (f(x_1) - f(x_0))

        if abs(x_2 - x_1) < epsilon:
            return x_2, iteration

        x_0 = x_1
        x_1 = x_2
        iteration += 1

    raise Exception("Не удалось найти корень методом секущих")


a=1.1 #левый край
b=3 #правый край
epsilon=1e-6 #точность
max_iter=100 # число итераций
root, iterations = secant_method(example_function, a, b, epsilon, max_iter)
print(f"Корень уравнения: {root:.12f}")
print(f"Количество итераций: {iterations}")
fun=example_function(root)
print(f"Значение функции: f({root})=",fun)

