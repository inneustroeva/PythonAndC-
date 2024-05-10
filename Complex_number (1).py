#Метод complex
import math
import cmath
# Комплексное число -1+1j
z = complex(-1, 1)
print(z)
# Комплексное число -3+2j
z = complex(-3, 2)
print(z)
# Комплексное число -1+2j
z = complex(-1, 2)
print(z)
# Комплексное число -1+2j cmath module
num = -1 + 2j # Using cmath module
p = cmath.phase(num)
print('cmath Module:', p) # Using math module
p = math.atan(num.imag/num.real)
print('Math Module:', p)
p = cmath.phase(num)
print('cmath Module in Radians:', p)
# Комплексное число -1+2j
a = -1 + 2j 
polar_coordinates = cmath.polar(a) 
print(polar_coordinates) 
modulus = abs(a) 
phase = cmath.phase(a) 
rect_coordinates = cmath.rect(modulus, phase) 
print(rect_coordinates)
# число pi
print('π =', cmath.pi)

# Арифметические операции
a = -1 + 1j
b = -3 + 2j
d = -1 + 2j 
c = a + b
print('a + b =', c)
c = a - b
print('a - b =', c)
c = a * b
print('a * b =', c)
c = a / b
print('a / d =', c)
c = d ** 4
print('a ** 4 =', c)

z = complex(input("Введите комплексное число a+bj: "))
n = int(input("Введите корень, который вы хотите найти (n): "))
r, phi = cmath.polar(z)
r **= 1 / n
print("n-ые корни комплексного числа: \n")
for k in range(n):
    roots = cmath.rect(r, (phi + 2 * cmath.pi * k) / n)
    print("k=",k, ", z_k=", roots, sep="")

z = complex(input("Введите комплексное число a+bj: "))
n = int(input("Введите корень, который вы хотите найти (n): "))
roots = [cmath.rect(pow(abs(z), 1/n), cmath.phase(z)/n + 2*cmath.pi*k/n) for k in range(n)]
print("n-ые корни комплексного числа в форме списка: \n", roots)
