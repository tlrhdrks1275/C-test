#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void input_char(char *p1, char *p2)
{
    printf("문자를 입력하세요: ");
    scanf("%s", p1);
    printf("정렬방식을 입력하세요(오름차순, 내림차순): ");
    scanf("%s", p2);
}

void func_sort(char *p1, char *p2)
{
    int i, j, len;
    char tmp;
    len=strlen(p1);
    
    if(strcmp(p2, "오름차순")==0)
    {
        for(i=0; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(*(p1+i)>*(p1+j))
            {
                tmp=*(p1+i);
                *(p1+i)=*(p1+j);
                *(p1+j)=tmp;
            }
        }
    }
    }
    
    else if(strcmp(p2, "내림차순")==0)
    {
        for(i=0; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(*(p1+i)<*(p1+j))
            {
                tmp=*(p1+i);
                *(p1+i)=*(p1+j);
                *(p1+j)=tmp;
            }
        }
    } 
    }
}

void func_print(char *p)
{
    printf("%s", p);
}


int main()
{
    char arr[100];
    char def[50];
    int i;
    
    input_char(arr, def);
    func_sort(arr, def);
    func_print(arr);
    
    return 0;
}

//printf에서 %c랑 %d는 실제 값을 입력해야 하지만, %s는 주소를 입력해야 함
//scanf는 항상 주소 입력!