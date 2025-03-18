//
// Created by User on 2024-04-22.
//

#include "def.h"
#include "algorithm"
#include "cmath"
using namespace std;
/*void loadfile(const string& filename,int (&result)[SIZE],int &num)
//浮点数算了吧 读进来太费劲了
{
//从文件中读出一个数组
//用寻访地址的方式来变成二维数组

ifstream input(filename);

int value;

int i = 0;
//这个图最大100个点
while(input >> value)
{
result[i++] = value;
}

//i的值为输入值的个数
if( pow(i,0.5) - int(pow(i,0.5)) > EPS)
//比较是否相等（浮点数） 看看是不是一个正方形矩阵
{
cerr << "column should = row" <<endl;
exit(0);
}

num = int(pow(i,0.5));
}
#include "math.h"
using namespace std;
*/
void loadfile(const string& filename,int (&result)[SIZE],int &num)
{
    //从文件中读出一个数组
    //用寻访地址的方式来变成二维数组

    ifstream input(filename);

    int value;

    int i = 0;
    //这个图最大100个点
    while(input >> value)
    {
        result[i++] = value;
    }

    //i的值为输入值的个数
    if( pow(i,0.5) - int(pow(i,0.5)) > EPS)
    //比较是否相等（浮点数） 看看是不是一个正方形矩阵
    {
        cerr << "column should = row" <<endl;
        exit(0);
    }

    num = int(pow(i,0.5));
}