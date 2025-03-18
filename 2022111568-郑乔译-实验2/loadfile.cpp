//
// Created by User on 2024-04-11.
//

#include "fstream"
#include "def.h"
using namespace std;

numofchara loadfile(string filename,int (&file2array)[127])
{
    //file2arr为127 的数组 对应ASCII码
    ifstream input(filename);
    if(!input.is_open())
    {
        cerr << "fail to open the file in loadfile!";
        cout << endl;
    }


    input >> noskipws;
    //不然会自动忽略空格和换行
    char value;
    while(input >> value)
    {
        /*
        file2arr[value].weight++;
        file2arr[value].c = value;
         */
        //ASCII码对应的那个索引 存这个字符和权重

        file2array[value] ++;
        //索引对应ASCII码 数值代表权重
    }

    int result = 0;
    for(int i = 0;i < ASCIISIZE;i++)
    {
        /*
        if(file2arr[i].weight != 0)
        {
            result++;
        }*/
        if(file2array[i] != 0)
        {
            result++;
        }
    }

    input.close();

    return result;

    //得到了ASCII码对应的松散的数组 file2array 索引对应ASCII码 数值代表权重
    //得到了字符的种类数
    //下一步应该根据这两个东西构建HTNOTE数组
}