//
// Created by User on 2024-04-22.
//
#include <cmath>
#include "def.h"
#include "algorithm"
using namespace std;


void Prim(int *C,int n)
//c表示联通矩阵 用一维数组表示二维数组
//n为点的个数
{   int LOWCOST[100] = {0};
    //数组LOWCOST[n]：用来保存集合V-U中各顶点与集合U中顶点最短边的权值，LOWCOST[v]=infinity表示顶点v已加入最小生成树中（进入u）；
    //下标表示顶点 数值代表权值
    int CLOSSET[100] = {0};
    //数组CLOSSET[n] ：用来保存依附于该边的（集合V-U中各顶点与集合U中顶点的最短边）在集合U中的顶点。
    //下标表示这个最短边对应的顶点    数值表示依附的u中的顶点
    int i, j, k;
    int min;
    for( i=0; i< n; i++ )
    {
        LOWCOST[i] = C[i];
        //C第一行代表和顶点1的距离
        CLOSSET[i] = 1;
        //i从0开始 但是他的值是从1开始的！
    }
    LOWCOST[0] = MYINFI;

    //先把i = 1装进u
    //现在 lowcost中都是离1的距离 其中lowcost 0 = 0
    //现在 closset中都是依附于1点的  都是1
    //这块有点坑 因为INFINITY是浮点数 自动转化为int后就肯定会比原来小 所以 LOWCOST[j] < INFINITY永远成立

    for( i = 1; i < n; i++ )
    {
        min = LOWCOST[i];
        k = i;

        for( j = 1; j < n; j++ )
        {
            if ( LOWCOST[j] < min && LOWCOST[j]!= 0)
            {
                min = LOWCOST[j] ;
                k=j;
            }
        }
        //min代表最近的距离
        // k代表现在最近的边来自哪u-v的哪个点

        //输出最小生成树的边信息
        cout << "(" << k + 1 << "," << CLOSSET[k] << ")" << endl;
        LOWCOST[k] = MYINFI ; //3.3把顶点k加入最小生成树中
        for ( j = 0; j < n; j++ ) //3.4调整数组LOWCOST和CLOSSET
            if ((C[k*n+j] < LOWCOST[j] && LOWCOST[j] < MYINFI && C[k*n + j]!= 0) ||  (C[k*n + j]!= 0 && LOWCOST[j] == 0))
            //k正好是从0开始的 所以不用k-1
            {
                //C[k*n+j]代表k到j的距离
                // k这个点加进去了 考察第k行（和k相邻的） 如果有比最近还近的 那就用这个了
                //原来那些等于0的点表示原来和u集合里的点没有直接通路 要及时更新
                LOWCOST[j]=C[k*n+j];
                CLOSSET[j]=k+1;
            }
    }
}