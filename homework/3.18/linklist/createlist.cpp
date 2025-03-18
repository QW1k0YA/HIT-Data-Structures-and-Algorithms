//
// Created by User on 2024-03-18.
//
#include "def.h"

LIST createlist(int n)
{
    LIST ptr,tail,head= NULL;
    head = (LIST) malloc(sizeof(celltype));
    tail = head;
    for(int i = 0;i < n ;i++)
    {
        ptr = (LIST) malloc(sizeof(celltype));
        cin >> ptr->data;
        tail->next = ptr;
        tail = ptr;
    }
    tail->next = NULL;
    return head;
}
