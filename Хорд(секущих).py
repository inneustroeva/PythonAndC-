import math

def f(x):
    return math.exp(-x) - math.sqrt(x - 1)

def secant_method(a, b, eps):
    iterations = 0
    while True:
        iterations += 1
        x_next = b - f(b) * (b - a) / (f(b) - f(a))
        if abs(x_next - b) < eps:
            break
        a, b = b, x_next
    return x_next, iterations

a = 1.1
b = 3
eps = 1e-6

root, iterations = secant_method(a, b, eps)
print(f"Корень уравнения: {root} найден за {iterations} итераций")
