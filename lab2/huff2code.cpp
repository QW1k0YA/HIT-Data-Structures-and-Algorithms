//
// Created by User on 2024-04-11.
//
#include "funcs.h"
#include "def.h"
#include "algorithm"
void huff2code(huffmantree &T,int num)
//codestring为编码
{
    int i = 0;
    int j = 0;
    for(i = 0;i < num;i++)
    {
        j = i;
        //j用于不断上溯更新
        while(T[j].parent != -1)
        {
            if(j == T[T[j].parent].lchild)
            {
                T[i].code += "0";
            }
            else if(j == T[T[j].parent].rchild)
            {
                T[i].code += "1";
            }
            j = T[j].parent;
        }
        reverse(T[i].code.begin(),T[i].code.end());
        //！！！刚开始没写这句 发现不满足前缀性 从上到下才是一定唯一的 因此 应该翻转
    }


}