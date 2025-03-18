//
// Created by User on 2024-04-11.
//
#include "def.h"

void InitHT(huffmantree& T,int num)
{
    for(int i = 0;i < 2*num - 1;i++)
    {
        T[i].weight = 0;
        T[i].parent = -1;
        T[i].rchild = -1;
        T[i].lchild = -1;
        T[i].c = '\0';
        T[i].code = "";
    }
}
