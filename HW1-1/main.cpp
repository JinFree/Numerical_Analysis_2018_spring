#include "main.h"
void Euler::setup()
{
    time = t0;
    T=T0;
}
void Euler::function()
{
    Tnew = T + k * dt * (Ta-T);
    return;
}
void Euler::timemarch()
{
    time += dt;
    T = Tnew;
    return;
}
void Euler::paraopen()
{
    char name[50];
    sprintf(name, "Euler, dt=%.1f.csv", dt);
    file = fopen(name, "w");
    fprintf(file, "time,T\n");
    return;
}
void Euler::parawrite()
{
    fprintf(file, "%.1f,%lf\n",time,T);
}
void Euler::paraclose()
{
    fclose(file);
    return;
}
void Euler::printstat()
{
    printf("\rtime=%.2f, T=%f",time,T);
}
Euler::Euler(double _dt)
{
    dt = _dt;
    ComputeEuler();
    return;
}
void Euler::ComputeEuler(double _dt)
{
    dt = _dt;
    ComputeEuler();
    return;
}
void Euler::ComputeEuler()
{
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
    return;
}
void Euler::printexact() {
    FILE *exact;
    char name[50];
    sprintf(name, "Euler, exact.csv", dt);
    exact = fopen(name, "w");
    fprintf(exact, "time,T\n");
    for(time = t0 ; time <= tmax ; time+=dt)
    {
        T=50*exp((-19)*time/(1000))+20;
        fprintf(exact, "%.1f,%lf\n",time,T);
    }
    fclose(exact);
    return;
}
int main(void)
{
	Euler hw1(0.5);
    hw1.ComputeEuler(1);
    hw1.ComputeEuler(2);
    hw1.printexact();
    return 0;
}