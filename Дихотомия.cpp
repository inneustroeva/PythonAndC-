#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

double f(double x) {
	return exp(-x) - sqrt(x - 1);
}
double dixit(double a, double b, double eps) {
	double c;
	do {
		c = (a + b) / 2.0;
		if (f(a) * f(c) < 0) b = c;
		else if (f(b) * f(c) < 0) a = c;
		else {
			cout << "The root is not found" << endl;
			return 0;
		}
	} while (fabs(b - a) >= eps);
	return c;
}
int main()
{
	double a = 0.9;
	double b = 1.20;
	double eps = 0.000001;
	cout << dixit(a, b, eps);
}