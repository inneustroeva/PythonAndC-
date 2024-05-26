from math import exp, sqrt

def function(x):
    return exp(-x) - sqrt(x - 1)

def iterative_method(x_0, epsilon):
    x = x_0
    iters = 0
    while True:
        x_new = exp(-x)
        if abs(x_new - x) < epsilon:
            print(f"Number of iterations: {iters}")
            return x_new
        x = x_new
        iters += 1

x_0 = 1.5  # начальное значение
epsilon = 1e-6  # точность
root = iterative_method(x_0, epsilon)
print(f"Solution: x = {root}")
