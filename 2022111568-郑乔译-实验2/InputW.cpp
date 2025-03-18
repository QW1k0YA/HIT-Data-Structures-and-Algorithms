//
// Created by User on 2024-04-11.
//
#include "def.h"

void InputW(huffmantree &T,int num,int (&file2array)[127])
{
    int j = 0;
    //j对应T
    for(int i = 0;i < ASCIISIZE;i++)
    //i对应array
    {
        if(file2array[i]!=0)
        {
            T[j].weight = file2array[i];
            T[j].c = char(i);
            j++;
        }
    }

    //不出以外的话 这里t应该是num个值被赋值了
    /*
    if(j == num)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << j << "=j  no!" << endl;
    }
*/
}