//
// Created by User on 2024-03-18.
//

#ifndef DATASTRUCTURE_SEQLISTOPER_H
#define DATASTRUCTURE_SEQLISTOPER_H
using namespace std;
#include "def.h"
position End(LIST L);
void Delete(position p,LIST &L);
void inverselist(LIST &L,position fir, position end);
void movecycle(LIST &L,int num,bool isleft);
LIST mergelist(const LIST& l1,const LIST& l2);
void printlist(const LIST &L);
void deleterepeat(LIST &L);

#endif //DATASTRUCTURE_SEQLISTOPER_H
