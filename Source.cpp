
#include <iostream>
#include <complex>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	complex<double> z1(-1.0, 1.0);
	complex<double> z2(-3.0, 2.0);
	complex<double> z(-1.0, 2.0);

	cout << "Сумма комплексных чисел: " << z1 + z2 << endl;
	cout << "Разность комплексных чисел: " << z1 - z2 << endl;
	cout << " Произведение комплексных чисел: " << z1 * z2 << endl;
	cout << " Частное комплексных чисел: " << z1 / z2 << endl;
	cout << " Возведение в степень комплексного чисела: " << pow(z, 4) << endl;
	double rho = abs(z);    // модуль комплексного числа  
	double theta = arg(z);  // аргумент комплексного числа

	double r = pow(rho, 1.0 / 3.0);  // кубический корень из модуля
	double t = theta / 3.0;    // деление аргумента на 3

	complex<double> Root =polar(r, t); // Создание к.ч. с использованием модуля `r` и аргумента `t`

	cout << "Корень третьей степени комплексного числа: " << Root <<endl;

}