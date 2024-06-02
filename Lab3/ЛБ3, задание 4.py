import numpy as np
def fun(x, eps=1e-6):
    k=1
    total_sum=0
    lim = 20000
    while abs(lim) > eps:
        lim = (-1) ** k / (np.sin(k * x) + 13 + k**2)
        total_sum += lim
        k += 1
    return total_sum

x = float(input("Введите значение x: "))
s = fun(x)

print(f"Сумма функционального ряда {s}")