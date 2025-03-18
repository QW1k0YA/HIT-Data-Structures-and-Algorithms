#include<stdio.h>
#include<malloc.h>

typedef struct celltype{
    int element;
    struct celltype* next;
}celltype;


typedef celltype* position;//指向某个结点的指针，因此表示需要进行操作的位置
typedef celltype* LIST;//指向头结点的指针，因此表示线性表

LIST L,L1,L2,L3;
LIST* Lp=&L;

LIST CreateList(int n);//n为线性表长度
LIST CreateNull(int n);
void PrintList(LIST L);
void DeleteGiven(LIST* Lp,int num);//num为要删除元素的位置
void DeleteEcho(LIST L);
void Inverse(LIST L);
void MoveCycle(LIST L,int num,int flag);//num为左移或右移的格数，flag标记左移或右移，flag=1为左移
LIST MergeList(LIST L1,LIST L2);



int main()
{
    printf("input the list (5 elements):\n");
    L=CreateList(5);
    printf("the list is:\n");
    PrintList(L);
    printf("\n");

    printf("delete the second element：\n");
    printf("before delete:\n");
    PrintList(L);
    DeleteGiven(Lp,2);
    printf("after delete:\n");
    PrintList(L);
    printf("\n");

    printf("delete the echo:\n");
    printf("before delete:\n");
    PrintList(L);
    DeleteEcho(L);
    printf("after delete:\n");
    PrintList(L);
    printf("\n");

    printf("inverse the list:\n");
    printf("before inverse:\n");
    PrintList(L);
    Inverse(L);
    printf("after inverse:\n");
    PrintList(L);
    printf("\n");

    printf("move 3 places to the left:\n");
    printf("before move:\n");
    PrintList(L);
    MoveCycle(L,3,1);
    printf("after move:\n");
    PrintList(L);
    printf("move 2 places to the right:\n");
    printf("before move:\n");
    PrintList(L);
    MoveCycle(L,2,0);
    printf("after move:\n");
    PrintList(L);
    printf("\n");

    printf("merge two lists:\n");
    printf("input the first list (5 elements):\n");
    L1=CreateList(5);
    printf("input the second list (8 elements):\n");
    L2=CreateList(8);
    printf("before merge:\n");
    PrintList(L1);
    PrintList(L2);
    L3=MergeList(L1,L2);
    printf("after merge:\n");
    PrintList(L3);
    printf("\n");

    return 0;
}

LIST CreateList(int n)
{
    LIST head=NULL,end,ptr;
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

LIST CreateNull(int n)
{
    LIST head=NULL,end,ptr;
    head=(LIST)malloc(sizeof(celltype));
    end=head;
    for(int i=0;i<n;i++)
    {
        ptr=(LIST)malloc(sizeof(celltype));
        end->next=ptr;
        end=ptr;
    }
    end->next=NULL;
    return head;
}


void PrintList(LIST L)
{
    LIST p = L->next;
    while(p->next!=NULL)
    {
        printf("%d ",p->element);
        p=p->next;
    }
    printf("%d",p->element);
    printf("\n");
}

void DeleteGiven(LIST* Lp,int num)
{

    LIST pr=NULL,p=NULL;
    pr=(*Lp)->next;
    if(num==1)
    {
        (*Lp)->next=pr->next;
        free(pr);
    }
    else
    {
        for(int i=0;i<num-2;i++)
        {
            pr=pr->next;
        }
        p=pr->next;
        pr->next=p->next;
        free(p);
    }
}

void DeleteEcho(LIST L)
{
    LIST pr1=L;
    LIST pr2=pr1->next->next;
    int i=1;//标记要删除的位置
    while(pr2->next!=NULL)
    {
        if(pr1->next->element==pr2->element)
        {
            pr2=pr2->next;
            DeleteGiven(Lp,i);
            i--;
        }
        else
        {
            pr2=pr2->next;
            pr1=pr1->next;
        }
        i++;
    }
    if(pr1->next->element==pr2->element)//最后两位的比较
    {
        pr2=pr2->next;
        DeleteGiven(Lp,i);
    }
}

void Inverse(LIST L)
{
    position p,q;
    p=L->next;
    q=p->next;
    if(p)
    {
        q=p->next;
        p->next=NULL;
        while(q!=NULL)
        {
            p=q;
            q=q->next;
            p->next=L->next;
            L->next=p;
        }
    }
}

void MoveCycle(LIST L,int num,int flag)
{
    int length=0;
    LIST L1,L2;
    L1=L->next;
    while(L1->next!=NULL)//计算链表的长度
    {
        L1=L1->next;
        length++;
    }
    length++;

    L1->next=L->next;//构造循环链表

    L2=L1->next;
    if(flag==1)
    {
        for(int i=0;i<num-1;i++)
        {
            L2=L2->next;
        }
        L->next=L2->next;
        L2->next=NULL;
    }
    else
    {
        for(int i=0;i<length-num-1;i++)
        {
            L2=L2->next;
        }
        L->next=L2->next;
        L2->next=NULL;
    }
}

LIST MergeList(LIST L1,LIST L2)
{
    int length1=0;
    int length2=0;
    LIST L3=L1->next;
    LIST L4=L2->next;

    while(L3->next!=NULL)//计算表1的长度
    {
        L3=L3->next;
        length1++;
    }
    length1++;

    while(L4->next!=NULL)//计算表2的长度
    {
        L4=L4->next;
        length2++;
    }
    length2++;

    LIST L=CreateNull(length1+length2);
    LIST Lp=L->next;
    int j=0,k=0;//j标记Lp1的位置，k标记Lp2的位置
    LIST Lp1=L1->next;
    LIST Lp2=L2->next;

    while((Lp1->next!=NULL)&&(Lp2->next!=NULL))
    {
        if(Lp1->element<=Lp2->element)
        {
            Lp->element=Lp1->element;
            Lp1=Lp1->next;
            j++;
        }
        else
        {
            Lp->element=Lp2->element;
            Lp2=Lp2->next;
            k++;
        }
        Lp=Lp->next;
    }

    int flag1 = 0;
    int flag2 = 0;
    while(flag1 != 1 && flag2 != 1)
    {
        if(Lp1->element<=Lp2->element)//其中一个等于NULL的最后一次情况
        {
            if(Lp1->next == NULL)
            {
            flag1++;
            }
            Lp->element=Lp1->element;
            Lp1=Lp1->next;
            j++;
        }
        else
        {
            if(Lp2->next == NULL)
            {
                flag2 ++;
            }
            Lp->element=Lp2->element;
            Lp2=Lp2->next;
            k++;
        }
        Lp=Lp->next;
    }

    if(j>length1-1)//表1满了，考虑表2剩下的元素
    {
        int n=length2  -k;
        for(int i=0;i<n;i++)
        {
            Lp->element=Lp2->element;
            Lp=Lp->next;
            Lp2=Lp2->next;
        }
    }
    if(k>length2-1)
    {
        int n=length1-j;
        for(int i=0;i<n;i++)
        {
            Lp->element=Lp1->element;
            Lp=Lp->next;
            Lp1=Lp1->next;
        }
    }

    return L;
}































