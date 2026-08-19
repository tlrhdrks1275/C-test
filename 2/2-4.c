#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//소수 구하는 에라토스테네스의 체 로직
void filter(int *p)
{
    int i, j;
    for(i=2; i<=28; i++)
    {
        for(j=0; j<=28; j++)
        {
            // 이미 0으로 지워진 값은 검사에서 제외
            if (*(p + j) == 0) continue;
            
            if((*(p+j)!=i) && (*(p+j)%i==0))
            {
                *(p+j)=0;
            }
        }
    }
}



int main()
{
    int arr[29];
    int i;
    
    //배열에 2~30 대입
    for(i=0; i<=28; i++)
    {
        arr[i]=i+2;
    }
    
    //filter 함수 사용
    filter(arr);
    
    //filter로 거르고 남은 소수들 출력
    printf("남은 소수 출력: ");
    for(i=0; i<=28; i++)
    {
        if(arr[i]!=0)
        {
            printf("%d ", arr[i]);
        }
    }
    
    
    return 0;
}


//수정 filter로 거르는 중에 0으로 바뀌어 있는 경우 => 건너뛰게 continue씀
//지역함수에서 리턴 안쓰니까 이름 int에서 void로 수정