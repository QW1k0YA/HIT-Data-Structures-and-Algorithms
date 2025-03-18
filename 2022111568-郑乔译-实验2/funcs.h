//
// Created by User on 2024-04-11.
//

#ifndef LAB2_FUNCS_H
#define LAB2_FUNCS_H
#include "def.h"

numofchara loadfile(string filename,int (&file2array)[127]);
void InitHT(huffmantree& T,int num);
void InputW(huffmantree &T,int num,int (&file2array)[127]);
void SelectMin(huffmantree &T,int num,int &p1,int&p2);
void CreateHT(huffmantree &T,int num);
void huff2code(huffmantree &T,int num);
void file2code(huffmantree &T,int num,const string& inputfile,const string& codefile);
void decode(huffmantree & T,int num,const string& codefile,const string& decodefile);
double comprerate(const string& filename1,const string& filename2);
#endif //LAB2_FUNCS_H
