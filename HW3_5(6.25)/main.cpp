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
    if(fabs(fx(cnew)) <= 0.000001)
        return 0;
    return fabs((fx(cnew)-fx(c))/fx(cnew))*100;
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
    FILE *file;
    char name[50];
    sprintf(name, "Function.csv");
    file = fopen(name, "w");
    fprintf(file, "c,dcdt\n");
    for(int i = 0 ; i < 1000 ; i++)
    {
        double x = (i-200)*0.1;
        double fx = 1-0.1*x-0.25*sqrt(x);
        fprintf(file, "%f,%f\n",x,fx);
    }
    fclose(file);
    return 0;
}