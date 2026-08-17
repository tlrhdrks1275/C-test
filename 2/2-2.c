/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    int a[2], tmp;
    int *p1, *p2;
    
    printf("Before swap: ");
    scanf("%d %d", &a[0], &a[1]);
    tmp=a[0];
    a[0]=a[1];
    a[1]=tmp;
    printf("Swap by index : %d %d\n\n", a[0], a[1]);
    
    printf("Before swap: ");
    scanf("%d %d", &a[0], &a[1]);
    p1=&a[0];
    p2=&a[1];
    
    tmp=*p1;
    *p1=*p2;
    *p2=tmp;
    
    printf("Swap by Pointer: %d %d", a[0], a[1]);
    
    return 0;
}