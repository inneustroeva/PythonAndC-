//Complex numbers
#include <iostream>
#include <math.h>
#include <complex>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n, k;
    double real, imag, z_real, z_imag, n_rt, dn_rt;
    const double M_PI = 3.14;
    complex< double > z(-1.0, 2.0);
    complex< double > z1(-1.0, 1.0);
    complex< double > z2(-3.0, 2.0);

    cout << "z=" << z << endl; // ����������� ����� ��������� � ���� �������
    cout << "z^sopr=" << conj(z) << endl; // ����������-�����������
    cout << "Re z=" << z.real() << endl; // �������������� ����� ������������ �����
    cout << "Im z=" << z.imag() << endl; // ������ ����� ������������ �����
    cout << "z1 + z2=" << z1 + z2 << endl; // �������� ����������� �����
    cout << "z1 - z2=" << z1 - z2 << endl; // �������� ����������� �����
    cout << "z1 * z2=" << z1 * z2 << endl; // ��������� ����������� �����
    cout << "z1 / z2=" << z1 / z2 << endl; // ������� ����������� �����
    cout << "z^4=" << pow(z, 4) << endl; // ���������� � ������� ������������ �����
    double rho = abs(z); // ������ ������������ �����
    double phi = arg(z); // �������� ������������ �����
    // ������������������ ����� ������������ �����
    cout << "z=" << rho << "*(cos(" << phi << ") + i*sin(" << phi << "))" << endl;
    // ������������� ����� ������������ �����
    cout << "z=" << rho << "*exp(i*" << phi << ")" << endl;
    // �������� �������� ����������� ����� �� ������ � ���������
    cout << "z=" << polar(rho, phi) << endl;


    // ���������� ����� n ������� �� ������������ �����
    cout << "Input complex number ";
    cin >> real >> imag; // ���� �������������� � ������ ����� ����� ������
    complex<double> zp(real, imag);
    cout << fixed << setprecision(16) << zp << endl;
    cout << "Input number n_root ";
    cin >> n_rt;
    cout << "\n";
    rho = abs(zp);
    phi = arg(zp);
    cout << "rho=" << rho << ", phi=" << phi << endl;
    dn_rt = 1.0 / n_rt;
    for (k = 0; k < n_rt; k++)
    {
        z_real = pow(rho, float(1 / n_rt)) * cos((phi + 2 * M_PI * k) / n_rt);
        z_imag = pow(rho, float(1 / n_rt)) * sin((phi + 2 * M_PI * k) / n_rt);
        complex<double> z_n(z_real, z_imag);
        cout << "k=" << k << ", z_k=" << z_n << "\n";
    }


    return 0;
}