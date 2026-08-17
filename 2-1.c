/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap1(int a, int b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
    printf("After value swap(in function), A : %d, B : %d\n", a, b);
}

void swap2(int *a, int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
    printf("After value swap(in function), A : %d, B : %d\n", *a, *b);
}


int main()
{
    int a, b;
    printf("A: ");
    scanf("%d", &a);
    
    printf("B: ");
    scanf("%d", &b);
    
    printf("Before swap, A : %d, B : %d\n\n", a, b);
    
    swap1(a, b);
    printf("After value swap(in main), A : %d, B : %d\n\n", a, b);
    
    swap2(&a, &b);
    printf("After value swap(in main), A : %d, B : %d", a, b);
    
    return 0;
}