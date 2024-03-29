/* Runge Kutta Method */
#include <iostream>
#include <iomanip>
using namespace std;
// Define function
float f(float x, float y)
{
    return x + y;
}
int main()
{
    float x0, y0, h, xn, x, y, k1, k2, k3, k4, k;

    cout << "Enter the initial values of x0, y0, height difference , xn" << endl;
    cin >> x0 >> y0 >> h >> xn;
    if (h == 0)
    {
        cout << "Error: Step size (h) cannot be zero." << endl;
        return 1;
    }
    x = x0;
    y = y0;

    cout << fixed;

    while (true)
    {
        if (x == xn)
        {
            break;
        }
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);
        k = (k1 + 2 * (k2 + k3) + k4) / 6;
        x += h;
        y += k;
        cout << "When x = " << setprecision(4) << setw(8) << x
             << "  Y = " << setw(8) << y << endl;
    }
    return 0;
}
