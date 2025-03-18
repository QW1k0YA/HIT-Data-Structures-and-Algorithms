//
// Created by User on 2024-04-11.
//
#include "def.h"

void SelectMin(huffmantree &T,int num,int &p1,int&p2)
//这里的num是动态的 表示T的长度 从numofch到2*numofch-1
{
    for(p1 = 0;p1 < num;p1++)
    {
        if(T[p1].parent == -1)
        {
            break;
        }
    }

    for(p2 = p1 + 1;p2 < num;p2 ++)
    {
        if(T[p2].parent == -1)
        {
            break;
        }
    }
    //给p1 p2赋初值 循环遍历找到根节点

    //先排序
    for(int i = 0;i < num;i++)
    {
        if(T[i].parent == -1 && T[i].weight < T[p1].weight && i!= p2)
        {
            p1 = i;
        }
    }
    //p1最小
    for(int i = 0;i < num;i++)
    {
        if(i == p1)
        {
            continue;
        }

        if(T[i].parent == -1 && T[i].weight < T[p2].weight )
        {
            p2 = i;
        }
    }
    //p2第二小
}