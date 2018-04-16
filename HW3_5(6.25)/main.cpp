#include "main.h"
double hw5::fx(double _x) {
    double x = _x;
    return 1-0.1*x-0.25*sqrt(x);
}
double hw5::fpx(double _x) {
    double x = _x;
    return (fx(x * (1 + delta)) - fx(x))/(delta * x);
}
double hw5::error() {
    return fabs((cnew-c)/(cnew))*100;
}
void hw5::ModifiedSecantMethod(double initial) {
    int iter = 0;
    double err = 0;
    c = initial;
    do{
        cnew = c - fx(c)/fpx(c);
        iter++;
        err = error();
        printf("iter = %d, x = %f, f(x) = %f, f'(x) = %f, error = %f %%\n",iter, cnew, fx(cnew), fpx(cnew), err);
        c = cnew;
    }while((iter < MinIter));
}
int main() {
    hw5 hw;
    hw.ModifiedSecantMethod(4);
    return 0;
}