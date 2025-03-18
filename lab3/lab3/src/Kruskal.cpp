//
// Created by User on 2024-04-24.
//
#include <cmath>
#include "def.h"
#include "algorithm"
using namespace std;

bool cmp1(edge a,edge b)
{
    return a.cost < b.cost;
}

int Find(int a,int parents[])
{
    int i = a;
    while(1)
    {

        i = parents[i];
        /*if(i < -50)
        {
            break;
        }*/
        if(i == parents[i])
        {
            break;
        }

    }
    //return i+100;
    return i;
}
void Kruskal(edge (&edges)[SIZE], int vexnum, int arcnum)
//arc是边数 vex是点数
{   int bnf, edf;
    int parents[100];
   /* for(int i = 0;i < arcnum;i++){
        edges[i].color = i + 1;
    }*/
    sort(edges, edges+arcnum,cmp1); //按照权值大小排序 ,
    int i = 0;
    for(i=0;i<vexnum;i++) //初始化parent[]数组（连通分量）
        //parents[i]=i-100;
        parents[i]=i;


    for(i=0;i<arcnum-1;i++) {

        bnf=Find(edges[i].begin,parents);
        edf=Find(edges[i].end,parents);

/*        bnf = edges[i].color;2
        edf = edges[i+1].color;
*/
        if(bnf!=edf)
        { // 非同一连通分量
            parents[bnf]=edf; // 连成一个连通子图

            cout<<"("<<edges[i].begin<<",";
            cout<<edges[i].end<<","<<edges[i].cost<<")";
            cout<<endl;
        }
    }
}