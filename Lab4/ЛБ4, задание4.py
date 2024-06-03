import numpy

def Metod_Progonki(A, B):
    k1 = -A[0, 1]
    m1 = B[0]
    k2 = -A[A.shape[0] - 1, A.shape[1] - 2]
    m2 = B[B.shape[0] - 1]
    alfa = k1
    beta = m1
    c = 2
    a = 0
    b = 1
    alf = [alfa]
    bet = [beta]
    
    for i in range(1, A.shape[0] - 1):
        beta = (B[i] - A[i, a] * beta) / (A[i, a] * alfa + A[i, b])
        alfa = -A[i, c] / (A[i, a] * alfa + A[i, b])
        a += 1
        b += 1
        c += 1
        alf.append(alfa)
        bet.append(beta)
    
    y = (k2 * beta + m2) / (1 - k2 * alfa)
    otv = [y]
    
    for i in range(len(alf) - 1, -1, -1):
        y = alf[i] * y + bet[i]
        otv.append(y)
    
    otvet = []
    for i in reversed(otv):
        otvet.append(i)
    
    return otvet

A_5x5 = numpy.array([[10, -1, 0, 0, 0], [-8, 16, 1, 0, 0], [0, 6, -16, 6, 0], [0, 0, -8, 16, -5], [0, 0, 0, 5, -13]])
B_5x5 = numpy.array([16, -110, 24, -3, 87])

print(A_5x5)
print(B_5x5)
print(Metod_Progonki(A_5x5, B_5x5))

