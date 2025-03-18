//
// Created by User on 2024-04-11.
//
#include "def.h"
#include "fstream"

using namespace std;

void decode(huffmantree & T,int num,const string& codefile,const string& decodefile)
{
    ifstream input(codefile);
    ofstream output(decodefile);

    if(!input.is_open())
    {
        cerr << "fail to open file in decode (input)";
        exit(0);
    }
    if(!output.is_open())
    {
        cerr << "fail to open file in decode (output)";
        exit(0);
    }

    string s;
    getline(input,s);
    s += "0";
    // 原来正常读取 但是最后一位进来的时候还没等判断就结束了 因此加一位数
    //这个循环是滞后的
    char value = '\0';
    int i = 2*num - 2;
    //i是根节点
    for(int j = 0;j < s.size();j++)
    {
        if(s[j] == '0' && T[i].lchild != -1)
        {
                i = T[i].lchild;
        }
        else if(s[j] == '1' && T[i].rchild != -1)
        {
                i = T[i].rchild;
        }
        else
        {
                output << T[i].c;
                i = 2*num - 2;
                if(s[j] == '0' && T[i].lchild != -1)
                {
                    i = T[i].lchild;
                }
                else if(s[j] == '1' && T[i].rchild != -1)
                {
                    i = T[i].rchild;
                }
                //下一次的已经读进来了！！因此要直接在这里进行一步操作
        }
    }

    input.close();
    output.close();
}