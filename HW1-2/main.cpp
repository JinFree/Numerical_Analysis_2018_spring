#include "main.h"
void bubblesort::sort(int _N) {
    N = _N;
    createArray();
    printArray(0);
    sorting();
    printArray(1);
    destroyArray();
    return;
}
void bubblesort::createArray() {
    A = (int *)malloc(N * sizeof(int));
    srand(time(NULL));
    for( int i = 0 ; i < N ; i++)
    {
        A[i] = rand()%N;
    }
}
void bubblesort::destroyArray() {
    free(A);
}
void bubblesort::printArray(int flag) {
    // flag == 0 : before sort
    // else flags : after sort
    FILE *file;
    char name[50];
    if(flag == 0)
        sprintf(name, "Array before sort.csv");
    else
        sprintf(name, "Array after sort.csv");
    file = fopen(name, "w");
    fprintf(file, "number, position\n");
    for(int i = 0 ; i < N ; i++)
    {
        fprintf(file, "%d,%d\n", A[i], i);
        printf("%d\n", A[i]);
    }
    fclose(file);
}
void bubblesort::sorting() {

}
int main(void) {
    bubblesort HW1_2;
    HW1_2.sort(20);
    return 0;
}