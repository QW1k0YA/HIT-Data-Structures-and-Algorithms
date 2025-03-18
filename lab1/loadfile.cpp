//
// Created by User on 2024-03-26.
//
#include "Stack.h"
#include "fstream"


void loadfile(string filename,char (&Txt)[MAX] )
{
    ifstream inputFile(filename);
    if(!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(0);
    }


    char value;
    int flag = 0;
    int i = 0;
    while(inputFile >> value)
    {
        if(value == '#')
        {
            flag++;
            continue;
        }
        //第一次遇见变成1，再遇见就变2结束
        if(flag == 1)
        {
            Txt[i++] = value;
        }
    }

    inputFile.close();

}