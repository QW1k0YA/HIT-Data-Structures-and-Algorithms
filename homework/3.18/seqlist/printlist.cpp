//
// Created by User on 2024-03-18.
//
#include <iostream>
using namespace std;
#include "def.h"

void printlist(const LIST &L)
{
    for(int i = 0;i <= L.last;i++)
    {
        cout << L.elements[i] <<" ";
    }
    cout << endl;
}