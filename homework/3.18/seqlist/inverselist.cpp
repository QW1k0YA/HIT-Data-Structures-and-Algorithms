//
// Created by User on 2024-03-18.
//
#include <iostream>
using namespace std;
#include "def.h"
#include "seqlistoper.h"

void inverselist(LIST &L,position fir, position end)
{
    if(fir > end)
    {
        cout << "fir should < end" <<endl;
    }
    else{
        int temp = 0;
        while(fir < end)
        {
            temp = L.elements[fir];
            L.elements[fir] =  L.elements[end];
            L.elements[end] = temp;
            fir++;
            end--;
        }
    }
}
