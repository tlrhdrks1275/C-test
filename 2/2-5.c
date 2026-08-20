#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void sort_Asending(int *p)
{
    int i, j, tmp;
    for(i=0; i<23; i++)
    {
        for(j=i+1; j<24; j++)
        {
            if(*(p+i)>*(p+j))
            {
                tmp=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=tmp;
            }
        }
    }
    
}


void sort_Dsending(int *p)
{
   int i, j, tmp;
    for(i=0; i<23; i++)
    {
        for(j=i+1; j<24; j++)
        {
            if(*(p+i)<*(p+j))
            {
                tmp=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=tmp;
            }
        }
    } 
}

int main()
{
    int arr[]={1, 3, 6, 23, 5756, 32, 546, 23, 34, 12, 89,
        43, 56, 76, 76, 2312, 4324, 13, 565, 657, 2343, 32,
        123, 343}; //24
    int i;
    
    printf("정렬 전 배열: ");
    for(i=0; i<24; i++)
    {
        printf("%d ", arr[i]);
    }
    
    sort_Asending(arr);
    printf("\n\n오름차순 정렬 후 배열: ");
    for(i=0; i<24; i++)
    {
        printf("%d ", arr[i]);
    }
    
    sort_Dsending(arr);
    printf("\n\n내림차순 정렬 후 배열: ");
    for(i=0; i<24; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

// 전체 배열 크기(byte) / 요소 1개의 크기(byte) -> 이렇게 하면 숫자 개수를 구할 수 있음
//int size = sizeof(arr) / sizeof(arr[0]);
//추후 랜덤 함수 배우면 그쪽으로 바꾸는데 더 깔끔할 듯
