import math

def example_function(x):
    if x < 1:
        raise ValueError("x должен быть больше или равен 1")
    return math.exp(-x) - math.sqrt(x - 1)

def dichotomy_method(f, a, b, epsilon):
    if f(a) * f(b) > 0:
        print("Функция должна иметь разные знаки на концах интервала a и b.")
        return None
    iter = 0
    while (b - a) / 2 > epsilon:
        c = (a + b) / 2
        iter += 1
        if f(c) == 0:
            return c
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
    print(f"Количество итераций: {iter}")
    return (a + b) / 2

a = 1  # левый край изменен, чтобы избежать ошибки
b = 1.20  # правый край
epsilon = 1e-6  # точность
root = dichotomy_method(example_function, a, b, epsilon)

if root is not None:
    print(f"Решение уравнения: x = {root}")
    fun = example_function(root)
    print(f"Значение функции: f({root}) = ", fun)
else:
    print("Корень не найден.")