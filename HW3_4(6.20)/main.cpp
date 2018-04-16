#include "main.h"
double hw4::gx(double _x) {
    double x = _x;
    return (pow(n*Q,0.6)*pow(B+2*x,0.4))/(B*pow(S,0.3));
}
double hw4::error() {
    return (fabs(Hnew-H)/Hnew)*100;
}
void hw4::FixedPointMethod(double initial) {
    H = initial;
    int iter = 0;
    double err;
    do{
        Hnew = gx(H);
        iter++;
        err = error();
        printf("iter = %d, x = %f, f(x) = %f, error=%f\n",iter, Hnew, gx(Hnew),err);
        H = Hnew;
    }while(err > 0.000001);
}
int main() {
    hw4 hw;
    hw.FixedPointMethod(0);
    return 0;
}