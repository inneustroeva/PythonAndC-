import numpy as np

# Таблица значений
x = np.array([-1.0, 0.0, 1.0, 2.0, 3.0])
y = np.array([-0.5, 0.0, 0.5, 0.86603, 1.0])

# Индекс точки, для которой нужно найти производные (x=1.0)
index = np.where(x == 1.0)[0][0]

# Первая производная (центральная разность)
if 0 < index < len(x) - 1:
    first_derivative = (y[index + 1] - y[index - 1]) / (x[index + 1] - x[index - 1])
else:
    first_derivative = np.nan  # Для точек на границе нужно использовать односторонние разности

# Вторая производная (центральная разность)
if 1 < index < len(x) - 2:
    second_derivative = (y[index + 1] - 2 * y[index] + y[index - 1]) / ((x[index + 1] - x[index]) ** 2)
else:
    second_derivative = np.nan  # Для точек на границе нужно использовать односторонние разности

print(f"Первая производная в точке x=1: {first_derivative}")
print(f"Вторая производная в точке x=1: {second_derivative}")
