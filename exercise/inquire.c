#include "model.h"
#include "inquire.h"
#include <stdio.h>

ugnode *serchUg(int num)
{
    ugnode *uPtr=ugHead->next;
    while (uPtr!=NULL)
    {
        if(uPtr->data.num==num) return uPtr;
        uPtr=uPtr->next;
    }
    return NULL;
}

pgnode *serchPg(int num)
{
    pgnode *pPtr=pgHead->next;
    while (pPtr!=NULL)
    {
        if(pPtr->data.num==num) return pPtr;
        pPtr=pPtr->next;
    }
    return NULL;
}