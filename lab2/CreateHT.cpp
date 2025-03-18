//
// Created by User on 2024-04-11.
//
#include "def.h"
#include "funcs.h"
void CreateHT(huffmantree &T,int num)
{
    //T代表树 T的0-N-1存的是N个字符
    //现在需要这求出这个N

    //int i ,p1 ,p2;
    int p1 = 0;
    int p2 = 0;


    for(int i = num; i < 2*num-1; i++){
        SelectMin(T, i, p1, p2);
        //找到没有父母的最小的两个
        T[p1].parent =T[p2].parent = i;
        T[i].lchild= p1;
        T[i].rchild= p2;
        T[i].weight =T[p1].weight + T[p2].weight;
    }
    //从第num+1 开始存放合并之后的节点

}
