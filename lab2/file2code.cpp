//
// Created by User on 2024-04-11.
//
#include "def.h"
#include "fstream"
using namespace std;

void file2code(huffmantree &T,int num,const string& inputfile,const string& codefile)
{
    ifstream input(inputfile);
    ofstream output(codefile);

    if(!input.is_open())
    {
        cerr << " fail to open the file in file2code(input)" << endl;
        exit(0);
    }
    if(!output.is_open())
    {
        cerr << " fail to open the file in file2code(input)" << endl;
        exit(0);
    }

    char value;
    input >> noskipws;
    //不然会自动忽略空格和换行
    while(input >> value)
    {
        for(int i = 0;i < num;i++)
        {
            if(value == T[i].c)
            {
                output << T[i].code;
            }
        }
    }

    output << endl;

    input.close();
    output.close();

}