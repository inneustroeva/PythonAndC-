import numpy

M4 = numpy.array([[-8., 5., 8., -6.], [2., 7., -8., -1.], [-5., -4., 1., -6.], [5., -9., -2., 8.]])
v4 = numpy.array([-144., 25., -21., 103.])

a = numpy.linalg.solve(M4, v4)
print('Решение СЛАУ')
print(a)
