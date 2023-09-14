#include <iostream>
#include <math.h>

using namespace std;

template <typename T> T average(T a[], int size)
{
    int c = 0;
    float s = 0;
    for (int i = 0; i < size; i++) {
        s += a[i];
        c++;
    }
    return s / c;
}

template <typename A1> A1 res(A1 a, A1 b)
{
    double x = -b / a;
    return x;
}
template <typename A2> A2 res(A2 a, A2 b, A2 c)
{
    double D = pow(b, 2) - 4 * a * c;
    if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Res (a*x*x+b*x+c = 0) = " << x1 << " and " << x2 << endl;
    }
    else if (D == 0) {
        double x = -b / (2 * a);
        cout << "Res (a*x*x+b*x+c = 0) = " << x << endl;
    }
    else {
        cout << "D < 0 or something wrong!" << endl;
    }
    return 0;
}
double rounding(double num, int c)
{
    double res;
    for (int i = 0; i <= c; i++) {
        num *= 10;
    }
    int temp = num;
    if ((int)num % 10 >= 5) {
        temp /= 10;
        temp++;
        num = temp;
        for (int j = 0; j < c; j++) {
            num /= 10;
        }
        res = num;
    }
    else if ((int)num % 10 < 5) {
        temp /= 10;
        num = temp;
        for (int j = 0; j < c; j++) {
            num /= 10;
        }
        res = num;
    }
    else {
        cout << "Something wrong!";
    }
    return res;
}

int main()
{
    //1
    const int size = 5;
    float ar[size] = { 0 };
    for (int i = 0; i < size; i++)
    {
        cout << "Enter first number: ";
        cin >> ar[i];
    }
    cout << average(ar, size) << endl;
    //2
    double a;
    cout << "Enter a: ";
    cin >> a;
    double b;
    cout << "Enter b: ";
    cin >> b;
    cout << "Res (a*x+b = 0) = " << res(a, b) << endl;
    double a1;
    cout << "Enter a: ";
    cin >> a1;
    double b1;
    cout << "Enter b: ";
    cin >> b1;
    double c1;
    cout << "Enter c: ";
    cin >> c1;
    res(a, b, c1);
    //3
    double num;
    cout << "Enter number: ";
    cin >> num;
    int q;
    cout << "How many digits after dot: ";
    cin >> q;
    cout << "Res = " << rounding(num, q) << endl;
}
