//
// Created by User on 2024-03-25.
//

#ifndef LAB1_STACK_H
#define LAB1_STACK_H

#include "iostream"
using namespace std;
#define MAX 100
typedef char ElemType;

typedef struct{
    ElemType elements[MAX];
    int top ;

}STACK;
typedef struct{
    int elements[MAX];
    int top ;

}STACK_;
char popstack(STACK &S);
void pushstack(STACK &S,char n);
void pushstack_(STACK_ &S,int n);
int popstack_(STACK_ &S);
void loadfile(string filename,char (&Txt)[MAX] );
void printstack(const STACK& s);
void printstack_(const STACK_& s);

#endif //LAB1_STACK_H
