import numpy as np
from scipy.optimize import minimize_scalar

def f(x):
    x1, x2 = x
    return 7 * x1**2 + 2 * x1 * x2 + 5 * x2**2 + x1 - 10 * x2

def grad_f(x):
    x1, x2 = x
    df_dx1 = 14 * x1 + 2 * x2 + 1
    df_dx2 = 2 * x1 + 10 * x2 - 10
    return np.array([df_dx1, df_dx2])

def steepest_descent(x, epsilon, max_iterations):
    for i in range(max_iterations):
        grad = grad_f(x)
        alpha = minimize_scalar(lambda a: f(x - a * grad)).x
        x_new = x - alpha * grad
        if np.linalg.norm(x_new - x) < epsilon:
            break
        x = x_new
    return x

x_initial = np.array([0.0, 0.0])
epsilon = 0.0001
max_iterations = 1000

x_optimal = steepest_descent(x_initial, epsilon, max_iterations)
print("Минимум функции достигается в точке:", x_optimal)
print("Значение функции в этой точке:", f(x_optimal))
