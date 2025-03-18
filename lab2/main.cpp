#include <iostream>
#include "def.h"
#include "funcs.h"
using namespace std;
int main() {


    int file2array[127] = {0};
    int numofch = loadfile(INFILEAD,file2array);
    //已经得到了file2array
    /*
    for(int i = 0;i < 127;i++)
    {
        if(file2array[i] != 0)
        {
            cout << char(i)  <<  " " << file2array[i] << " ";
        }
    }
    cout << numofch;*/
    //loadfile没问题

    //下一步构建huffmantree

    //建立一个数组 大小为2*ASCIIsize-1
    //实际上用了 2*numofch - 1

    huffmantree T;
    //这个T要与numofch成对出现；
    InitHT(T,numofch);
    //初始化
    InputW(T,numofch,file2array);
    //赋权值
    //给前num个赋值
    CreateHT(T,numofch);
    //创建哈夫曼树
    huff2code(T,numofch);
    //把每一个符号的huffman编码算出来 放到结构体里

    //cout << "3";

    for(int i = 0;i < numofch;i++)
    {
        cout << T[i].c << ":" << T[i].code << endl;
    }

    file2code(T,numofch,INFILEAD,HUFFFILEAD);

    decode(T,numofch,HUFFFILEAD,DECODEAD);

    double com = comprerate(INFILEAD,HUFFFILEAD);
    cout << "the compression rate is:" << com << endl;











}
