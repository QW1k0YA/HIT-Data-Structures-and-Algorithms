#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readfile(int* arr, int* np)
{
    FILE* fp;
    int i;

    // 打开文件
    fp = fopen("D:\\数据结构与算法实验\\实验4\\input(100000).txt", "r");
    if (fp == NULL)
    {
        printf("fail to open！");
        return 1;
    }

    // 读取第一行数据，表示待排序序列的长度
    fscanf(fp, "%d", np);

    // 读取第二行的 n 个整数，存储到数组中
    for (i = 0; i < *np; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    // 关闭文件
    fclose(fp);
}

// 归并排序
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    //包括中间
    int n2 = r - m;
    int L[50000], R[50000];//创建左右临时序列

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m +1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) //合并左右两个部分
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];//arr 代表一个部分排序的序列
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)//左边有剩余情况
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)//右边有剩余情况
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)//序列不止有一个元素 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);//对左边进行递归
        mergeSort(arr, m + 1, r);//对右边进行递归
        merge(arr, l, m, r);//将左右部分合并
    }
}

// 快速排序
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];//基准值
    int i = (low - 1);//排完序的序列也还是从low开始
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);//i+1为比pivot小的数的个数
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);//对比基准值小的数进行递归排序
        quickSort(arr, pi + 1, high);//对比基准值大的数进行递归排序
    }
}

//选择排序
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)//遍历每一个数，将该数与它之后的数进行比较，小的数往前排
{
    int i =0, j= 0, min_idx = 0;//min_idx为当前设定的最小值的下标
    for (i = 0; i < n - 1; i++) 
    {
        min_idx = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() 
{
    //生成一定规模的随机数
    int i, arr[100000], n;//n表示待排序序列长度
    /*srand(time(0));
    for (i = 0; i < 10000; i++)
    {
        arr[i] = rand()%100;
        n++;
    }
    printf("%d\n", n);
    for (i = 0; i < 10000; i++)
    {
        printf("%d ", arr[i]);
    }*/

    // 归并排序
    readfile(arr, &n);
    clock_t start_merge = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end_merge = clock();
    double time_spent_merge = (double)(end_merge - start_merge) / CLOCKS_PER_SEC;

    // 输出归并排序后的序列
    printf("\nAfter merge sort：\n");
 /*   for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/
    printf("\nmerge sort time：%f s\n", time_spent_merge);

    // 快速排序
    readfile(arr, &n);
    clock_t start_quick = clock();
    quickSort(arr, 0, n - 1);
    clock_t end_quick = clock();
    double time_spent_quick = (double)(end_quick - start_quick) / CLOCKS_PER_SEC;

    // 输出快速排序后的序列
    printf("\nAfter quick sort：\n");
 /*   for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/
    printf("\nquick sort time：%f s\n", time_spent_quick); 

    //选择排序
    readfile(arr, &n);
    clock_t start_selection = clock();
    selectionSort(arr, n);
    clock_t end_selection = clock();
    double time_spent_selection = (double)(end_selection - start_selection) / CLOCKS_PER_SEC;

    // 输出选择排序后的序列
    printf("\nAfter selection sort：\n");
 /*   for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/
    printf("\nselection sort time：%f s\n", time_spent_selection);

    return 0;
}
