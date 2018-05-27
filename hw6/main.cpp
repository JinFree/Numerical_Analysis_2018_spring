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
    result = (4.0/27.0) * (
           F(x0, y0, z0) + 4.0 * F(x1, y0, z0) + F(x2, y0, z0) +
    4.0 * (F(x0, y1, z0) + 4.0 * F(x1, y1, z0) + F(x2, y1, z0))+
           F(x0, y2, z0) + 4.0 * F(x1, y2, z0) + F(x2, y2, z0) +
    4.0 * (F(x0, y0, z1) + 4.0 * F(x1, y0, z1) + F(x2, y0, z1) +
    4.0 * (F(x0, y1, z1) + 4.0 * F(x1, y1, z1) + F(x2, y1, z1))+
           F(x0, y2, z1) + 4.0 * F(x1, y2, z1) + F(x2, y2, z1))+
           F(x0, y0, z2) + 4.0 * F(x1, y0, z2) + F(x2, y0, z2) +
    4.0 * (F(x0, y1, z2) + 4.0 * F(x1, y1, z2) + F(x2, y1, z2))+
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
    result = f00 + 4.0 * f02 + f04 +
      3.0 * (f40 + 4.0 * f42 + f44)+
      3.0 * (f80 + 4.0 * f82 + f84)+
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
    for( i = 0 ; i < 5 ; i++) {
        int pos = 2 * i + 1;
        ResultS += (2.0/3.0)*(F[pos-1]+4.0*F[pos]+F[pos+1]);
    }
}
void hw2417::Trapezoidal(double *F) {
    int i;
    ResultT1 = 0;
    ResultT2 = 0;
    for(i = 0 ; i < 10 ; i++) {
        int pos = i;
        ResultT1 += F[pos] + F[pos+1];
    }
    for(i = 0 ; i < 5 ; i++) {
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
    _a = 0;
    _b = 30;
    _n = 6;
    ResultT = Trapezoidal(_n, _a, _b);
    ResultS = Simpsons13(_n, _a, _b);
    ResultG = GaussQuadrature(_a, _b);
    ResultR = Romberg(_a, _b, 3);
    printf("\nProb 24.46\n");
    printf("Trapezoidal, Result is %.6f\n", ResultT);
    printf("Simpson's 1/3, Result is %.6f\n", ResultS);
    printf("Gauss quadrature, Result is %.6f\n", ResultG);
    printf("O(h^8) Romberg, Result is %.6f\n", ResultR);
    Differentiation();
}
double hw2446::Trapezoidal(int n, int a, int b) {
    double h = double(b - a)/(double)n;
    double x = a;
    double sum = F(x);
    for (int i = 1 ; i < n ; i++) {
        x = x+h;
        sum += 2 * F(x);
    }
    sum += F(b);
    return h * 0.5 * sum;
}
double hw2446::Simpsons13(int n, int a, int b) {
    double h = double(b - a)/(double)n;
    double x = a;
    double sum = F(x);
    for ( int i = 1 ; i < n ; i++) {
        x = x+h;
        if(i%2 ==1)
            sum += 4.0*F(x);
        else
            sum += 2.0*F(x);
    }
    sum += F(b);
    return sum * h / 3.0;
}
double hw2446::GaussQuadrature(int a, int b) {
    double C[6] = {
            0.1713245,
            0.3607616,
            0.4679139,
            0.4679139,
            0.3607616,
            0.1713245
    };
    double X[6] = {
            -0.932469514,
            -0.661209386,
            -0.238619186,
            0.238619186,
            0.661209386,
            0.932469514
    };
    double m = -0.5*a + 0.5*b;
    double c = 0.5*a + 0.5*b;
    double sum = 0;
    for( int i=0;i<6;i++) {
        sum += C[i] * F(m*X[i]+c);
    }
    return m*sum;
}
double hw2446::Romberg(int a, int b, int maxit) {
    double I[4][4];
    int n = 1;
    I[0][0] = Trapezoidal(n, a, b);
    int iter = 0;
    do{
        iter++;
        n = (int)pow(2.0, (double)iter);
        I[iter][0] = Trapezoidal(n, a, b);
        for (int k=2; k<=iter+1;k++) {
            int j = 2 + iter - k;
            I[j-1][k-1] = (pow(4.0,double(k-1))*I[j][k-2]-I[j-1][k-2])/(pow(4.0,double(k-1))-1.0);
        }
    }while(iter < maxit);
    return I[0][iter];
}
void hw2446::Differentiation() {
    FILE *fp;
    char name[50];
    sprintf(name, "Acceleration vs Time.csv");
    fp = fopen(name, "w");
    fprintf(fp, "Acceleration,Time\n");
    double t_end = 30.0;
    double dt = 0.1;
    int t_step = (int)(t_end/dt);
    for(int i= 0 ; i < t_step ; i++) {
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