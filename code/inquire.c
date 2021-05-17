#define _CRT_SECURE_NO_WARNINGS
#include "model.h"
#include "inquire.h"
#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

ugnode *serchUg(int num) //在本科生链表中搜索
{
    ugnode *uPtr = ugHead->next;
    while (uPtr != NULL)
    {
        if (uPtr->data.num == num)
            return uPtr;
        uPtr = uPtr->next;
    }
    return NULL; //没找到则返回NULL
}

pgnode *serchPg(int num) //在研究生链表中搜索
{
    pgnode *pPtr = pgHead->next;
    while (pPtr != NULL)
    {
        if (pPtr->data.num == num)
            return pPtr;
        pPtr = pPtr->next;
    }
    return NULL;
}

void showAllUg()
{
    int count = 0, cur = 0, end = 0, opt = 0;
    ugnode **page;
    ugnode *uPtr = ugHead->next;
    while (uPtr != NULL)
    {
        count++;
        if (count > 10)
        {
            cur++;
            count = 1;
        }
        if (count == 1)
        {
            page = (ugnode **)realloc(page, (cur + 1) * sizeof(ugnode *));
            page[cur] = uPtr;
        }
        uPtr = uPtr->next;
    }
    end = cur;
    cur = 0;
    while (1)
    {
        system("cls");
        uPtr = page[cur];
        count = 1;
        while (uPtr != NULL && count <= 10)
        {
            count++;
            outputUgInfor(uPtr);
            uPtr = uPtr->next;
        }
        printf("\n当前第%d页，共%d页\n", cur + 1, end + 1);
        printf("\n请选择：1.上一页 2.下一页 3.首页 4.最后一页 5.退出：");
        enterNum(&opt);
        if (opt == 1)
        {
            if (cur != 0)
                cur--;
            else
            {
                printf("当前为第1页！\n");
                system("pause");
            }
        }
        else if (opt == 2)
        {
            if ((cur != end))
                cur++;
            else
            {
                printf("当前为最后一页！\n");
                system("pause");
            }
        }
        else if (opt == 3)
            cur = 0;
        else if (opt == 4)
            cur = end;
        else
            break;
    }
    free(page);
}