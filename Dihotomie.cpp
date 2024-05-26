#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x)
{
    return exp(-x) - sqrt(x - 1);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int iter = 0;
    double eps;
    double a, b, t, f1, f2, x;
    cout << "Введите сегмент, где должен быть корень уравнения";
    cout << "\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "eps = ";
    cin >> eps;
    do
    {
        f1 = func(a);
        t = (a + b) / 2.0;
        f2 = func(t);
        if (f1 * f2 <= 0) b = t;
        else a = t;
        iter++;
    } while (fabs(b - a) > eps);
    x = (a + b) / 2.0;
    f1 = func(x);
    if (fabs(f1) <= eps)
    {
        cout << "\nКорень уравнения c заданной точностью  ";
        cout << fixed << setprecision(16) << "eps = " << eps << "  x = " << x;
        cout << "\nЗначение функции f(x)= " << func(x) << ".";
        cout << "\nКол-во итераций " << iter << ".";
    }
    else cout << "Уравнение не имеет корней !!!";
    return 0;
}