import random
import sympy as sp

# Генерация случайных коэффициентов для уравнения конуса второго порядка
A = random.uniform(-10, 10)
B = random.uniform(-10, 10)
C = random.uniform(-10, 10)
D = random.uniform(-10, 10)
E = random.uniform(-10, 10)
F = random.uniform(-10, 10)
G = random.uniform(-10, 10)
H = random.uniform(-10, 10)
I = random.uniform(-10, 10)
J = random.uniform(-10, 10)

# Генерация случайной плоскости: ax + by + cz + d = 0
a = random.uniform(-10, 10)
b = random.uniform(-10, 10)
c = random.uniform(-10, 10)
d = random.uniform(-10, 10)

# Генерация случайной прямой: (x - x0)/l = (y - y0)/m = (z - z0)/n
x0 = random.uniform(-10, 10)
y0 = random.uniform(-10, 10)
z0 = random.uniform(-10, 10)
l = random.uniform(-10, 10)
m = random.uniform(-10, 10)
n = random.uniform(-10, 10)

# Генерация случайной точки
x1 = random.uniform(-10, 10)
y1 = random.uniform(-10, 10)
z1 = random.uniform(-10, 10)

# Проверка принадлежности точки конусу второго порядка
def point_on_cone(A, B, C, D, E, F, G, H, I, J, x1, y1, z1):
    return A*x1**2 + B*y1**2 + C*z1**2 + D*x1*y1 + E*x1*z1 + F*y1*z1 + G*x1 + H*y1 + I*z1 + J == 0

# Проверка пересечения плоскости с конусом второго порядка
def plane_intersects_cone(A, B, C, D, E, F, G, H, I, J, a, b, c, d):
    # Подставляем уравнение плоскости в уравнение конуса и решаем относительно одной переменной
    x, y, z = sp.symbols('x y z')
    plane_eq = a*x + b*y + c*z + d
    cone_eq = A*x**2 + B*y**2 + C*z**2 + D*x*y + E*x*z + F*y*z + G*x + H*y + I*z + J
    substituted_eq = cone_eq.subs(z, (-a*x - b*y - d)/c)
    solutions = sp.solve(substituted_eq, [x, y])
    return bool(solutions)

# Проверка пересечения прямой с конусом второго порядка
def line_intersects_cone(A, B, C, D, E, F, G, H, I, J, x0, y0, z0, l, m, n):
    # Подставляем параметрическое уравнение прямой в уравнение конуса и решаем относительно параметра t
    t = sp.symbols('t')
    x = x0 + l*t
    y = y0 + m*t
    z = z0 + n*t
    cone_eq = A*x**2 + B*y**2 + C*z**2 + D*x*y + E*x*z + F*y*z + G*x + H*y + I*z + J
    solutions = sp.solve(cone_eq, t)
    return bool(solutions)


print(f"Конус второго порядка: {A}x^2 + {B}y^2 + {C}z^2 + {D}xy + {E}xz + {F}yz + {G}x + {H}y + {I}z + {J} = 0")
print(f"Плоскость: {a}x + {b}y + {c}z + {d} = 0")
print(f"Прямая: (x - {x0})/{l} = (y - {y0})/{m} = (z - {z0})/{n}")
print(f"Точка: ({x1}, {y1}, {z1})")
print(f"Пересекает ли плоскость конус? {'Да' if plane_intersects_cone(A, B, C, D, E, F, G, H, I, J, a, b, c, d) else 'Нет'}")
print(f"Пересекает ли прямая конус? {'Да' if line_intersects_cone(A, B, C, D, E, F, G, H, I, J, x0, y0, z0, l, m, n) else 'Нет'}")
print(f"Принадлежит ли точка конусу? {'Да' if point_on_cone(A, B, C, D, E, F, G, H, I, J, x1, y1, z1) else 'Нет'}")
