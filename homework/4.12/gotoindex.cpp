//
// Created by User on 2024-04-19.
//
#include "def.h"
#include "vector"
using namespace std;

BTREE gotoindex(BTREE T,int num)
//int a[] 存放编号
{
    BTREE result;
    //返回一个节点
    BTREE Q[N];
    if(T == NULL)
    {
        cerr << "input invalid in gotoindex";
        exit(0);
    }

    if(num == 1)
    {
        return T;
    }

    int front = 0;
    int rear = 0;
    //队尾入 队首出

    BTREE  q;


    Q[++rear] = T;

    //从1开始
    int i = 0;
    //要执行num次
    while(front!=rear && i < num)
    {
        q = Q[++front];
        //取出队首元素 把他们的子节点放到队尾
        if(q->lchild!= NULL) Q[++rear] = q->lchild;
        if(q->rchild!= NULL) Q[++rear] = q->rchild;
        i++;

    }
    return q;
}
