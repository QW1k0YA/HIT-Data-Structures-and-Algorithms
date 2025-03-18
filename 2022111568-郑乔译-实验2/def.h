//
// Created by User on 2024-04-11.
//

#ifndef LAB2_DEF_H
#define LAB2_DEF_H

#define ASCIISIZE 127
#define INFILEAD "F:\\datastruct\\lab\\lab2\\helloworld.txt"
#define  HUFFFILEAD "F:\\datastruct\\lab\\lab2\\Huffcode.txt"
#define DECODEAD "F:\\datastruct\\lab\\lab2\\decode.txt"
#include "iostream"
#include "vector"
using namespace std;

typedef struct { /* 结点型 */
    int weight ; /* 权值 */
    int lchild ; /* 左孩子链 */
    int rchild ; /* 右孩子链 */
    int parent; /* 双亲链 */
    char c;/*表示的是哪个字符*/
    string code;
}HTNODE ;

typedef HTNODE huffmantree[2*ASCIISIZE - 1];

typedef int numofchara;








#endif //LAB2_DEF_H
