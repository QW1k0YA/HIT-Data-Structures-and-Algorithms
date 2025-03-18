//
// Created by User on 2024-04-12.
//

#ifndef INC_4_12_FUNCS_H
#define INC_4_12_FUNCS_H
#include "def.h"
using namespace std;

string loadfile(const string& filename);
void createtr(BTREE& T,const string& s);
void preorder(BTREE& T);
void inorder(BTREE& T);
void postorder(BTREE& T);
void preorder_(BTREE T);
void inorder_(BTREE T);
void postorder_(BTREE root);
void leverorder(BTREE T);
BTREE gotoindex(BTREE T,int num);
int numofT(BTREE T);
bool ifcomplete(BTREE T);
void cntwidth(BTREE T,int depth,int width[]);
#endif //INC_4_12_FUNCS_H
