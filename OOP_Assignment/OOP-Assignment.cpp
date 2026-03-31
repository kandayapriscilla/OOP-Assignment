#include <iostream>
#include <conio.h>
#include <cstdlib>  

int g_num1 = 10;

int adder(int n1, int n2) {
    int tmp = 50;
    tmp = n1 + n2;
    return tmp;
}

int main(void) {
    int* ptr1 = (int*)malloc(sizeof(int) * 1);
    *ptr1 = 5;

    int a = 3, b = 5, c = 100;

    int* ptr2 = (int*)malloc(sizeof(int) * 1);
    *ptr2 = 10;

    free(ptr1);
    c = adder(a, b);
    free(ptr2);

    _getch();
    return 0;
}