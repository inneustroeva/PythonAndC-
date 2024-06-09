import random
import sympy as sp

# Генерация случайных коэффициентов для уравнения параболы y = ax^2 + bx + c
a = random.uniform(-10, 10)
b = random.uniform(-10, 10)
c = random.uniform(-10, 10)

# Генерация случайной точки на плоскости
x0 = random.uniform(-10, 10)
y0 = random.uniform(-10, 10)

# Проверка принадлежности точки параболе
def point_on_parabola(a, b, c, x0, y0):
    return y0 == a * x0**2 + b * x0 + c

# Координаты фокуса параболы
def focus_of_parabola(a, b, c):
    xv = -b / (2 * a)
    yv = c - (b**2) / (4 * a)
    return (xv, yv + 1 / (4 * a))

# Расстояние от директрисы до фокуса
def distance_focus_directrix(a):
    return 1 / (2 * a)

print(f"Парабола: y = {a}x^2 + {b}x + {c}")
print(f"Точка: ({x0}, {y0})")
print(f"Принадлежит ли точка параболе? {'Да' if point_on_parabola(a, b, c, x0, y0) else 'Нет'}")
print(f"Координаты фокуса: {focus_of_parabola(a, b, c)}")
print(f"Расстояние от директрисы до фокуса: {distance_focus_directrix(a)}")
