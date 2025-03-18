//
// Created by User on 2024-03-18.
//

#ifndef LINKLIST_DEF_H
#define LINKLIST_DEF_H
#include <iostream>
using namespace std;
typedef int Elemtype;

struct celltype{
    Elemtype data;
    celltype *next;
};

typedef celltype* LIST;
typedef celltype* position;




#endif //LINKLIST_DEF_H
