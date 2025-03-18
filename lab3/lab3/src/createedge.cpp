//
// Created by User on 2024-04-24.
//
#include <cmath>
#include "def.h"
#include "algorithm"
using namespace std;

int createedge(int *C,int n,edge re[])
{
    int k = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = i;j < n;j++)
        {
            if(C[i*n+j] != 0)
            {
                re[k].begin = i+1;
                re[k].end = j+1;
                re[k++].cost = C[i*n+j];

            }
        }
    }

    return k;
}