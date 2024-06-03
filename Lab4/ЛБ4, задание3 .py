
import numpy as np

def seidel(A, b, x0, epsilon, max_iterations):
    n = len(A)
    x = x0.copy()

    #Seidal Method

    for i in range(max_iterations):
        x_new = np.zeros(n)
        for j in range(n):
            s1 = np.dot(A[j, :j], x_new[:j])
            s2 = np.dot(A[j, j + 1:], x[j + 1:])
            x_new[j] = (b[j] - s1 - s2) / A[j, j]
        if np.allclose(x, x_new, rtol=epsilon):
            return x_new
        x = x_new
    return x
# Заполнение матрицы и правой части
A = np.array([[15, 0, 7, 5],
              [-3, -14, -6, 1],
              [-2, 9, 13, 2],
              [4, -1, 3, 9]])
b = np.array([176, -111, 74, 76])
x0 = np.zeros(4)
eps = 1e-2 # Точность 
max_iter = 100 # Число итераций

x = seidel(A, b, x0, eps, max_iter)
print(x)