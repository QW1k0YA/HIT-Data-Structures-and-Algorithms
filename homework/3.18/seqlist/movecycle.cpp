//
// Created by User on 2024-03-18.
//
#include <iostream>
using namespace std;
#include "def.h"
#include "seqlistoper.h"

void movecycle(LIST &L,int num,bool isleft)
{
    if(isleft)
    {
        inverselist(L,0,num-1);
        inverselist(L,num,L.last);
        inverselist(L,0,L.last);
    }
    else
    {
        inverselist(L,0,L.last - num);
        inverselist(L,L.last - num + 1,L.last);
        inverselist(L,0,L.last);
    }
}