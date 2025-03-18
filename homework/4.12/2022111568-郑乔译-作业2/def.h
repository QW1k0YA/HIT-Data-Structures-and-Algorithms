//
// Created by User on 2024-04-12.
//

#ifndef INC_4_12_DEF_H
#define INC_4_12_DEF_H
#include "iostream"
#define FILEAD "F:\\datastruct\\homework\\4.12\\test.txt"
#define FILEAD2 "F:\\datastruct\\homework\\4.12\\test2.txt"
#define N 1000
typedef struct node {
    struct node *lchild ;
    struct node *rchild ;
    char data ;
}NODE;
typedef struct node * BTREE ;
typedef struct {
    BTREE ptr;
    int flag;
}Stack;



#endif //INC_4_12_DEF_H
