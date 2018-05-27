#include "main.h"
double hw2115::Compute() {
    x0 = -3.0;
    x2 = 1.0;
    x1 = 0.5*(x0+x2);
    y0 = 0.0;
    y2 = 2.0;
    y1 = 0.5*(y0+y2);
    z0 = -2.0;
    z2 = 2.0;
    z1 = 0.5*(z0+z2);
    double exact = -160.0;
    TripleIntegral13();
    printf("\nProb 21.15\n");
    printf("Result is %.6f\n", result);
    Error(exact);
    return result;
}
void hw2115::TripleIntegral13() {
    result = (4.0/27.0) * (\
           F(x0, y0, z0) + 4.0 * F(x1, y0, z0) + F(x2, y0, z0) +\
    4.0 * (F(x0, y1, z0) + 4.0 * F(x1, y1, z0) + F(x2, y1, z0))+\
           F(x0, y2, z0) + 4.0 * F(x1, y2, z0) + F(x2, y2, z0) +\
    4.0 * (F(x0, y0, z1) + 4.0 * F(x1, y0, z1) + F(x2, y0, z1) +\
    4.0 * (F(x0, y1, z1) + 4.0 * F(x1, y1, z1) + F(x2, y1, z1))+\
           F(x0, y2, z1) + 4.0 * F(x1, y2, z1) + F(x2, y2, z1))+\
           F(x0, y0, z2) + 4.0 * F(x1, y0, z2) + F(x2, y0, z2) +\
    4.0 * (F(x0, y1, z2) + 4.0 * F(x1, y1, z2) + F(x2, y1, z2))+\
           F(x0, y2, z2) + 4.0 * F(x1, y2, z2) + F(x2, y2, z2));
}
double hw2115::F(double x, double y, double z) {
    return x*x*x-3.0*y*z;
}
void hw2115::Error(double exact) {
    error = (exact - result)/exact * 100.0;
    printf("Error is %.6f\n", error);
}

double hw2126::Compute() {
    f00 = -2.0;
    f40 = -1.0;
    f80 = 4.0;
    f120 = 10.0;
    f02 = -4.0;
    f42 = -3.0;
    f82 = 1.0;
    f122 = 7.0;
    f04 = -8.0;
    f44 = -8.0;
    f84 = -6.0;
    f124 = 4.0;
    DoubleIntegral();
    result = result / 48.0;
    printf("\nProb 21.26\n");
    printf("Result is %.6f\n", result);
    return result;
}
void hw2126::DoubleIntegral() {
    result = f00 + 4.0 * f02 + f04 + \
      3.0 * (f40 + 4.0 * f42 + f44)+ \
      3.0 * (f80 + 4.0 * f82 + f84)+ \
             f120 + 4.0 * f122 + f124;
}

void hw2417::Compute() {
    double F[11] = {0, 1.8, 2, 4, 4, 6, 4, 3.6, 3.4, 2.8, 0};
    Trapezoidal(F);
    Simpsons13(F);
    printf("\nProb 24.17\n");
    printf("Trapezoidal h=4, Result is %.6f\n", ResultT2);
    printf("Trapezoidal h=2, Result is %.6f\n", ResultT1);
    printf("Simpson's 1/3 h=2, Result is %.6f\n", ResultS);
}
void hw2417::Simpsons13(double *F) {
    int i;
    ResultS = 0;
    for( i = 0 ; i < 5 ; i++)
    {
        int pos = 2 * i + 1;
        ResultS += (2.0/3.0)*(F[pos-1]+4.0*F[pos]+F[pos+1]);
    }
}
void hw2417::Trapezoidal(double *F) {
    int i;
    ResultT1 = 0;
    ResultT2 = 0;
    for(i = 0 ; i < 10 ; i++)
    {
        int pos = i;
        ResultT1 += F[pos] + F[pos+1];
    }
    for(i = 0 ; i < 5 ; i++)
    {
        int pos = 2 * i + 1;
        ResultT2 += 2.0*(F[pos+1]+F[pos-1]);
    }
}

void hw2446::Compute() {
    u = 1800;
    m = 160000;
    q = 2500;
    g = 9.8;
    ResultT=0.0;
    ResultS=0.0;
    ResultG=0.0;
    ResultR=0.0;
    a = 0;
    b = 30;
    n = 6;
    h = (b-a)/n;
    Trapezoidal();
    Simpsons13();
    GaussQuadrature();
    Romberg();
    printf("\nProb 24.46\n");
    printf("Trapezoidal, Result is %.6f\n", ResultT);
    printf("Simpson's 1/3, Result is %.6f\n", ResultS);
    printf("Gauss quadrature, Result is %.6f\n", ResultG);
    printf("O(h^8) Romberg, Result is %.6f\n", ResultR);
    Differentiation();
}
void hw2446::Trapezoidal() {
    int i=0;
    ResultT = F(i*h);
    for( i = 1 ; i < n ; i++)
    {
        ResultT += 2.0* F(i*h);
    }
    ResultT += F(i*h);
    ResultT = 0.5*h*ResultT;
}
void hw2446::Simpsons13() {
    int i = 0;
    ResultS = F(i*h);
    for ( i = 1 ; i < n ; i++)
    {
        if(i%2 ==1)
            ResultS += 4.0*F(i*h);
        else
            ResultS += 2.0*F(i*h);
    }
    ResultS += F(i*h);
    ResultS = ResultS*h/3.0;
}
void hw2446::GaussQuadrature() {

}
void hw2446::Romberg() {

}
void hw2446::Differentiation() {
    FILE *fp;
    char name[50];
    sprintf(name, "Acceleration vs Time.csv");
    fp = fopen(name, "w");
    fprintf(fp, "Acceleration,Time\n");
    double t_end = 30.0;
    double dt = 0.1;
    int t_step = t_end/dt;
    for(int i= 0 ; i < t_step ; i++)
    {
        double t = i*dt;
        double a = (F(t+dt)-F(t))/dt;
        fprintf(fp, "%f,%f\n", a, t);
    }
    fclose(fp);
}
double hw2446::F(double t) {
    return u*log(m/(m-q*t))-g*t;
}
int main() {
    hw2115 hw1;
    hw1.Compute();

    hw2126 hw2;
    hw2.Compute();

    hw2417 hw3;
    hw3.Compute();

    hw2446 hw4;
    hw4.Compute();
    return 0;
}