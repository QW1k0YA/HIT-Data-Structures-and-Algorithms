//
// Created by User on 2024-04-19.
//
#include "def.h"
#include "vector"
#include "funcs.h"
using namespace std;

bool ifcomplete(BTREE T)
//num为节点个数
{
    //bool flag = true;
    //遍历每一个节点
    int num = numofT(T);
    //cout << num;
    for(int i = 2;i <= num;i++)
    //遍历每一个节点 看看是否符合条件
    {
        //若i = 1, 则 i 是根结点，无父结点；
        if( i > 1)
        {
            BTREE temp = gotoindex(T,i);
            int n = i/2;
            if(temp != gotoindex(T,n)->rchild && temp != gotoindex(T,n)->lchild)
            {
                return false;
            }
        }

        if( 2*i <= num )
        {
            if(gotoindex(T,i)->lchild == NULL || gotoindex(T,i)->lchild != gotoindex(T,2*i))
            {
                return false;
            }
        }
        else
        {
            if(gotoindex(T,i)->lchild != NULL)
            {
                return false;
            }
        }

        if( 2*i + 1 <= num )
        {
            if(gotoindex(T,i)->rchild == NULL || gotoindex(T,i)->rchild != gotoindex(T,2*i + 1))
            {
                return false;
            }
        }
        else
        {
            if(gotoindex(T,i)->rchild != NULL)
            {
                return false;
            }
        }
    }

    return true;
}