#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readfile(int* arr, int* np)
{
    FILE* fp;
    int i;

    // ���ļ�
    fp = fopen("D:\\���ݽṹ���㷨ʵ��\\ʵ��4\\input(100000).txt", "r");
    if (fp == NULL)
    {
        printf("fail to open��");
        return 1;
    }

    // ��ȡ��һ�����ݣ���ʾ���������еĳ���
    fscanf(fp, "%d", np);

    // ��ȡ�ڶ��е� n ���������洢��������
    for (i = 0; i < *np; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    // �ر��ļ�
    fclose(fp);
}

// �鲢����
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    //�����м�
    int n2 = r - m;
    int L[50000], R[50000];//����������ʱ����

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m +1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) //�ϲ�������������
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];//arr ����һ���������������
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)//�����ʣ�����
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)//�ұ���ʣ�����
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)//���в�ֹ��һ��Ԫ�� 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);//����߽��еݹ�
        mergeSort(arr, m + 1, r);//���ұ߽��еݹ�
        merge(arr, l, m, r);//�����Ҳ��ֺϲ�
    }
}

// ��������
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];//��׼ֵ
    int i = (low - 1);//�����������Ҳ���Ǵ�low��ʼ
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
    return (i + 1);//i+1Ϊ��pivotС�����ĸ���
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);//�ԱȻ�׼ֵС�������еݹ�����
        quickSort(arr, pi + 1, high);//�ԱȻ�׼ֵ��������еݹ�����
    }
}

//ѡ������
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)//����ÿһ����������������֮��������бȽϣ�С������ǰ��
{
    int i =0, j= 0, min_idx = 0;//min_idxΪ��ǰ�趨����Сֵ���±�
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
    //����һ����ģ�������
    int i, arr[100000], n;//n��ʾ���������г���
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

    // �鲢����
    readfile(arr, &n);
    clock_t start_merge = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end_merge = clock();
    double time_spent_merge = (double)(end_merge - start_merge) / CLOCKS_PER_SEC;

    // ����鲢����������
    printf("\nAfter merge sort��\n");
 /*   for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/
    printf("\nmerge sort time��%f s\n", time_spent_merge);

    // ��������
    readfile(arr, &n);
    clock_t start_quick = clock();
    quickSort(arr, 0, n - 1);
    clock_t end_quick = clock();
    double time_spent_quick = (double)(end_quick - start_quick) / CLOCKS_PER_SEC;

    // �����������������
    printf("\nAfter quick sort��\n");
 /*   for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/
    printf("\nquick sort time��%f s\n", time_spent_quick); 

    //ѡ������
    readfile(arr, &n);
    clock_t start_selection = clock();
    selectionSort(arr, n);
    clock_t end_selection = clock();
    double time_spent_selection = (double)(end_selection - start_selection) / CLOCKS_PER_SEC;

    // ���ѡ������������
    printf("\nAfter selection sort��\n");
 /*   for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/
    printf("\nselection sort time��%f s\n", time_spent_selection);

    return 0;
}
