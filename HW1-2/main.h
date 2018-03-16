//
// Created by 왕진영 on 2018. 3. 16..
//

#ifndef HW1_2_MAIN_H
#define HW1_2_MAIN_H
#include <cstdio>
#include <cstdlib>
#include <ctime>

#endif //HW1_2_MAIN_H
class bubblesort{
public:
    bubblesort(){}
    void sort(int _N);
private:
    int N;
    int *A;
    void createArray(void);
    void destroyArray(void);
    void printArray(int flag = 1);
    void sorting();
};