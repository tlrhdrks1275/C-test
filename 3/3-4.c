#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void vip_check(int (**p)[4], int *n)
{
    int i, k;
    printf("\n예약을 시작합니다");
    for(i=0; i<3; i++)
    {
        if((*p)[i][0]==0)
        {
            printf("\n%d호를 예약했습니다.", 301+i);
            for(k=0; k<4; k++)
            {
                
                (*p)[i][k]=1;
                *n-=1;
                if(*n==0)
                    break;
            }
        }
        if(*n==0)
            break;
    }
}

void normal_check(int (**p)[2], int *n)
{
    int i, k;
    printf("\n예약을 시작합니다");
    for(i=0; i<5; i++)
    {
        if((*p)[i][0]==0)
        {
            printf("\n%d호를 예약했습니다.", 201+i);
            for(k=0; k<2; k++)
            {
                
                (*p)[i][k]=1;
                *n-=1;
                if(*n==0)
                    break;
            }
        }
        if(*n==0)
            break;
    }
}


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
        {   printf("\n룸이 부족합니다.");
            return; }
        for(i=0; i<3; i++)
        {
            if(p1[i][0]==0)
            {
                printf("%d호 ", 301+i);
            }
        }
        vip_check(&p1, &n);
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
        
        if(n<=on)
        {
            printf("\n예약이 가능합니다.");
            printf("\n예약이 가능한 룸은: ");
        }
        else
        {    printf("\n룸이 부족합니다.");
            return;
        }
        for(i=0; i<5; i++)
        {
            if(p2[i][0]==0)
            {
                printf("%d호 ", 201+i);
            }
        }
        normal_check(&p2, &n); 
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
            printf("예약룸을 선택해주세요(VIP:1, Normal:2): ");
            scanf("%d", &room);
            if(room==1 || room==2)
                break;
                
            printf("예약룸을 다시 입력해주세요!\n");
        }
        printf("예약 인원을 입력해주세요: ");
        scanf("%d", &n);
        reservation_hotel(room, n, arr1, arr2);
        printf("\n");
    }
    
    return 0;
}

//포인터 배열은 배열이 본체임. 즉 *p[4]에서 포인터4개를 배열로 저장한것
//배열 포인터는 포인터가 본체임. 즉(*p)[4]에서 포인터 한 개가 4개의 배열을 지정하는 것임
//다차원 배열에서 arr은 첫 행 전체의 주소이고, &arr은 배열 전체의 주소이다
//배열 포인터는 입력받은 배열의 크기르 모름. 단지 지정된 크기(칸) 만큼 다음 이동하는 것일 뿐임 따라서 다차원 배열을 받을수 있는 것!
//일반 포인터나 더블 포인터나 "역참조(*)를 한 번 할 때마다 주소의 단계를 한 꺼풀씩 벗겨낸다"는 동일한 규칙
//p (역참조 0번 / **p 구조 전체) p1 변수 자체의 주소를 가리킴
//*p (역참조 1번) p가 가리키던 p1 변수 안으로 들어갑니다. p1 안에 들어있는 값은 arr 배열의 주소입니다. 즉, *p는 배열의 주소를 가리킵니다!
//**p 또는 (*p)[0] (역참조 2번) 배열 주소에서 한 단계 더 들어갑니다. 하지만 *p가 '배열'을 가리키고 있었기 때문에, 한 번 더 꺼낸 (*p)[0] 역시 배열 0번째 줄의 첫 번째 칸 주소가 됩니다.
//(*p)[0][0] (역참조 3번 / 최종 값) 인덱스 [0]을 하나 더 붙여서 알맹이까지 들어가야 비로소 실제 int 값이 나옵니다.
