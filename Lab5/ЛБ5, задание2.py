import numpy as np

def lagrange_interpolation(x, y, xi):
    result = 0.0
    n = len(x)
    
    for i in range(n):
        term = y[i]
        for j in range(n):
            if j != i:
                term *= (xi - x[j]) / (x[i] - x[j])
        result += term
    
    return result

pi = np.pi

    # Заданные точки
x = [0.1 * pi, 0.2 * pi, 0.3 * pi, 0.4 * pi]
y = [np.sin(xi) for xi in x]

    # Точка для интерполяции
xi = 0.25 * pi
    
    # Интерполяция Лагранжа
interpolated_value = lagrange_interpolation(x, y, xi)
true_value = np.sin(xi)
error = np.abs(interpolated_value - true_value)
    
print(f"Интерполированное значение в x=0.25*pi: {interpolated_value}")
print(f"Истинное значение в x=0.25*pi: {true_value}")
print(f"Погрешность интерполяции: {error}")
