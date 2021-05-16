#include "model.h"
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tool.h"

void scoreSort()
{
    ugnode *uSortPre = NULL, *uTmp = NULL, *uOri = NULL, *uSortCur = NULL;
    pgnode *pSortCur = NULL, *pTmp = NULL, *pOri = NULL, *pSortPre = NULL;
    int uflag, pflag, item;

    while (1)
    {
        system("cls");
        printf("-----------------------------------------------------\n");
        printf("   1.查看本科生排名结果      2.查看研究生排名结果    \n");
        printf("                       3.退出                        \n");
        printf("-----------------------------------------------------\n");
        printf("请输入菜单编号：");
        do
        {
            enterNum(&item);
            if (item < 1 || item > 3)
                printf("错误！请输入正确的数字：");
        } while (item < 1 || item > 3);

        system("cls");
        switch (item)
        {
        case 1:
        {
            if (ugHead->next == NULL)
            {
                printf("暂无数据\n");
                break;
            }
            uOri = ugHead->next->next;
            ugHead->next->next = NULL;
            while (uOri != NULL)
            {
                uSortPre = ugHead;
                uSortCur = uSortPre->next;
                uTmp = uOri->next;

                while (uSortCur != NULL)
                {
                    uflag = 0;
                    if (uSortCur->data.totalScore < uOri->data.totalScore)
                    {
                        uOri->next = uSortCur;
                        uSortPre->next = uOri;
                        uflag++;
                        break;
                    }
                    uSortPre = uSortCur;
                    uSortCur = uSortCur->next;
                }
                if (uflag == 0)
                {
                    uSortPre->next = uOri;
                    uOri->next = NULL;
                }
                uOri = uTmp;
            }
            printf("排序后的全部本科生信息：\n\n");
            printUList(ugHead);
            recoverUList();
            break;
        }
        case 2:
        {
            if (pgHead->next == NULL)
            {
                printf("暂无数据\n");
                break;
            }
            pOri = pgHead->next->next;
            pgHead->next->next = NULL;
            while (pOri != NULL)
            {
                pSortPre = pgHead;
                pSortCur = pSortPre->next;
                pTmp = pOri->next;

                while (pSortCur != NULL)
                {
                    pflag = 0;
                    if (pSortCur->data.totalScore < pOri->data.totalScore)
                    {
                        pOri->next = pSortCur;
                        pSortPre->next = pOri;
                        pflag++;
                        break;
                    }
                    pSortPre = pSortCur;
                    pSortCur = pSortCur->next;
                }
                if (pflag == 0)
                {
                    pSortPre->next = pOri;
                    pOri->next = NULL;
                }
                pOri = pTmp;
            }
            printf("排序后的全部研究生信息：\n\n");
            printPList(pgHead);
            recoverPList();
            break;
        }
        case 3:
            return;
        }
        system("pause");
    }
}

void recoverUList()
{
    ugnode *uSortPre = NULL, *uTmp = NULL, *uOri = NULL, *uSortCur = NULL;
    int uflag;

    uOri = ugHead->next->next;
    ugHead->next->next = NULL;
    while (uOri != NULL)
    {
        uSortPre = ugHead;
        uSortCur = uSortPre->next;
        uTmp = uOri->next;

        while (uSortCur != NULL)
        {
            uflag = 0;
            if (uSortCur->data.num > uOri->data.num)
            {
                uOri->next = uSortCur;
                uSortPre->next = uOri;
                uflag++;
                break;
            }
            uSortPre = uSortCur;
            uSortCur = uSortCur->next;
        }
        if (uflag == 0)
        {
            uSortPre->next = uOri;
            uOri->next = NULL;
        }
        uOri = uTmp;
    }
}

void recoverPList()
{
    pgnode *pSortCur = NULL, *pTmp = NULL, *pOri = NULL, *pSortPre = NULL;
    int pflag;

    pOri = pgHead->next->next;
    pgHead->next->next = NULL;

    while (pOri != NULL)
    {
        pSortPre = pgHead;
        pSortCur = pSortPre->next;
        pTmp = pOri->next;

        while (pSortCur != NULL)
        {
            pflag = 0;
            if (pSortCur->data.num > pOri->data.num)
            {
                pOri->next = pSortCur;
                pSortPre->next = pOri;
                pflag++;
                break;
            }
            pSortPre = pSortCur;
            pSortCur = pSortCur->next;
        }
        if (pflag == 0)
        {
            pSortPre->next = pOri;
            pOri->next = NULL;
        }
        pOri = pTmp;
    }
}

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

void newListDestroy(ugnode *newUgListHead, pgnode *newPgListHead) //销毁两条链表
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