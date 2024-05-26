#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
const int N=10;

// Функция для полинома:
double F(double x){
    return exp(-x) - sqrt(x - 1);
}

// Функция поиска корня:
double FindRoot(double (*f)(double), double x0, int n){
    double x=x0, df, h=0.00001;
    int iterations = 0; // переменная для подсчета итераций

    df = (f(x+h) - f(x)) / h;
    for(int i=1; i<=n; i++) {
        x = x - f(x) / df;
        iterations++; // увеличиваем счетчик итераций
    }

    cout << "Количество итераций: " << iterations << endl;

    return x;
}

int main(){
    // Начальное приближение и корень:
    double x0, x;
    cout << "initial x0 = ";
    cin >> x0;

    // Поиск решения:
    x = FindRoot(F, x0, N);

    cout << "x = " << x << endl;

    return 0;
}
