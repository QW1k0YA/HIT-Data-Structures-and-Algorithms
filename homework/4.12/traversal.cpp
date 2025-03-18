//
// Created by User on 2024-04-12.
//
#include "def.h"
#include "vector"
using namespace std;

void preorder(BTREE& T)
{
    if(T != NULL)
    {
        cout << T->data;
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

void inorder(BTREE& T)
{
    if(T != NULL)
    {
        inorder(T->lchild);
        cout << T->data;
        inorder(T->rchild);
    }
}

void InOrder (BTREE BT)
{
    if ( BT != NULL)
    {
        InOrder ( BT->lchild ) ;
        cout<< BT->data ;
        InOrder ( BT->rchild ) ;
    }
}

void postorder(BTREE& T)
{
    if ( T != NULL)
    {
        postorder ( T->lchild ) ;
        postorder ( T->rchild ) ;
        cout<< T->data ;
    }
}


/*
void PreOrder_(BTREE root,BTREE s[])
{   int top= -1;
    while (root!=NULL || top!= -1) {
        while (root!= NULL) {
            cout<<root->data;
            s[++top]=root;
            root=root->lchild;
        }
        if (top!= -1) {
            root=s[top--];
            root=root->rchild;
        }
    }
}
 */
void preorder_(BTREE T)
{
    BTREE s[N];
    int top = -1;
    while((T!= NULL)||(top != -1))
    {
        while(T!= NULL)
        {
            cout << T->data;
            s[++top] = T;
            T = T->lchild;
        }
        //循环结束 此时T == NULL
        if(top != -1)
        {
            T = s[top--];
            T = T->rchild;
        }
        //左孩子访问完 退回去看右孩子

    }
}
//栈里保存的是访问了一半的节点

void inorder_(BTREE T)
{
    BTREE s[N];
    int top = -1;
    while(T != NULL || top != -1)
    {
        while(T!= NULL)
        {
            s[++top] = T;
            T = T->lchild;
        }

        if(top != -1)
        {
            T = s[top--];
            cout << T->data;
            T = T->rchild;
        }
    }
}
//区别只在于cout地方不同



void postorder_(BTREE root) {
    Stack s[N];
    int top = -1;
    while (root != NULL || top != -1) {

        while (root != NULL) {
            s[++top].ptr = root;
            //这里是改的
            s[top].flag = 1;
            root = root->lchild;
        }

        //左边节点全部入栈
        while (top != -1 && s[top].flag == 2) {
            root = s[top--].ptr;
            cout << root->data;
        }
        //右边的全出了 但是问题在于此时的指针指向不是null 因此正常执行的话 就会回到开头进行

        if (top == -1) {
            break;
        }
        //这里是加的

        if (top != -1) {
            //  root = s[top--].ptr;
            //top--;
            s[top].flag = 2;
            root = s[top].ptr->rchild;
        }
    }


}

void leverorder(BTREE T)
{
    BTREE Q[N];
    int front = 0;
    int rear = 0;
    //队尾入 队首出

    BTREE  q;
    if(T == NULL)
    {
        return;
    }

    Q[++rear] = T;
    //从1开始
    while(front!=rear)
    {
        q = Q[++front];
        //取出队首元素 把他们的子节点放到队尾
        cout << q->data;
        if(q->lchild!= NULL) Q[++rear] = q->lchild;
        if(q->rchild!= NULL) Q[++rear] = q->rchild;

    }
}


