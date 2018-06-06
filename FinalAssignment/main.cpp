#include "main.h"
void Prob1::Compute(double _dt, double _t_end) {
    dx = _dt;
    x_end = _t_end;
    int n = 2;
    double rho = 1.3;
    double d = 0.22;
    double A = M_PI * d * d;
    double Cd = 0.52;
    cd = 0.5*rho*A*Cd;
    double xi = 0.0;
    double* yi = (double *)malloc(n * sizeof(double));
    yi[0] = 40.0;
    yi[1] = 0.0;
    sprintf(name, "Prob25.25, dt=%.3f.csv", dx);
    double xf = RK4Main(n, xi, yi, x_end, dx);
    printf("\nProb 25.25\n");
    printf("Time = %fs\n", xf);
    printf("Velocity = %f\n", yi[0]);
    printf("Height = %f\n", yi[1]);
    free(yi);
}
double Prob1::RK4Main(int n, double xi, double *yi, double x_end, double dx) {
    double x = xi;
    int iter = 0;
    FILE *file;
    file = fopen(name, "w");
    fprintf(file, "Time,Velocity,Height\n");
    double* y = (double *)malloc(n * sizeof(double));
    for(int i = 0 ; i < n ; i++) {
        y[i] = yi[i];
    }
    fprintf(file, "%f,%f,%f\n", x, y[0], y[1]);
    do{
        double h = dx;
        x = Integrator(x, y, n, h, x_end);
        iter++;
        fprintf(file, "%f,%f,%f\n", x, y[0], y[1]);
    }while((x < x_end) && (y[1]>0.0));
    for(int i = 0 ; i < n ; i++) {
        yi[i] = y[i];
    }
    free(y);
    return x;
}
double Prob1::Integrator(double x, double *y, int n, double h, double x_end) {
    if( x_end - x < h)
        h = x_end - x;
    x = RK4(x, y, n, h);
    return x;
}
double Prob1::RK4(double x, double *y, int n, double h) {
    double* k1 = (double *)malloc(n * sizeof(double));
    double* k2 = (double *)malloc(n * sizeof(double));
    double* k3 = (double *)malloc(n * sizeof(double));
    double* k4 = (double *)malloc(n * sizeof(double));
    double* ym = (double *)malloc(n * sizeof(double));
    double* ye = (double *)malloc(n * sizeof(double));
    double* slope = (double *)malloc(n * sizeof(double));
    int i;
    Derivs(x, y, k1);
    for(i = 0 ; i < n ; i++) {
        ym[i] = y[i] + k1[i] * 0.5 * h;
    }
    Derivs(x + 0.5 * h, ym, k2);
    for(i = 0 ; i < n ; i++) {
        ym[i] = y[i] + k2[i] * 0.5 * h;
    }
    Derivs(x + 0.5 * h, ym, k3);
    for(i = 0 ; i < n ; i++) {
        ye[i] = y[i] + k3[i] * h;
    }
    Derivs(x + h, ye, k4);
    for( i = 0 ; i < n ; i++) {
        slope[i] = (k1[i] + 2.0 * (k2[i] + k3[i]) + k4[i])/6.0;
        y[i] = y[i] + slope[i] * h;
    }
    free(k1);
    free(k2);
    free(k3);
    free(k4);
    free(ym);
    free(ye);
    free(slope);
    return x+h;
}
void Prob1::Derivs(double x, double *y, double *dy) {
    double y1;
    y1 = y[0];
    dy[1] = y1;
    dy[0] = -g-(cd/m)*y1*abs(y1);
}
void Prob2::Compute(double _dt, double _t_end) {
    dx = _dt;
    x_end = _t_end;
    int n = 2;
    double xi = 0.0;
    double* yi = (double *)malloc(n * sizeof(double));
    yi[0] = 0.0;
    yi[1] = 0.25;
    sprintf(name, "Prob26.13, dt=%.3f.csv", dx);
    double xf = RK4Main(n, xi, yi, x_end, dx);
    printf("\nProb 26.13\n");
    printf("t_end = %fs\n", xf);
    printf("Rad = %f\n", yi[0]);
    printf("Rad/s = %f\n", yi[1]);
    free(yi);
}
double Prob2::RK4Main(int n, double xi, double *yi, double x_end, double dx) {
    double x = xi;
    int iter = 0;
    FILE *file;
    file = fopen(name, "w");
    fprintf(file, "Time,Rad,Rad/s\n");
    double* y = (double *)malloc(n * sizeof(double));
    for(int i = 0 ; i < n ; i++) {
        y[i] = yi[i];
    }
    fprintf(file, "%f,%f,%f\n", x, y[0], y[1]);
    do{
        double h = dx;
        x = Integrator(x, y, n, h, x_end);
        iter++;
        fprintf(file, "%f,%f,%f\n", x, y[0], y[1]);
    }while((x < x_end) && (y[0]<M_PI*0.5));
    for(int i = 0 ; i < n ; i++) {
        yi[i] = y[i];
    }
    free(y);
    return x;
}
double Prob2::Integrator(double x, double *y, int n, double h, double x_end) {
    if( x_end - x < h)
        h = x_end - x;
    x = RK4(x, y, n, h);
    return x;
}
double Prob2::RK4(double x, double *y, int n, double h) {
    double* k1 = (double *)malloc(n * sizeof(double));
    double* k2 = (double *)malloc(n * sizeof(double));
    double* k3 = (double *)malloc(n * sizeof(double));
    double* k4 = (double *)malloc(n * sizeof(double));
    double* ym = (double *)malloc(n * sizeof(double));
    double* ye = (double *)malloc(n * sizeof(double));
    double* slope = (double *)malloc(n * sizeof(double));
    int i;
    Derivs(x, y, k1);
    for(i = 0 ; i < n ; i++) {
        ym[i] = y[i] + k1[i] * 0.5 * h;
    }
    Derivs(x + 0.5 * h, ym, k2);
    for(i = 0 ; i < n ; i++) {
        ym[i] = y[i] + k2[i] * 0.5 * h;
    }
    Derivs(x + 0.5 * h, ym, k3);
    for(i = 0 ; i < n ; i++) {
        ye[i] = y[i] + k3[i] * h;
    }
    Derivs(x + h, ye, k4);
    for( i = 0 ; i < n ; i++) {
        slope[i] = (k1[i] + 2.0 * (k2[i] + k3[i]) + k4[i])/6.0;
        y[i] = y[i] + slope[i] * h;
    }
    free(k1);
    free(k2);
    free(k3);
    free(k4);
    free(ym);
    free(ye);
    free(slope);
    return x+h;
}
void Prob2::Derivs(double x, double *y, double *dy) {
    double y1, y2;
    y1 = y[0];
    y2 = y[1];
    dy[0] = y2;
    dy[1] = g/l*y1;
}
void Prob3::Compute(double _dt) {
    dx = _dt;
    x_end = L;
    int n = 2;
    double xi = 0.0;
    double* yi = (double *)malloc(n * sizeof(double));
    yi[0] = 0.0;
    yi[1] = 0.0;
    sprintf(name, "Prob28.26, dx=%.3f.csv", dx);
    double xf = RK4Main(n, xi, yi, x_end, dx);
    printf("\nProb 28.26\n");
    printf("x_end = %fm\n", xf);
    printf("y_numerical = %.13fm\n", yi[0]);
    printf("y_analytical = %.13fm\n", yi[1]);
    printf("relative_error = %.13f\n", Error(yi[0],yi[1]));
    free(yi);
}
double Prob3::RK4Main(int n, double xi, double *yi, double x_end, double dx) {
    double x = xi;
    int iter = 0;
    FILE *file;
    file = fopen(name, "w");
    fprintf(file, "x,y_numerical,y_analytical,relative_error\n");
    double* y = (double *)malloc(n * sizeof(double));
    for(int i = 0 ; i < n ; i++) {
        y[i] = yi[i];
    }
    double y_a = Analytical(x);
    fprintf(file, "%f,%.13f,%.13f,%.13f\n", x, y[0], y_a, Error(y[0],y_a));
    do{
        double h = dx;
        x = Integrator(x, y, n, h, x_end);
        iter++;
        y_a = Analytical(x);
        fprintf(file, "%.13f,%.13f,%.13f,%.13f\n", x, y[0], y_a, Error(y[0],y_a));
    }while((x < x_end));
    yi[0]=y[0];
    yi[1]=Analytical(x);
    free(y);
    return x;
}
double Prob3::Integrator(double x, double *y, int n, double h, double x_end) {
    if( x_end - x < h)
        h = x_end - x;
    x = RK4(x, y, n, h);
    return x;
}
double Prob3::RK4(double x, double *y, int n, double h) {
    double* k1 = (double *)malloc(n * sizeof(double));
    double* k2 = (double *)malloc(n * sizeof(double));
    double* k3 = (double *)malloc(n * sizeof(double));
    double* k4 = (double *)malloc(n * sizeof(double));
    double* ym = (double *)malloc(n * sizeof(double));
    double* ye = (double *)malloc(n * sizeof(double));
    double* slope = (double *)malloc(n * sizeof(double));
    int i;
    Derivs(x, y, k1);
    for(i = 0 ; i < n ; i++) {
        ym[i] = y[i] + k1[i] * 0.5 * h;
    }
    Derivs(x + 0.5 * h, ym, k2);
    for(i = 0 ; i < n ; i++) {
        ym[i] = y[i] + k2[i] * 0.5 * h;
    }
    Derivs(x + 0.5 * h, ym, k3);
    for(i = 0 ; i < n ; i++) {
        ye[i] = y[i] + k3[i] * h;
    }
    Derivs(x + h, ye, k4);
    for( i = 0 ; i < n ; i++) {
        slope[i] = (k1[i] + 2.0 * (k2[i] + k3[i]) + k4[i])/6.0;
        y[i] = y[i] + slope[i] * h;
    }
    free(k1);
    free(k2);
    free(k3);
    free(k4);
    free(ym);
    free(ye);
    free(slope);
    return x+h;
}
void Prob3::Derivs(double x, double *y, double *dy) {
    double y1, y2;
    y1 = y[0];
    y2 = y[1];
    dy[0] = y2;
    dy[1] = (-P/(E*I))*(L-x);
}
double Prob3::Analytical(double x) {
    return (P*x*x)/(2.0*E*I)*(-1.0*L + x / 3.0);
}
double Prob3::Error(double y_n, double y_a) {
    if(y_a == 0)
        return y_a-y_n;
    return (y_a-y_n)/y_a*100.0;
}

void Prob4::Compute(double _dt, double _t_end) {
    dx = _dt;
    x_end = _t_end;
    int n = 1;
    double xi = 0.0;
    double* yi = (double *)malloc(n * sizeof(double));
    yi[0] = 6.0;
    sprintf(name, "Prob28.28, dt=%.3f.csv", dx);
    double xf = RK4Main(n, xi, yi, x_end, dx);
    printf("\nProb 28.28\n");
    printf("t_end = %fs\n", xf);
    printf("h = %f\n", yi[0]);
    free(yi);
}
double Prob4::RK4Main(int n, double xi, double *yi, double x_end, double dx) {
    double x = xi;
    int iter = 0;
    FILE *file;
    file = fopen(name, "w");
    fprintf(file, "Time,Height\n");
    double* y = (double *)malloc(n * sizeof(double));
    for(int i = 0 ; i < n ; i++) {
        y[i] = yi[i];
    }
    fprintf(file, "%f,%f\n", x, y[0]);
    do{
        double h = dx;
        x = Integrator(x, y, n, h, x_end);
        if(y[0] < 0.01) {
            y[0] = 0.0;
            break;
        }
        iter++;
        fprintf(file, "%f,%f\n", x, y[0]);
    }while(y[0]>=0.0);
    for(int i = 0 ; i < n ; i++) {
        yi[i] = y[i];
    }
    free(y);
    return x;
}
double Prob4::Integrator(double x, double *y, int n, double h, double x_end) {
    if( x_end - x < h)
        h = x_end - x;
    x = RK4(x, y, n, h);
    return x;
}
double Prob4::RK4(double x, double *y, int n, double h) {
    double* k1 = (double *)malloc(n * sizeof(double));
    double* k2 = (double *)malloc(n * sizeof(double));
    double* k3 = (double *)malloc(n * sizeof(double));
    double* k4 = (double *)malloc(n * sizeof(double));
    double* ym = (double *)malloc(n * sizeof(double));
    double* ye = (double *)malloc(n * sizeof(double));
    double* slope = (double *)malloc(n * sizeof(double));
    int i;
    Derivs(x, y, k1);
    for(i = 0 ; i < n ; i++) {
        ym[i] = y[i] + k1[i] * 0.5 * h;
    }
    Derivs(x + 0.5 * h, ym, k2);
    for(i = 0 ; i < n ; i++) {
        ym[i] = y[i] + k2[i] * 0.5 * h;
    }
    Derivs(x + 0.5 * h, ym, k3);
    for(i = 0 ; i < n ; i++) {
        ye[i] = y[i] + k3[i] * h;
    }
    Derivs(x + h, ye, k4);
    for( i = 0 ; i < n ; i++) {
        slope[i] = (k1[i] + 2.0 * (k2[i] + k3[i]) + k4[i])/6.0;
        y[i] = y[i] + slope[i] * h;
    }
    free(k1);
    free(k2);
    free(k3);
    free(k4);
    free(ym);
    free(ye);
    free(slope);
    return x+h;
}
void Prob4::Derivs(double x, double *y, double *dy) {
    double y1, y2;
    y1 = y[0];
    dy[0] = (-1.0*M_PI*d*d)/(4.0*Area(y1))*(sqrt(2.0*g*(y1+e)));
}
double Prob4::Area(double x) {
    IndexInit();
    for(int i = 0 ; i < 7 ; i++) {
        if((H[i]<=x+0.01)&&(x-0.01<=H[i+1])) {
            double x0, x1, y0, y1;
            x0 = H[i];
            x1 = H[i+1];
            y0 = A[i];
            y1 = A[i+1];
            return y0 + (y1-y0)/(x1-x0)*(x-x0);
        }
    }
    return 0;
}
void Prob4::IndexInit() {
    for(int i = 0 ; i < 7 ; i++) {
        H[i] = i;
    }
    A[0] = 0.0;
    A[1] = 0.18;
    A[2] = 0.32;
    A[3] = 0.45;
    A[4] = 0.67;
    A[5] = 0.97;
    A[6] = 1.17;
}
int main() {
    Prob1 Hw1;
    Hw1.Compute(0.01, 10);

    Prob2 Hw2;
    Hw2.Compute(0.01, 10);

    Prob3 Hw3;
    Hw3.Compute(0.01);

    Prob4 Hw4;
    Hw4.Compute(0.0001, 10);
    return 0;
}