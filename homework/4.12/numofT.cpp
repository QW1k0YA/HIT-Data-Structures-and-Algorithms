//
// Created by User on 2024-04-19.
//
#include "def.h"
#include "vector"
using namespace std;

int numofT(BTREE T)
{

    BTREE Q[N];
    int front = 0;
    int rear = 0;
    //队尾入 队首出

    BTREE  q;
    if(T == NULL)
    {
        return 0;
    }

    Q[++rear] = T;
    //从1开始
    int i = 0;
    while(front!=rear)
    {
        q = Q[++front];
        //取出队首元素 把他们的子节点放到队尾

        if(q->lchild!= NULL) Q[++rear] = q->lchild;
        if(q->rchild!= NULL) Q[++rear] = q->rchild;
        i++;
    }
    return i;
}

