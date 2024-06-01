// Неустроева Ирина, НБИ-02-23, ЛБ 3, Задание 1
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>

using namespace std;

double f(double x)
{
    return 1 / (pow(x, 4) * (13 + pow(x, 2))); // Функция для интегрирования
}

double Left_Rect(double a, double b, double n_point) { // Функция для левых прямоугольников
    double h = (b - a) / n_point;
    double sum = 0.0;
    for (int i = 0; i <= n_point - 1; i++) {
        sum += h * f(a + i * h);
    }
    return sum;
}

double Right_Rect(double a, double b, double n_point) { // Функция для правых прямлоугольников
    double h = (b - a) / n_point;
    double sum = 0.0;
    for (int i = 1; i <= n_point; i++) {
        sum += h * f(a + i * h);
    }
    return sum;
}

double Trapeze_Rect(double a, double b, double n_point) { // Функция для трапеций
    double h = (b - a) / n_point;
    double sum = f(a) + f(b);
    for (int i = 1; i <= n_point - 1; i++) {
        sum += 2 * f(a + i * h);
    }
    sum *= h / 2;
    return sum;
}
double Sympson_Rect(double a, double b, double n_point) { // Функция для Симпсона
    double h = (b - a) / n_point;
    double sum = f(a) + f(b);
    int k;
    for (int i = 1; i <= n_point - 1; i++) {
        k = 2 + 2 * (i % 2); // если i чет = 2, else i = 4;
        sum += 2 * f(a + i * h);
    }
    sum *= h / 3;
    return sum;
}
double Midpoint_Rect(double a, double b, double n_point) { // Функция средних прямоугольников
    double h = (b - a) / n_point;
    double sum = 0.0;
    for (int i = 0; i <= n_point - 1; i++) {
        sum += h * f(a + (i + 0.5) * h);
    }
    return sum;
}
int main()
{
    setlocale(LC_ALL, "rus");
    double a, b, x, h;
    int n_point;
    cout << "Введите нижний предел  a=";
    cin >> a;
    cout << "Введите верхний предел  b=";
    cin >> b;
    cout << "Введите число точек n=";
    cin >> n_point;
    double eps = 1e-6;
    
    cout << "Значение интеграла для метода левых прямоугольников без заданной точности:" << endl;
    cout << "I=" << Left_Rect(a, b, n_point) << endl;
    int k = 10; // Объявим начальное разбиение 
    int i = 0;
    double diff;
    do {
        i++; 
        diff = fabs(Left_Rect(a, b, k * i) - Left_Rect(a, b, k * (i + 1)));
    } while (diff > eps); // удваеваем разбиение и сравниваем значение интеграла
    cout << "Значение интеграла для метода левых прямоугольников c точностью 1e-6:" << endl;
    cout << "k= " << k * (i + 1) << " " << "Left_Rect= " << Left_Rect(a, b, k * (i + 1))<< endl;
    
    cout << "Значение интеграла для метода правых прямоугольников без заданной точности:" << endl;
    cout << "I=" << Left_Rect(a, b, n_point) << endl;
    do {
        i++;
        diff = fabs(Right_Rect(a, b, k * i) - Right_Rect(a, b, k * (i + 1)));
    } while (diff > eps);
    cout << "Значение интеграла для правый прямоугольников с точностью 1e-6:" << endl;
    cout << "k= " << k * (i + 1) << " " << "Right_Rect= " << Right_Rect(a, b, k * (i + 1)) << endl;
    
    cout << "Значение интеграла для метода трапеций без заданной точности:" << endl;
    cout << "I=" << Trapeze_Rect(a, b, n_point) << endl;
    do {
        i++;
        diff = fabs(Trapeze_Rect(a, b, k * i) - Trapeze_Rect(a, b, k * (i + 1)));
    } while (diff > eps);
    cout << "Значение интеграла для метода трапеций c точностью 1e-6:" << endl;
    cout << "k= " << k * (i + 1) << " " << "Trapeze_Rect= " << Trapeze_Rect(a, b, k * (i + 1)) << endl;
    
    cout << "Значение интеграла для симпсона  без заданной точности:" << endl;
    cout << "I=" << Sympson_Rect(a, b, n_point) << endl;
    do {
        i++;
        diff = fabs(Sympson_Rect(a, b, k * i) - Sympson_Rect(a, b, k * (i + 1)));
    } while (diff > eps);
    cout << "Значение интеграла для метода трапеций c точностью 1e-6:" << endl;
    cout << "k= " << k * (i + 1) << " " << "Sympson_Rect= " << Sympson_Rect(a, b, k * (i + 1))<< endl;

    cout << "Значение интеграла для метода средних прямоугольников" << endl;
    cout << "I=" << Midpoint_Rect(a, b, n_point) << endl;
    do {
        i++;
        diff = fabs(Midpoint_Rect(a, b, k * i) - Midpoint_Rect(a, b, k * (i + 1)));
    } while (diff > eps);
    cout << "Значение интеграла для метода средних прямоугольников с точностью 1e-6:" << endl;
    cout << "k= " << k * (i + 1) << " " << "Right_Rect= " << Midpoint_Rect(a, b, k * (i + 1)) << endl;


    return 0;

}