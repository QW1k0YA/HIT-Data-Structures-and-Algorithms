#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct celltype
{
    int data;
    struct celltype* lchild,* rchild;
}bstnode;//����������Ľڵ�
typedef bstnode* BST;

int test1[1025];  //��������1
int test2[1025];  //��������2

//�ݹ����������
void insertBST(int r, BST &f)
{
	if (f == NULL)
	{
		f = (bstnode*)malloc(sizeof(bstnode));
		if (f == NULL)
			printf("�����ڴ�ʧ��\n");
		f->data = r;
		f->lchild = NULL;
		f->rchild = NULL;
	}
	else if(r < f->data)
	{
		insertBST(r, f->lchild);
	}
	else if(r > f->data)
	{
		insertBST(r, f->rchild);
	}
}

//����test1�Ķ��������
BST createbt1(void)
{
	BST f;
	f = (bstnode*)malloc(sizeof(bstnode));
	f = NULL;  //��ʼ��fΪ��
	int key, k = 1;
	while (k < 1025)
	{
		insertBST(test1[k], f);
		k++;
	}
	return f;  //���ؽ����Ķ���������ĸ�
}

//����test2�Ķ��������
BST createbt2(void)
{
	BST f = (bstnode*)malloc(sizeof(bstnode));
	f = NULL;  //��ʼ��fΪ��
	int  k = 1;
	while (k < 1025)
	{
		insertBST(test2[k], f);
		k++;
	}
	return f;  //���ؽ����Ķ���������ĸ�
}

//ɾ���ؼ�����С�Ľڵ㣬���������������
int deletemin(BST &f)
{
	int tmp;
	BST p;
	p = (bstnode*)malloc(sizeof(bstnode));
	if (f->lchild == NULL)
	{
		p = f;
		tmp = f->data;
		f = f->rchild;  //�����̳�
		free(p);
		return tmp;
	}
	else
	{
		return (deletemin(f->lchild));
	}
}

//ɾ��ĳ���ڵ�
void deletenode(int k, BST &f)
{
	if (f != NULL)
	{
		if (k < f->data)
		{
			deletenode(k, f->lchild);
		}
		else if (k > f->data)
		{
			deletenode(k, f->rchild);
		}
		else//�ҵ�����Ҫɾ��������
		{
			if (f->rchild == NULL)  //��������Ϊ�գ���ֱ�Ӽ̳�������
			{
				f = f->lchild;
			}
			else if (f->lchild == NULL)  //��������Ϊ�գ���ֱ�Ӽ̳�������
			{
				f = f->rchild;
			}
			else
				f->data = deletemin(f->rchild);   //����������Ϊ���൱��ɾ���������������С�ؼ��ֽڵ㲢������ֵ���Ƶ���ɾ���Ľڵ�
		}
	}
}

//�������
BST BSTsearch(int k, BST &f)
{
	BST p;
	p = (bstnode*)malloc(sizeof(bstnode));
	p = f;
	if (p == NULL || k == p->data)
	{
		return p;
	}
	if (k < p->data)//���Ҫ����Ԫ�رȵ�ǰ�ڵ�Ĺؼ���С�������������������
	{
		return (BSTsearch(k, p->lchild));
	}
	else//����������������
		return (BSTsearch(k, p->rchild));
}

//������������
void sort(BST &f)
{
	if (f != NULL)
	{
		sort(f->lchild);
		printf("%d ", f->data);
		sort(f->rchild);
	}
}

//�۰���ҵݹ��㷨
int binsearch(int f[], int low, int up, int k)
{
	int mid;
	if (low > up)
		return 0;
	else
	{
		mid = (low + up) / 2;
		if (k < f[mid])
		{
			return binsearch(f, low, mid - 1, k);
		}
		else if(k > f[mid])
		{
			return binsearch(f, mid + 1, up, k);
		}
		else
			return mid;
	}
}

//�۰���ҵĲ��ҳ���
int count1;
int binlength(int data[], int low, int up, int k)
{
	
	int mid;
	if (low > up)
		return count1;
	else
	{
		mid = (low + up) / 2;
		if (k < data[mid])
		{
			count1++;
			return binlength(data, low, mid - 1, k);
		}
		else if(k > data[mid])
		{
			count1++;
			return binlength(data, mid + 1, up, k);
		}
		else if(k == data[mid])
		{
			count1++;
			return count1;
		}
	}
}

//������������1
void createtest1()
{
	int k = 1;
	for (int i = 1; i < 2049; i++)
	{
		if (i % 2 == 1)
		{
			test1[k] = i;
			k++;
		}
	}
}

//������������2
void createtest2()
{
	int i, j, temp, k = 1;
	for (i = 1; i < 2049; i++)
	{
		if (i % 2 == 1)
		{
			test2[k] = i;
			k++;
		}
	}
	srand(time(0));
	for (k = 1; k < 10000; k++)
	{
		i = rand() % 1025;
		j = rand() % 1025;
		temp = test2[i];
		test2[i] = test2[j];
		test2[j] = temp;
	}
}

//����һ�����Ĳ��Ҵ���
int datacount1(int k, BST &f)
{
	BST p;
	p = (bstnode*)malloc(sizeof(bstnode));
	p = f;
	if (p == NULL)
	{
		return count1;
	}
	if (k == p->data)
	{
		count1++;
		return count1;
	}
	if (k < p->data)
	{
		count1++;
		return datacount1(k, p->lchild);
	}
	else
	{
		count1++;
		return datacount1(k, p->rchild);
	}
}

//�˵�
void menu()
{
	printf("BST��\n");
	printf("����һ��\n");
	printf("1.����\n");
	printf("2.���ҳ���\n");
	printf("3.����\n");
	printf("4.����\n");
	printf("5.����\n");
	printf("6.ɾ��\n");
	printf("���ݶ���\n");
	printf("7.����\n");
	printf("8.���ҳ���\n");
	printf("9.����\n");
	printf("10.����\n");
	printf("11.����\n");
	printf("12.ɾ��\n");
	printf("�۰���ң�\n");
	printf("13.�۰����\n");
	printf("14.�۰���ҵĲ��ҳ���\n");

}

int main()
{
	BST f1, f2, key;//f1��ʾ����1�Ķ�������f2��ʾ����2�Ķ�������key��ʾ�������������ڽڵ�
	f1 = (bstnode*)malloc(sizeof(bstnode));
	f2 = (bstnode*)malloc(sizeof(bstnode));
	key = (bstnode*)malloc(sizeof(bstnode));

	int m, n, p, success = 0, failure = 0;//success��¼���ҳɹ����ȣ�failure��¼����ʧ�ܳ���
	int op, position;//position��ʾҪ���ҵ�Ԫ�ض�Ӧ�±�,op��ʾ������

	menu();
	while (1)
	{
		printf("�����������");
		scanf(" %d", &op);
		switch (op)
	   {
		case 1:
			createtest1();
			f1 = createbt1();
			printf("�ɹ���������һ��BST\n");
			printf("\n");
			break;
		case 2:
			success = 0;
			failure = 0;
			createtest1();
			f1 = createbt1();
			for (p = 1; p < 1025; p++)
			{
				count1 = 0;
				success += datacount1(test1[p], f1);
			}
			printf("����һBST�ɹ����ҳ��ȣ�%f\n", ((float)success / 1024));
			for (p = 0; p <= 2048; p += 2)
			{
				count1 = 0;
				failure += datacount1(p, f1);
			}
			printf("����һBSTʧ�ܲ��ҳ��ȣ�%f\n", ((float)failure / 1025));
			printf("\n");
			break;
		case 3:
			createtest1();
			f1 = createbt1();
			sort(f1);
			printf("\n");
			break;
		case 4:
			printf("��������Ҫ���������\n");
			scanf(" %d", &m);
			insertBST(m, f1);
			sort(f1);
			printf("\n");
			break;
		case 5:
			printf("��������Ҫ���ҵ�����\n");
			scanf(" %d", &n);
			key = BSTsearch(n, f1);
			if (key != NULL)
				printf("���ҳɹ�\n");
			else
				printf("����ʧ��\n");
			printf("\n");
			break;
		case 6:
			printf("��������Ҫɾ��������\n");
			scanf(" %d", &n);
			deletenode(n, f1);
			sort(f1);
			printf("\n");
			break;
		case 7:
			createtest2();
			f2 = createbt2();
			printf("�ѳɹ��������ݶ���BST\n");
			printf("\n");
			break;
		case 8:
			success = 0;
			failure = 0;
			createtest2();
			f2 = createbt2();
			for (p = 1; p < 1025; p++)
			{
				count1 = 0;
				success += datacount1(test2[p], f2);
			}
			printf("���ݶ�BST�ɹ����ҳ��ȣ�%f\n", ((float)success / 1024));
			for (p = 0; p <= 2048; p += 2)
			{
				count1 = 0;
				failure += datacount1(p, f2);
			}
			printf("���ݶ�BSTʧ�ܲ��ҳ��ȣ�%f\n", ((float)failure / 1025));
			printf("\n");
			break;
		case 9:
			createtest2();
			f2 = createbt2();
			sort(f2);
			printf("\n");
			break;
		case 10:
			printf("��������Ҫ���������\n");
			scanf(" %d", &m);
			insertBST(m, f2);
			sort(f2);
			printf("\n");
			break;
		case 11:
			printf("��������Ҫ���ҵ�����\n");
			scanf(" %d", &n);
			key = BSTsearch(n, f2);
			if (key != NULL)
				printf("���ҳɹ�\n");
			else
				printf("����ʧ��\n");
			printf("\n");
			break;
		case 12:
			printf("��������Ҫɾ��������\n");
			scanf(" %d", &n);
			deletenode(n, f2);
			sort(f2);
			printf("\n");
			break;
		case 13:
			printf("��������Ҫ�۰���ҵ�����\n");
			scanf(" %d", &n);
			createtest1();
			position = binsearch(test1, 1, 1024, n);
			if (position >= 1 && position <= 1024)
				printf("��ӦԪ���±�Ϊ��%d\n", position);
			else
				printf("����ʧ��\n");
			printf("\n");
			break;
		case 14:
			success = 0;
			failure = 0;
			createtest1();
			for (p = 1; p < 1025; p++)
			{
				count1 = 0;
				success += binlength(test1, 1, 1024, test1[p]);
			}
			printf("�۰���ҳɹ����ҳ��ȣ�%f\n", ((float)success / 1024));
			for (p = 0; p <= 2048; p += 2)
			{
				count1 = 0;
				failure += binlength(test1, 1, 1024, p);
			}
			printf("�۰����ʧ�ܲ��ҳ��ȣ�%f\n", ((float)failure / 1025));
			printf("\n");
			break;
		default:
			printf("��������ȷ��ţ�\n");
			break;
		}
	}
}



			