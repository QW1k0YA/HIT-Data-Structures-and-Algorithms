//
// Created by User on 2024-04-12.
//
#include "def.h"
using namespace std;

int i = 0;
void createtr(BTREE &T,const string& str)
{

    char c;
    //scanf("%c",&c);
    //cin >> c;
    string s = str + "#";
    //最后一个‘#'没有读取到
    //每一次都会加上“#” 所以const也不是真正的const 猜测是把地址赋给s了

    if(s[i]!='\0')
    {
        c = s[i++] ;
    }
    if(s[i] == '\0')
    {
        return;
    }

    if(c == '#')
    {
        T = NULL;
    }
    else
    {
        T = new NODE;
        //建立新节点 new函数！
        T->data = c;
        createtr(T->lchild,s);
        createtr(T->rchild,s);
    }
}