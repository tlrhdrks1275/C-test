#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void reservation_hotel(int room, int n, int (*p1)[4], int (*p2)[2])
{
    int on=0, check=0, i;
    if(room==1)
    {
        
        for(i=0; i<3; i++)
        {
            if(p1[i][0]==0)
            {
                check+=1;
            }
        }
        on=check*4;
        
        if(n<=on)
        {
            printf("\n예약이 가능합니다.");
            printf("\n예약이 가능한 룸은: ");
        }
        else
            printf("\n룸이 부족합니다.");
            
        
        for(i=0; i<3; i++)
        {
            if(p1[i][0]==0)
            {
                printf("%d호 ", 301+i);
            }
        }
        
    }
    
    if(room==2)
    {
        
        for(i=0; i<5; i++)
        {
            if(p2[i][0]==0)
            {
                check+=1;
            }
        }
        on=check*2;
        
        if(n>=check)
        {
            printf("\n예약이 가능합니다.");
            printf("\n예약이 가능한 룸은: ");
        }
        else
            printf("\n룸이 부족합니다.");
            
        
        for(i=0; i<5; i++)
        {
            if(p2[i][0]==0)
            {
                printf("%d호 ", 201+i);
            }
        }
        
    }
}

void vip_check(int **p, int *n)
{
    int i, k;
    printf("\n예약을 시작합니다");
    for(i=0; i<3; i++)
    {
        if((*p)[i][0]==0)
        {
            for(k=0; k<4; k++)
            {
                (*p)[i][k]=1;
                n-=1;
                if(n==0)
                    break;
            }
        }
        if(n==0)
            break;
    }
}

int main()
{
    int arr1[3][4]={0};
    int arr2[5][2]={0};
    int room, n, i;
    
    for(i=0; i<5; i++)
    {
        while(1)
        {
            printf("예약룸을 선택해주세요(VIP:1, Nomar:2): ");
            scanf("%d", &room);
            if(room==1 || room==2)
                break;
                
            printf("예약룸을 다시 입력해주세요!\n");
        }
        printf("예약 인원을 입력해주세요: ");
        scanf("%d", &n);
        reservation_hotel(room, n, &arr1, &arr2);
    }
    
    return 0;
}

    