//
// Created by User on 2024-03-18.
//
#include <iostream>
using namespace std;
#include "def.h"

void Delete(position p,LIST &L)
{
    position q = p;
    if((L.last < p) || (p < 1))
    //边界条件别忘了！！！！！！
    {
        cout << " position not exit" <<endl;
    }
    else
    {
        while(q < L.last)
        {
            L.elements[q] = L.elements[q + 1];
            q++;
        }
        L.last -= 1;
    }
}