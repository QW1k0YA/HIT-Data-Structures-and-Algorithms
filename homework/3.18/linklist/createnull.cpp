//
// Created by User on 2024-03-19.
//
#include "def.h"

LIST createnull(int n)
{
    LIST ptr,tail,head= NULL;
    head = (LIST) malloc(sizeof(celltype));
    tail = head;
    for(int i = 0;i < n ;i++)
    {
        ptr = (LIST) malloc(sizeof(celltype));
        tail->next = ptr;
        tail = ptr;
    }
    tail->next = NULL;
    return head;
}
