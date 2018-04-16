#include "main.h"
double hw2::fx(double _x) {
    double x = _x;
    return tanh(pow(x,2)-9);
}
double hw2::fpx(double _x) {
    double x = _x;
    return -1.0* 2.0 * x * (pow(fx(x),2)-1.0);
}
void hw2::NewtonRaphson() {
    int iter = 0;
    xold = x0;
    do{
        xnew = xold - fx(xold)/fpx(xold);
        iter++;
        printf("iter = %d, x = %.3f, f(x) = %.3f, f'(x) = %.3f\n",iter, xnew, fx(xnew), fpx(xnew));
        xold = xnew;
    }while((iter < MinIter));
}
int main() {
    hw2 hw;
    hw.NewtonRaphson();
    return 0;
}