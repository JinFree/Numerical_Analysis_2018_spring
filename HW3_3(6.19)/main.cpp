#include "main.h"
double hw3::fx(double _x) {
    double x = _x;
    return pi * x * x * (3 * R - x) / 3 - 30;
}
double hw3::fpx(double _x) {
    double x = _x;
    return (pi * x * (6 * R - 3 * x)) / 3;
}
double hw3::error() {
    if(fabs(fx(xnew)) <= 0.000001)
        return 0;
    return fabs((fx(xnew)-fx(xold))/fx(xnew));
}
void hw3::NewtonRaphson() {
    int iter = 0;
    double err = 0;
    xold = x0;
    do{
        xnew = xold - fx(xold)/fpx(xold);
        iter++;
        err = error();
        printf("iter = %d, x = %f, f(x) = %f, f'(x) = %f, error=%f %%\n",iter, xnew, fx(xnew), fpx(xnew),err);
        xold = xnew;
    }while((iter < MinIter));
}
int main() {
    hw3 hw;
    hw.NewtonRaphson();
    return 0;
}