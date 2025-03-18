//
// Created by User on 2024-04-12.
//
#include "def.h"
#include "fstream"

using namespace std;

string loadfile(const string& filename)
{
    ifstream input(filename);

    if(!input.is_open())
    {
        cerr << "fail to open file in loadfile";
    }

    string s;
    getline(input,s);

    return s;

}