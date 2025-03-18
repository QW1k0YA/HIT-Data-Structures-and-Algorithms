//
// Created by User on 2024-04-11.
//
#include "def.h"
#include "fstream"
using namespace std;

double comprerate(const string& filename1,const string& filename2)
{
    /*
    int i = 0;

    while( (1 << i) < num)
    {
        i++;
    }

    cout << i << endl;

    //最少用i位二进制编码能进行区分



 */

    int simplecode = 0;

    ifstream in(filename1);
    char value;
    while(in >> value)
    {
        size_t temp = value;
        //unsigned int temp = value;
        // int temp = value;
        while(temp)
        {
            simplecode++;
            temp >>= 1;
        }
    }
    cout << simplecode <<endl;

    in.close();

    ifstream input(filename2);
    string s;
    getline(input,s);
    size_t huffcode = s.size();
    cout << huffcode <<endl;

    input.close();

    double result = 1 - ((huffcode+0.0)/simplecode);
    return result;
}