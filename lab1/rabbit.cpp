//
// Created by User on 2024-03-28.
//

#include "math.h"
#include "iostream"
#include "fstream"

using namespace std;
#define MAX 100
typedef char ElemType;

typedef struct{
    ElemType elements[MAX];
    int top ;

}STACK;
typedef struct{
    int elements[MAX];
    int top ;

}STACK_;
char popstack(STACK &S);
void pushstack(STACK &S,char n);
void pushstack_(STACK_ &S,int n);
int popstack_(STACK_ &S);
void loadfile(string filename,char (&Txt)[MAX] );
void printstack(const STACK& s);
void printstack_(const STACK_& s);

int main()
{
    char str[MAX];
    //scanf("%s",str);

    loadfile("F:\\datastruct\\lab\\lab1\\test.txt",str);
    printf("%s\n\n",str);

    char strre[MAX];
    //strre ->postfix expression
    STACK op;
    // op -> "+-*/()"
    op.top = -1;

    int i = 0,j = 0;
    int numb[MAX] = {0};
    int m = 0;

    while(str[i]!='\0')
    {
        if((str[i] != '+') && (str[i] != '-') &&  (str[i] != '*') && (str[i] != '/') && (str[i] != '(') &&  (str[i] != ')'))
        {
            strre[j++] = str[i];
            numb[m]++;
        }

        else
        {
            if(str[i]!='(' && str[i]!=')')
            {
                m++;
            }
            if(op.top == -1)
            {
                pushstack(op,str[i]);
                printstack(op);
            }
            else if(str[i] == '(')
            {
                pushstack(op,str[i]);
                printstack(op);
            }
            else if((str[i] == '*' || str[i] =='/') && (op.elements[op.top] == '+' || op.elements[op.top] == '-'))
            {
                pushstack(op, str[i]);
                printstack(op);

                //*+
            }
            else if(str[i] == ')')
            {
                while(op.elements[op.top] != '(')
                {
                    strre[j++] = popstack(op);
                    printstack(op);
                }
                popstack(op);
                printstack(op);
            }
            else if(str[i] == '+' || str[i] =='-')
            {
                while(op.elements[op.top] != '(' )
                {
                    strre[j++] = popstack(op);
                    printstack(op);
                }
                pushstack(op,str[i]);
                printstack(op);

            }
                //++ +*
            else
            {
                while(op.elements[op.top] != '(' && op.elements[op.top] != '+' && op.elements[op.top] != '-')
                {
                    strre[j++] = popstack(op);
                    printstack(op);
                }
                pushstack(op,str[i]);
                printstack(op);
            }
            //**
        }

        i++;
    }

    if(op.top != -1)
    {
        while(op.top != -1)
        {
            strre[j++] = popstack(op);
            printstack(op);
        }
    }
    //postfix expression

    STACK_ opnum;
    //opnum -> numbers
    opnum.top = -1;
    int result = 0;
    int num = 0;
    m = 0;

    for(int k = 0;k < j;k++)
    {
        if(strre[k] != '+' && strre[k] != '-' && strre[k] != '*' && strre[k] != '/' )
        {

            if(num ==0 ) //第一次
            {
                opnum.elements[++opnum.top] = (strre[k] - '0')*int(pow(10,numb[m]-num-1));
                printstack_(opnum);
                num++;
            }
            else
            {
                if(numb[m] - num != 0)
                {
                    opnum.elements[opnum.top] += (strre[k] - '0')*int(pow(10,numb[m]-num-1));
                    num++;
                }
                else
                {
                    m++;
                    num = 0;
                    opnum.elements[++opnum.top] =(strre[k] - '0')*int(pow(10,numb[m]-num-1));
                    printstack_(opnum);
                    num++;
                }
            }

            //num++ 直到numb[m] - num == 0 m++
            //以后

        }
        else
        {


            int temp1 = popstack_(opnum);
            int temp2 = popstack_(opnum);
            int temp3;
            switch (strre[k])
            {
                case '+':
                {
                    temp3 =  temp1 +temp2 ;
                    break;
                }
                case '-':
                {
                    temp3 =  temp2 -temp1 ;
                    break;
                }
                case '*':
                {
                    temp3 = temp1 *temp2;
                    break;
                }
                case '/':
                {
                    temp3 = temp2 /temp1 ;
                    break;
                }
            }
            pushstack_(opnum,temp3);
            printstack_(opnum);
        }
    }

    cout << endl;
    for(int l = 0;l < j;l++)
    {
        cout << strre[l];
    }
    cout <<endl;
    printf("%d",int(opnum.elements[0]));
}

void printstack(const STACK& s)
{
    for(int i = 0;i <= s.top;i++)
    {
        cout << s.elements[i]<< " " ;
    }
    cout << endl;
}

void printstack_(const STACK_& s)
{
    for(int i = 0;i <= s.top;i++)
    {
        cout << s.elements[i]<< " " ;
    }
    cout << endl;
}


void loadfile(string filename,char (&Txt)[MAX] )
{
    ifstream inputFile(filename);
    if(!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(0);
    }


    char value;
    int flag = 0;
    int i = 0;
    while(inputFile >> value)
    {
        if(value == '#')
        {
            flag++;
            continue;
        }
        //第一次遇见变成1，再遇见就变2结束
        if(flag == 1)
        {
            Txt[i++] = value;
        }
    }

    inputFile.close();

}

void pushstack(STACK &S,char n)
{
    if(S.top >= MAX - 1)
    {
        cout << "stack is full"<<endl;
    }
    else
    {
        S.top++;
        S.elements[S.top] = n;
    }
}

void pushstack_(STACK_ &S,int n)
{
    if(S.top >= MAX - 1)
    {
        cout << "stack is full"<<endl;
    }
    else
    {
        S.top++;
        S.elements[S.top] = n;
    }
}


char popstack(STACK &S)
{
    char result = S.elements[S.top];
    if(S.top < 0)
    {
        cout <<"empty!";
    }
    else
    {
        S.top--;
    }

    return result;
}

int popstack_(STACK_ &S)
{
    int result = S.elements[S.top];
    if(S.top < 0)
    {
        cout <<"empty!";
    }
    else
    {
        S.top--;
    }

    return result;
}