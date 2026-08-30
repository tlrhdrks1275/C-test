#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int arr[4][8]={0};
    int i;
    int (*p)[8]=arr;
    
    for(i=0; i<8; i++)
    {
        printf("%d번째 숫자: ", i+1);
        scanf(" %d", &arr[0][i]);
    }
    
    for(i=0; i<4; i++)
    {
        p[1][i*2]=p[0][i*2]+p[0][1+2*i];
    }
    
    for(i=0; i<2; i++)
    {
        p[2][4*i]=p[1][4*i]+p[1][2+4*i];
    }
    
    p[3][0]=p[2][0]+p[2][4];
    
    printf("최종 값: %d", p[3][0]);
    
   
    

    return 0;
}