#include "main.h"
double hw4::fx(double _x) {
    double x = _x;
    return (sqrt(S)*pow(B*x, 5/3))/(n*pow((B+2*x),2/3))-Q;
}
double hw4::error() {
    if(fabs(fx(Hnew)) <= 0.000001)
        return 0;
    return fabs((fx(Hnew)-fx(H))/fx(Hnew))*100;
}
void hw4::fpx(double _x) {
    double x = _x;
    double fp = (fx(x*1.01)-fx(x*0.99))/(2*(x*0.02));
    printf("fpx = %.3f\n",fp);
}
void hw4::SecantMethod(double initial) {
    Hold = initial;
    int iter = 0;
    double err = 0;
    H = Hold*1.1+0.01;
    do{
        Hnew = H - (fx(H)*(Hold-H))/(fx(Hold)-fx(H));
        iter++;
        err = error();
        printf("iter = %d, x = %.3f, f(x) = %.3f, error=%.3f %%\n",iter, Hnew, fx(Hnew),err);
        Hold = H;
        H = Hnew;
    }while(err > 0.01);
}
int main() {
    hw4 hw;
    hw.SecantMethod(rand());
    for( int i = 1 ; i < 100 ; i++)
        hw.fpx(i*1.01);
    return 0;
}