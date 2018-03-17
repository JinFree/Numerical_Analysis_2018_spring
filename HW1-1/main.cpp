#include "main.h"
void Euler::ComputeEuler(double _dt) {
    dt = _dt;
    ComputeEuler();
}
void Euler::ComputeEuler() {
    setup();
    paraopen();
    parawrite();
    do{
        function();
        timemarch();
        printstat();
        parawrite();
    }while(time < tmax);
    printf("\n");
    paraclose();
}
void Euler::printexact() {
    FILE *exact;
    char name[50];
    sprintf(name, "Euler, exact.csv");
    exact = fopen(name, "w");
    fprintf(exact, "time,T\n");
    for(time = t0 ; time <= tmax ; time+=0.5)
    {
        T=50*exp((-19)*time/(1000))+20;
        fprintf(exact, "%.1f,%lf\n",time,T);
        printf("\rexact, time=%.2f, T=%lf", time, T);
    }
    printf("\n");
    fclose(exact);
    return;
}
void Euler::setup() {
    time = t0;
    T=T0;
}
void Euler::function() {
    Tnew = T + k * dt * (Ta-T);
}
void Euler::timemarch() {
    time += dt;
    T = Tnew;
}
void Euler::paraopen() {
    char name[50];
    sprintf(name, "Euler, dt=%.1f.csv", dt);
    file = fopen(name, "w");
    fprintf(file, "time,T\n");
}
void Euler::parawrite() {
    fprintf(file, "%.1f,%lf\n",time,T);
}
void Euler::paraclose() {
    fclose(file);
}
void Euler::printstat() {
    printf("\rdt = %.2f, time=%.2f, T=%f",dt, time,T);
}
int main(void) {
	Euler HW1_1;
    HW1_1.printexact();
    HW1_1.ComputeEuler(0.5);
    HW1_1.ComputeEuler(1);
    HW1_1.ComputeEuler(2);
    return 0;
}