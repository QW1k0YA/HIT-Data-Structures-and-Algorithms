/*#include<stdio.h>
#include<malloc.h>

typedef struct celltype{
	int element;
	celltype* next;
}celltype;

typedef celltype* position;//ָ��ĳ������ָ�룬��˱�ʾ��Ҫ���в�����λ�� 
typedef celltype* LIST;//ָ��ͷ����ָ�룬��˱�ʾ���Ա� 


LIST CreateList(int n);//nΪ���Ա��� 
void Insert(int x,position p);
void Delete(position p);
position Locate(int x,LIST L);
LIST MakeNull(LIST* pr);
LIST End(LIST L);
void PrintList(LIST L);

int main()
{
	LIST L;
	L=CreateList(5);
	PrintList(L);
	
	
}

LIST CreateList(int n)
{
	LIST head,end,ptr = NULL;
	head=(LIST)malloc(sizeof(celltype));
	end=head;
	for(int i=0;i<n;i++)
	{
		ptr=(LIST)malloc(sizeof(celltype));
		scanf("%d",&ptr->element);
		end->next=ptr;
		end=ptr;
	}
	end->next=NULL;
	return head;
}


void Insert(int x,position p)
{
	position temp;
	temp=p->next;
	p->next=(position)malloc(sizeof(celltype));
	p->next->element=x;
	p->next->next=temp;
}

void PrintList(LIST L)
{
	LIST p = L->next;
    int i,j,k = 0;
    printf("%d %d %d",i,j,k);
	while(p->next!=NULL)
	{
		printf("%d ",p->element);
		p=p->next;
	}
	printf("%d",p->element);	
}



*/


