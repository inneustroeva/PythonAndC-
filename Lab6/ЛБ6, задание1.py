import math

def f(x1, x2):
    return x1 * x1 + 3 * x2 * x2 + math.cos(x1 + x2)

def df_dx1(x1, x2):
    return 2 * x1 - math.sin(x1 + x2)

def df_dx2(x1, x2):
    return 6 * x2 - math.sin(x1 + x2)

def coordinate_descent(x1, x2, alpha, epsilon, max_iterations):
    for _ in range(max_iterations):
        prev_x1 = x1
        prev_x2 = x2
        x1 = prev_x1 - alpha * df_dx1(prev_x1, prev_x2)
        x2 = prev_x2 - alpha * df_dx2(prev_x1, prev_x2)
        if abs(x1 - prev_x1) < epsilon and abs(x2 - prev_x2) < epsilon:
            break  # Выход из цикла, если изменения координат стали малыми
    return x1, x2

x1 = 0.5  # Начальная точка
x2 = 0.5
alpha = 0.1  # Шаг градиентного спуска
epsilon = 0.0001  # Критерий остановки
max_iterations = 1000  # Максимальное количество итераций

x1, x2 = coordinate_descent(x1, x2, alpha, epsilon, max_iterations)

print(f"Минимум функции достигается в точке: ({x1}, {x2})")
print(f"Значение функции в этой точке: {f(x1, x2)}")
