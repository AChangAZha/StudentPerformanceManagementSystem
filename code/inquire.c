#include "model.h"
#include "inquire.h"
#include <stdio.h>

ugnode *serchUg(int num) //在本科生链表中搜索
{
    ugnode *uPtr=ugHead->next;
    while (uPtr!=NULL)
    {
        if(uPtr->data.num==num) return uPtr;
        uPtr=uPtr->next;
    }
    return NULL;  //没找到则返回NULL
}

pgnode *serchPg(int num)  //在研究生链表中搜索
{
    pgnode *pPtr=pgHead->next;
    while (pPtr!=NULL)
    {
        if(pPtr->data.num==num) return pPtr;
        pPtr=pPtr->next;
    }
    return NULL;
}