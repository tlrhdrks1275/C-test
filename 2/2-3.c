#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double pi=3.14;

double get_area(double a)
{
    return pi*a*a;
}

double get_circumference(double b)
{
    return pi*b*2;
}

int main()
{
    double r;
    printf("넓이/둘레를 구할 원의 반지름을 입력하세요: ");
    scanf("%lf", &r);
    printf("입력한 반지름 : %.0f에 대한\n", r);
    
    printf("원의 넓이는 %.6f\n", get_area(r));
    printf("원의 둘레는 %.6f", get_circumference(r));
}

//소수점은 컴퓨터가 2진수로 저장 할때 오차가 생길수 있음
//double은 scanf 할때 lf로 받아야 함, 그러나 출력할때는 float. double 둘다 f로 사용.