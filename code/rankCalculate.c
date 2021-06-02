#include "rankCalculate.h"
#include <stdio.h>
#include <string.h>
#include "model.h"

void schoolRankCalculate() //计算校级排名
{
    ugnode *uPtr = ugHead->next, *uCmp;
    pgnode *pPtr = pgHead->next, *pCmp;
    while (uPtr != NULL)
    {
        if (uPtr->data.totalScore != -1)
        {
            uPtr->data.schoolRank = 1;
            uCmp = ugHead->next;
            while (uCmp != NULL)
            {
                if (uPtr->data.totalScore < uCmp->data.totalScore)
                    uPtr->data.schoolRank++;
                uCmp = uCmp->next;
            }
        }
        else
            uPtr->data.schoolRank = -1;
        uPtr = uPtr->next;
    }
    while (pPtr != NULL)
    {
        if (pPtr->data.totalScore != -1)
        {
            pPtr->data.schoolRank = 1;
            pCmp = pgHead->next;
            while (pCmp != NULL)
            {
                if (pPtr->data.totalScore < pCmp->data.totalScore)
                    pPtr->data.schoolRank++;
                pCmp = pCmp->next;
            }
        }
        else
            pPtr->data.schoolRank = -1;
        pPtr = pPtr->next;
    }
}

void classRankCalculate() //计算班级排名
{
    ugnode *uPtr = ugHead->next, *uCmp;
    pgnode *pPtr = pgHead->next, *pCmp;
    while (uPtr != NULL)
    {
        if (uPtr->data.totalScore != -1)
        {
            uPtr->data.classRank = 1;
            uCmp = ugHead->next;
            while (uCmp != NULL)
            {
                if (strcmp(uPtr->data.classes, uCmp->data.classes) == 0)
                    if (uPtr->data.totalScore < uCmp->data.totalScore)
                        uPtr->data.classRank++;
                uCmp = uCmp->next;
            }
        }
        else
            uPtr->data.classRank = -1;
        uPtr = uPtr->next;
    }
    while (pPtr != NULL)
    {
        if (pPtr->data.totalScore != -1)
        {
            pPtr->data.classRank = 1;
            pCmp = pgHead->next;
            while (pCmp != NULL)
            {
                if (strcmp(pPtr->data.classes, pCmp->data.classes) == 0)
                    if (pPtr->data.totalScore < pCmp->data.totalScore)
                        pPtr->data.classRank++;
                pCmp = pCmp->next;
            }
        }
        else
            pPtr->data.classRank = -1;
        pPtr = pPtr->next;
    }
}