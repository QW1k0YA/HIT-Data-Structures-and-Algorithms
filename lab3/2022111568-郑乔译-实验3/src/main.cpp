#include <iostream>
#include "def.h"
#include "funcs.h"

int main() {

    string s = FILEAD;
    int graph[SIZE] = {0};
    int row = 0;
    loadfile(s,graph,row);

    Prim(graph,row);

    edge in[SIZE];
    int n = createedge(graph,row,in);
    //n是边数
    //in 里面的点开始和结束都是从1开始的
    Kruskal(in, row, n);
    cout << " " <<endl;
}
