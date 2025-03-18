//
// Created by User on 2024-03-18.
//
#include <iostream>
using namespace std;
#include "def.h"
#include "seqlistoper.h"

void deleterepeat(LIST &L)
{
    int i = 0,j = 1;
    while(j <= L.last)
    {
        if(L.elements[i] == L.elements[j])
        {
            Delete(j,L);
        }
        else
        {
            i++;
            j++;
        }
    }
}
