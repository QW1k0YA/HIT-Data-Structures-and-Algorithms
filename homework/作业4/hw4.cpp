#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct celltype
{
    int data;
    struct celltype* lchild,* rchild;
}bstnode;//二叉查找树的节点
typedef bstnode* BST;

int test1[1025];  //测试数组1
int test2[1025];  //测试数组2

//递归二叉树插入
void insertBST(int r, BST &f)
{
	if (f == NULL)
	{
		f = (bstnode*)malloc(sizeof(bstnode));
		if (f == NULL)
			printf("申请内存失败\n");
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

//建立test1的二叉查找树
BST createbt1(void)
{
	BST f;
	f = (bstnode*)malloc(sizeof(bstnode));
	f = NULL;  //初始化f为空
	int key, k = 1;
	while (k < 1025)
	{
		insertBST(test1[k], f);
		k++;
	}
	return f;  //返回建立的二叉查找树的根
}

//建立test2的二叉查找树
BST createbt2(void)
{
	BST f = (bstnode*)malloc(sizeof(bstnode));
	f = NULL;  //初始化f为空
	int  k = 1;
	while (k < 1025)
	{
		insertBST(test2[k], f);
		k++;
	}
	return f;  //返回建立的二叉查找树的根
}

//删除关键词最小的节点，并返回里面的数据
int deletemin(BST &f)
{
	int tmp;
	BST p;
	p = (bstnode*)malloc(sizeof(bstnode));
	if (f->lchild == NULL)
	{
		p = f;
		tmp = f->data;
		f = f->rchild;  //右链继承
		free(p);
		return tmp;
	}
	else
	{
		return (deletemin(f->lchild));
	}
}

//删除某个节点
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
		else//找到了需要删除的数据
		{
			if (f->rchild == NULL)  //若右子树为空，则直接继承左子树
			{
				f = f->lchild;
			}
			else if (f->lchild == NULL)  //若左子树为空，则直接继承右子树
			{
				f = f->rchild;
			}
			else
				f->data = deletemin(f->rchild);   //左右子树都为空相当于删除右子树里面的最小关键字节点并把它的值复制到待删除的节点
		}
	}
}

//二叉查找
BST BSTsearch(int k, BST &f)
{
	BST p;
	p = (bstnode*)malloc(sizeof(bstnode));
	p = f;
	if (p == NULL || k == p->data)
	{
		return p;
	}
	if (k < p->data)//如果要查找元素比当前节点的关键词小，则继续向左子树查找
	{
		return (BSTsearch(k, p->lchild));
	}
	else//否则，向右子树查找
		return (BSTsearch(k, p->rchild));
}

//中序遍历并输出
void sort(BST &f)
{
	if (f != NULL)
	{
		sort(f->lchild);
		printf("%d ", f->data);
		sort(f->rchild);
	}
}

//折半查找递归算法
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

//折半查找的查找长度
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

//产生测试数组1
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

//产生测试数组2
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

//计算一个数的查找次数
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

//菜单
void menu()
{
	printf("BST：\n");
	printf("数据一：\n");
	printf("1.建立\n");
	printf("2.查找长度\n");
	printf("3.排序\n");
	printf("4.插入\n");
	printf("5.查找\n");
	printf("6.删除\n");
	printf("数据二：\n");
	printf("7.建立\n");
	printf("8.查找长度\n");
	printf("9.排序\n");
	printf("10.插入\n");
	printf("11.查找\n");
	printf("12.删除\n");
	printf("折半查找：\n");
	printf("13.折半查找\n");
	printf("14.折半查找的查找长度\n");

}

int main()
{
	BST f1, f2, key;//f1表示数据1的二叉树，f2表示数据2的二叉树，key表示待查找数据所在节点
	f1 = (bstnode*)malloc(sizeof(bstnode));
	f2 = (bstnode*)malloc(sizeof(bstnode));
	key = (bstnode*)malloc(sizeof(bstnode));

	int m, n, p, success = 0, failure = 0;//success记录查找成功长度，failure记录查找失败长度
	int op, position;//position表示要查找的元素对应下标,op表示操作数

	menu();
	while (1)
	{
		printf("请输入操作：");
		scanf(" %d", &op);
		switch (op)
	   {
		case 1:
			createtest1();
			f1 = createbt1();
			printf("成功建立数据一的BST\n");
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
			printf("数据一BST成功查找长度：%f\n", ((float)success / 1024));
			for (p = 0; p <= 2048; p += 2)
			{
				count1 = 0;
				failure += datacount1(p, f1);
			}
			printf("数据一BST失败查找长度：%f\n", ((float)failure / 1025));
			printf("\n");
			break;
		case 3:
			createtest1();
			f1 = createbt1();
			sort(f1);
			printf("\n");
			break;
		case 4:
			printf("请输入你要插入的数：\n");
			scanf(" %d", &m);
			insertBST(m, f1);
			sort(f1);
			printf("\n");
			break;
		case 5:
			printf("请输入你要查找的数：\n");
			scanf(" %d", &n);
			key = BSTsearch(n, f1);
			if (key != NULL)
				printf("查找成功\n");
			else
				printf("查找失败\n");
			printf("\n");
			break;
		case 6:
			printf("请输入你要删除的数：\n");
			scanf(" %d", &n);
			deletenode(n, f1);
			sort(f1);
			printf("\n");
			break;
		case 7:
			createtest2();
			f2 = createbt2();
			printf("已成功建立数据二的BST\n");
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
			printf("数据二BST成功查找长度：%f\n", ((float)success / 1024));
			for (p = 0; p <= 2048; p += 2)
			{
				count1 = 0;
				failure += datacount1(p, f2);
			}
			printf("数据二BST失败查找长度：%f\n", ((float)failure / 1025));
			printf("\n");
			break;
		case 9:
			createtest2();
			f2 = createbt2();
			sort(f2);
			printf("\n");
			break;
		case 10:
			printf("请输入你要插入的数：\n");
			scanf(" %d", &m);
			insertBST(m, f2);
			sort(f2);
			printf("\n");
			break;
		case 11:
			printf("请输入你要查找的数：\n");
			scanf(" %d", &n);
			key = BSTsearch(n, f2);
			if (key != NULL)
				printf("查找成功\n");
			else
				printf("查找失败\n");
			printf("\n");
			break;
		case 12:
			printf("请输入你要删除的数：\n");
			scanf(" %d", &n);
			deletenode(n, f2);
			sort(f2);
			printf("\n");
			break;
		case 13:
			printf("请输入需要折半查找的数：\n");
			scanf(" %d", &n);
			createtest1();
			position = binsearch(test1, 1, 1024, n);
			if (position >= 1 && position <= 1024)
				printf("对应元素下标为：%d\n", position);
			else
				printf("查找失败\n");
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
			printf("折半查找成功查找长度：%f\n", ((float)success / 1024));
			for (p = 0; p <= 2048; p += 2)
			{
				count1 = 0;
				failure += binlength(test1, 1, 1024, p);
			}
			printf("折半查找失败查找长度：%f\n", ((float)failure / 1025));
			printf("\n");
			break;
		default:
			printf("请输入正确序号！\n");
			break;
		}
	}
}



			