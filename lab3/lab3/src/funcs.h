//
// Created by User on 2024-04-22.
//

#ifndef LAB3_FUNCS_H
#define LAB3_FUNCS_H
#include "def.h"

using namespace std;

void loadfile(const string& filename,int (&result)[10000],int &num);
void Prim(int *C,int n);
int createedge(int *C,int n,edge re[]);
void Kruskal(edge (&edges)[SIZE], int vexnum, int arcnum);
#endif //LAB3_FUNCS_H
