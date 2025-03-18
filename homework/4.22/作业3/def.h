//
// Created by User on 2024-04-27.
//

#ifndef INC_3_DEF_H
#define INC_3_DEF_H

#define EPS 0.000001
#define SIZE 1000

typedef struct node{
    int dot;
    int cost;
    struct node* next;
}Edgenode;
//边表
typedef struct{
    int dot;
    Edgenode * firstedge;
}Vertexnode;
//顶点表

typedef struct
{
    int n;
    int e;
    Vertexnode vexlist[SIZE];
}AdjGraph;
//图
typedef struct{
    int tail;
    int head;
    int cost;
}edge;
#endif //INC_3_DEF_H
