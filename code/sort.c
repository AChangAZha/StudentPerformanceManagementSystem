#include "model.h"
#include "sort.h"
#include <stdlib.h>
#include <string.h>

ugnode *setUClassList(char classTmp[]) //建立查找本科班级链表
{
    ugnode *uPtr = ugHead->next;
    ugnode *newUgHead, *node, *newPre;
    newUgHead = (ugnode *)malloc(sizeof(ugnode));
    newUgHead->next = NULL;
    newPre = newUgHead;

    while (uPtr != NULL)
    {
        if ((strcmp(uPtr->data.classes, classTmp)) == 0)
        {
            node = (ugnode *)malloc(sizeof(ugnode));
            node->data = uPtr->data;
            node->next = NULL;
            newPre->next = node;
            newPre = node;
        }
        uPtr = uPtr->next;
    }
    return newUgHead;
}

pgnode *setPClassList(char classTmp[]) //建立查找研究生班级链表
{
    pgnode *pPtr = pgHead->next;
    pgnode *newPgHead, *node, *newPre;
    newPgHead = (pgnode *)malloc(sizeof(pgnode));
    newPgHead->next = NULL;
    newPre = newPgHead;

    while (pPtr != NULL)
    {
        if ((strcmp(pPtr->data.classes, classTmp)) == 0)
        {
            node = (pgnode *)malloc(sizeof(pgnode));
            node->data = pPtr->data;
            node->next = NULL;
            newPre->next = node;
            newPre = node;
        }
        pPtr = pPtr->next;
    }
    return newPgHead;
}

void newlistDestroy(ugnode *newUgListHead, pgnode *newPgListHead) //销毁两条链表
{
    ugnode *uTmp, *uPtr;
    pgnode *pTmp, *pPtr;
    uPtr = newUgListHead;
    pPtr = newPgListHead;

    while (uPtr != NULL)
    {
        uTmp = uPtr;
        uPtr = uPtr->next;
        free(uTmp);
    }
    while (pPtr != NULL)
    {
        pTmp = pPtr;
        pPtr = pPtr->next;
        free(pTmp);
    }
}