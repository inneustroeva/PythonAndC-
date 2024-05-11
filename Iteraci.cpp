#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x)
{
    return exp(-x) - sqrt(x - 1);
}

double g(double x)
{
    return exp(-2 * x) + 1;
}

double find(double x, double eps)
{
    double x_1, x_2;
    int iter = 0;
    x_2 = x;
    do {
        x_1 = x_2;
        x_2 = g(x_1);
        iter++;
    } while (fabs(x_2 - x_1) > eps && iter < 100);
    cout << "\nNumber of iterations is " << iter << endl;
    return x_2;
}

int main()
{
    double x0, eps, root;
    cout << "x_0 = ";
    cin >> x0;
    eps = 1e-6;
    root = find(x0, eps);
    cout << "Root x = " << fixed << setprecision(16) << root;
    cout << "\nFunction value f(x)=" << func(root);
    cin.get();
    return 0;
}
