#include <iostream>
#include "def.h"
#include "funcs.h"

int main() {
    string str = loadfile(FILEAD2);
    BTREE T;
    createtr(T,str);

    preorder(T);
    cout << endl;

    inorder(T);
    cout << endl;

    postorder(T);
    cout << endl;

   // PreOrder_(T,Sta);
    //cout << endl;
    preorder_(T);
    cout << endl;


    inorder_(T);
    cout << endl;


    postorder_(T);
    cout <<endl;


    leverorder(T);
    cout << endl;


    /*
    BTREE Sta5[N];
    BTREE Ttest1 = gotoindex(T,Sta5,1);
    BTREE Ttest2 = gotoindex(T,Sta5,3);

    cout << endl;
    cout << Ttest1->data;
    cout << endl;
    cout << Ttest2->data;*/
    //想法：按照层序遍历的顺序对二叉树进行编号
    //建立一个新的层序访问函数 ：访问到第i个元素
    //经过上面的测试 gotoindex应该问题不大

    bool a = ifcomplete(T);
    if(a)
    {
        cout << "is complete";
    }
    else
    {
        cout << "is not complete";
    }
    cout << endl;

    int width[100] = {0};
    cntwidth(T,0,width);

    int max = 1;
    for(int i = 0;i < 100;i++)
    {
        if(width[i] > max)
        {
            max = width[i];
        }
    }
    cout << "width = " << max;


}
