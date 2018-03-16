#include "main.h"
void bubblesort::sort(int _N) {
    N = _N;
    createArray();
    printArray(0);
    sorting();
    printArray(1);
    destroyArray();
}
void bubblesort::createArray() {
    A = (int *)malloc(N * sizeof(int));
    srand(time(NULL));
    for( int i = 0 ; i < N ; i++)
        A[i] = rand()%(3*N);
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
    fprintf(file, "position, number\n");
    for(int i = 0 ; i < N ; i++)
        fprintf(file, "%d,%d\n", i, A[i]);
    fclose(file);
}
void bubblesort::sorting() {
    int m = N;
    bool check;
    do{
        check = false;
        m = m-1;
        for ( int i = 0 ; i < m ; i++)
        {
            if(A[i] > A[i+1])
            {
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1]=temp;
                check = true;
            }
        }
    }while(check == true);
}
int main(void) {
    bubblesort HW1_2;
    HW1_2.sort(20);
    return 0;
}