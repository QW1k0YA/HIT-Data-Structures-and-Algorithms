//
// Created by User on 2024-04-27.
//
#include "def.h"
#include "iostream"
using namespace std;


void matrix2list(AdjGraph &G,const string& filename,int num,int (&C)[SIZE])
{
    G.n = num;
    G.e = 0;
/*
    for(int i = 0;i < num;i++)
    {
        for(int j = i;j < num ;j++)
        {
            if(C[i*num+j]!=0)
            {
                G.e++;
            }
        }
    }
    //计算出边数

    int cnt = 0;
    edge e[SIZE];
    for(int i = 0;i < num;i++)
    {
        for(int j = 0;j < num ;j++)
        {
            if(C[i*num+j]!=0)
            {
                cnt++;
                e[cnt].head = i;
                e[cnt].tail = j;
                e[cnt].cost = C[i*num+j];
            }
        }
    }
    //边的信息都在里面了
*/

    edge e[SIZE];
    for(int i = 0;i < num;i++)
    {
        for(int j = 0;j < num ;j++)
        {
            if(C[i*num+j]!=0)
            {
                G.e++;
                e[G.e].head = i;
                e[G.e].tail = j;
                e[G.e].cost = C[i*num+j];
            }
        }
    }
    //边的信息都在里面了
    for(int i = 0;i < G.n;i++)
    {
        G.vexlist[i].dot = i+1;
        G.vexlist[i].firstedge = NULL;
    }
    //建立边表 （从1开始）

    for(int i = 0;i < G.e;i++)
    {

    }
}