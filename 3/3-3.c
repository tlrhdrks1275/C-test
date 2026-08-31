#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func1(char (*p)[4], int *x, int *y)
{
    if(*x>0 && *y>0)
    {    p[2-*y][1+*x]='O';
        p[1+*y][1+*x]='X';
        *y=-*y;
    }
    else if(*x>0 && *y<0)
    {    p[1-*y][1+*x]='O';
        p[2+*y][1+*x]='X';
        *y=-*y;
    }
    else if(*x<0 && *y>0)
    {    p[2-*y][2+*x]='O';
        p[1+*y][2+*x]='X';
        *y=-*y;
    }
    else if(*x<0 && *y<0)
    {    p[1-*y][2+*x]='O';
        p[2+*y][2+*x]='X';
        *y=-*y;
    }
}

void func2(char (*p)[4], int *x, int *y)
{
    if(*x>0 && *y>0)
    {    p[2-*y][1+*x]='O';
        p[2-*y][2-*x]='X';
        *x=-*x;
    }
    else if(*x>0 && *y<0)
    {    p[1-*y][1+*x]='O';
        p[1-*y][2-*x]='X';
        *x=-*x;
    }
    else if(*x<0 && *y>0)
    {    p[2-*y][2+*x]='O';
        p[2-*y][1-*x]='X';
       *x=-*x;
    }
    else if(*x<0 && *y<0)
    {    p[1-*y][2+*x]='O';
        p[1-*y][1-*x]='X';
        *x=-*x;
    }
}

void func3(char (*p)[4], int *x, int *y)
{
    if(*x>0 && *y>0)
    {    p[2-*y][1+*x]='O';
        p[1+*y][2-*x]='X';
        *x=-*x;
        *y=-*y;
    }
    else if(*x>0 && *y<0)
    {    p[1-*y][1+*x]='O';
        p[2+*y][2-*x]='X';
        *x=-*x;
       *y=-*y;
    }
    else if(*x<0 && *y>0)
    {    p[2-*y][2+*x]='O';
        p[1+*y][1-*x]='X';
        *x=-*x;
        *y=-*y;
    }
    else if(*x<0 && *y<0)
    {    p[1-*y][2+*x]='O';
        p[2+*y][1-*x]='X';
        *x=-*x;
        *y=-*y;
    }
}

int main()
{
    char arr[4][4];
    int i,k;
    int x, y;
    
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            arr[i][k]='O';
        }
    }
    
    printf("좌표를 입력하세요(x y): ");
    scanf("%d %d", &x, &y);
    
    if(x>0 && y>0)
        arr[2-y][1+x]='X';
    else if(x>0 && y<0)
        arr[1-y][1+x]='X';
    else if(x<0 && y>0)
        arr[2-y][2+x]='X';
    else if(x<0 && y<0)
        arr[1-y][2+x]='X';

    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%c", arr[i][k]);
        }
        printf("\n");
    }
    printf("\n");

    func1(arr, &x, &y);
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%c", arr[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    func2(arr, &x, &y);
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%c", arr[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    func3(arr, &x, &y);
    {
        for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%c", arr[i][k]);
        }
        printf("\n");
    }
    
    }
    return 0;
}

//배열을 처음 선언하면서 안에 숫자나 문자를 채울때, 다 채울려면 일일이 채워야 하고, 0이나 널문자로 채우는 거면 생략 가능
//일단 하드 코딩으로 해버리긴 했으니, 추후에 다른 방식으로 더 공부해서 추가 하야 할 듯