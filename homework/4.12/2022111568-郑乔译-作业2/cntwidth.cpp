//
// Created by User on 2024-04-19.
//
//要计算每层的宽度 先定义一个数组 分别放每一层的宽度
//先根遍历 打印数组
#include "def.h"
#include "funcs.h"
using namespace std;



void cntwidth(BTREE T,int depth,int width[])
{
    if(T == NULL) {
        return;
    }

    width[depth]++;

    cntwidth(T->lchild,depth+1,width);

    cntwidth(T->rchild,depth+1,width);

}