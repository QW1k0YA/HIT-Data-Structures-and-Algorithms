//
// Created by User on 2024-03-19.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H
#include "def.h"
LIST createlist(int n);
void deletelocate(LIST l,int n);
void printlist(const LIST& l);
void deleteduplicate(LIST l);
void inverselist(LIST l);
void cyclemove(LIST l,int num,bool isleft);
LIST createnull(int n);
LIST mergelist(const LIST& l1,const LIST& l2);



#endif //LINKLIST_LINKLIST_H
