#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    //����һ����ģ�������
    int i, arr[100000];
    srand(time(0));
    for (i = 0; i < 10000; i++)
    {
        arr[i] = rand();
    }
    for (i = 0; i < 10000; i++)
    {
        printf("%d ", arr[i]);
    }
}