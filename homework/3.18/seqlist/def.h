//
// Created by User on 2024-03-18.
//

#ifndef DATASTRUCTURE_DEF_H
#define DATASTRUCTURE_DEF_H
#include <iostream>
using namespace std;
#define maxlength 20
typedef int position;
typedef int Elementtype;

struct LIST{
    Elementtype elements[maxlength];
    int last;
};
#endif //DATASTRUCTURE_DEF_H
