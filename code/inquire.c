#define _CRT_SECURE_NO_WARNINGS
#include "model.h"
#include "inquire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    ugnode **page = NULL;
    ugnode *uPtr = ugHead->next;
    if (uPtr == NULL)
    {
        printf("暂无数据！");
        system("pause");
        system("cls");
        return;
    }
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
        if (cur != end)
            printUList(page[cur], page[cur + 1]);
        else
            printUList(page[cur], NULL);
        printf("\n当前第%d页，共%d页\n", cur + 1, end + 1);
        printf("\n请选择：1.上一页 2.下一页 3.首页 4.最后一页 5.退出：");
        do
        {
            enterNum(&opt);
            if (opt < 1 || opt > 5)
                printf("错误！请输入正确的数字：");
        } while (opt < 1 || opt > 5);
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
        {
            system("cls");
            break;
        }
    }
    free(page);
}

void showAllPg()
{
    int count = 0, cur = 0, end = 0, opt = 0;
    pgnode **page = NULL;
    pgnode *pPtr = pgHead->next;
    if (pPtr == NULL)
    {
        printf("暂无数据！");
        system("pause");
        system("cls");
        return;
    }
    while (pPtr != NULL)
    {
        count++;
        if (count > 10)
        {
            cur++;
            count = 1;
        }
        if (count == 1)
        {
            page = (pgnode **)realloc(page, (cur + 1) * sizeof(pgnode *));
            page[cur] = pPtr;
        }
        pPtr = pPtr->next;
    }
    end = cur;
    cur = 0;
    while (1)
    {
        system("cls");
        if (cur != end)
            printPList(page[cur], page[cur + 1]);
        else
            printPList(page[cur], NULL);
        printf("\n当前第%d页，共%d页\n", cur + 1, end + 1);
        printf("\n请选择：1.上一页 2.下一页 3.首页 4.最后一页 5.退出：");
        do
        {
            enterNum(&opt);
            if (opt < 1 || opt > 5)
                printf("错误！请输入正确的数字：");
        } while (opt < 1 || opt > 5);
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
        {
            system("cls");
            break;
        }
    }
    free(page);
}

void stuClaInfor()
{
    char cla[20];
    ugnode *p = ugHead;
    pgnode *q = pgHead;
    int ff, uflag = 0, pflag = 0;

    while (1)
    {
        uflag = 0;
        pflag = 0;
        system("cls");
        outputAllClasses();
        printf("\n请输入需要查看学生信息的班级（输入0可返回）：");
        enterStr(cla, sizeof(cla));
        system("cls");
        if (strcmp(cla, "0") == 0)
            return;

        while (p != NULL)
        {
            if ((strcmp(p->data.classes, cla)) == 0)
            {
                if (uflag == 0)
                    printUHead();
                uflag = 1;
                printOneUg(p);
            }
            p = p->next;
        }
        while (uflag == 0 && q != NULL)
        {
            if ((strcmp(q->data.classes, cla)) == 0)
            {
                if (pflag == 0)
                    printPHead();
                pflag = 1;
                printOnePg(q);
            }
            q = q->next;
        }
        if (uflag == 0 && pflag == 0)
            printf("该班级不存在！\n");
        printf("\n请选择下一操作（1.继续查看班级学生信息 2.退出）：");
        do
        {
            enterNum(&ff);
            if (ff < 1 || ff > 2)
                printf("错误！请输入正确的数字：");
        } while (ff < 1 || ff > 2);
        if (ff == 2)
        {
            system("cls");
            break;
        }
    }
}

void findInfor()
{
    ugnode *p;
    pgnode *q;
    int ff, item, uCount, pCount;
    char nameTemp[20];
    int numTemp;

    while (1)
    {
        system("cls");
        printf("-----------------------------------------------------\n");
        printf("   1.按学号查找学生信息       2.按姓名查找学生信息      \n");
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
        if (item == 3)
            return;
        if (item == 1)
        {
            printf("请输入要查询的学生学号:");
            enterNum(&numTemp);
            if ((p = serchUg(numTemp)) != NULL)
                printUList(p, p->next);
            else if ((q = serchPg(numTemp)) != NULL)
                printPList(q, q->next);
            else
                printf("该学生不存在！\n");
        }
        else if (item == 2)
        {
            printf("请输入要查询的学生姓名：");
            enterStr(nameTemp, sizeof(nameTemp));
            uCount = serchUgName(nameTemp);
            printf("\n");
            pCount = serchPgName(nameTemp);
            printf("\n");
            if (uCount + pCount == 0)
                printf("该学生不存在！\n");
            else
                printf("共找到%d个结果！\n", uCount + pCount);
        }
        printf("\n请选择下一操作（1.继续查找学生 2.退出）：");
        do
        {
            enterNum(&ff);
            if (ff < 1 || ff > 2)
                printf("错误！请输入正确的数字：");
        } while (ff < 1 || ff > 2);
        if (ff == 2)
        {
            system("cls");
            break;
        }
    }
}

int serchUgName(char nameTemp[])
{
    int flag = 0;
    ugnode *uPtr = ugHead->next;
    while (uPtr != NULL)
    {
        if (strcmp(uPtr->data.name, nameTemp) == 0)
        {
            if (flag == 0)
                printUHead();
            flag++;
            printOneUg(uPtr);
        }
        uPtr = uPtr->next;
    }
    return flag;
}

int serchPgName(char nameTemp[])
{
    int flag = 0;
    pgnode *pPtr = pgHead->next;
    while (pPtr != NULL)
    {
        if (strcmp(pPtr->data.name, nameTemp) == 0)
        {
            if (flag == 0)
                printPHead();
            flag++;
            printOnePg(pPtr);
        }
        pPtr = pPtr->next;
    }
    return flag;
}

void failStu()
{
    char classTemp[20];
    int ff;
    ugnode *p;
    pgnode *q;

    while (1)
    {
        system("cls");
        outputAllClasses();
        printf("\n请输入需要查看学生信息的班级（输入0可返回）：");
        enterStr(classTemp, sizeof(classTemp));
        system("cls");
        if (strcmp(classTemp, "0") == 0)
            return;

        p = setUClassList(classTemp);
        q = setPClassList(classTemp);

        if (p->next != NULL)
        {
            unFailStu(p); //进入该函数选择并输出不及格信息
        }
        else if (q->next != NULL)
        {
            pnFailStu(q);
        }
        else
        {
            printf("该班级不存在!\n");
            system("pause");
        }
        newListDestroy(p, q);
    }
}

void unFailStu(ugnode *p)
{
    ugnode *pp;
    int flag, ff, item;
    char cla[20];
    strcpy(cla, p->next->data.classes);
    while (1)
    {
        system("cls");
        printf("--------------------------------------------\n");
        printf("        %s                                  \n", cla);
        printf("        1.高数               2.英语         \n");
        printf("        3.C语言              4.退出         \n");
        printf("--------------------------------------------\n");
        printf("\n请选择要查看该班级不及格学生信息的课程编号：");
        do
        {
            enterNum(&item);
            if (item < 1 || item > 4)
                printf("错误！请输入正确的数字：");
        } while (item < 1 || item > 4);
        system("cls");
        if (item == 4)
            return;
        pp = p->next;
        flag = 0;
        switch (item)
        {
        case 1:
        {
            while (pp != NULL)
            {
                if (pp->data.math < 60)
                {
                    if (flag == 0)
                        printUHead();
                    flag++;
                    printOneUg(pp);
                }
                pp = pp->next;
            }
            if (flag == 0)
                printf("该班级学生高数课程全部及格！\n");
            break;
        }
        case 2:
        {
            while (pp != NULL)
            {
                if (pp->data.english < 60)
                {
                    if (flag == 0)
                        printUHead();
                    flag++;
                    printOneUg(pp);
                }
                pp = pp->next;
            }
            if (flag == 0)
                printf("该班级学生英语课程全部及格！\n");
            break;
        }
        case 3:
        {
            while (pp != NULL)
            {
                if (pp->data.cLanguguage < 60)
                {
                    if (flag == 0)
                        printUHead();
                    flag++;
                    printOneUg(pp);
                }
                pp = pp->next;
            }
            if (flag == 0)
                printf("该班级学生C语言课程全部及格！\n");
            break;
        }
        }
        printf("\n请选择下一操作（1.继续查看该班级其他科目不及格的学生信息  2.退出）：");
        do
        {
            enterNum(&ff);
            if (ff < 1 || ff > 2)
                printf("错误！请输入正确的数字：");
        } while (ff < 1 || ff > 2);
        if (ff == 2)
        {
            system("cls");
            break;
        }
    }
}

void pnFailStu(pgnode *q)
{
    pgnode *pp;
    int flag, ff, item;
    char cla[20];
    strcpy(cla, q->next->data.classes);
    while (1)
    {
        system("cls");
        printf("--------------------------------------------\n");
        printf("      %s                                    \n", cla);
        printf("      1.课程综合             2.论文         \n");
        printf("                   3.退出                   \n");
        printf("--------------------------------------------\n");
        printf("\n请选择要查看该班级不及格学生信息的课程编号：");
        do
        {
            enterNum(&item);
            if (item < 1 || item > 3)
                printf("错误！请输入正确的数字：");
        } while (item < 1 || item > 3);
        system("cls");
        if (item == 3)
            return;
        pp = q->next;
        flag = 0;
        switch (item)
        {
        case 1:
        {
            while (pp != NULL)
            {
                if (pp->data.compCourse < 60)
                {

                    if (flag == 0)
                        printPHead();
                    flag++;
                    printOnePg(pp);
                }
                pp = pp->next;
            }
            if (flag == 0)
                printf("该班级学生课程综合全部及格！\n");
            break;
        }
        case 2:
        {
            while (pp != NULL)
            {
                if (pp->data.thesis < 60)
                {

                    if (flag == 0)
                        printPHead();
                    flag++;
                    printOnePg(pp);
                }
                pp = pp->next;
            }
            if (flag == 0)
                printf("该班级学生论文全部及格！\n");
            break;
        }
        }
        printf("\n请选择下一操作（1.继续查看该班级其他科目不及格的学生信息  2.退出）：");
        do
        {
            enterNum(&ff);
            if (ff < 1 || ff > 2)
                printf("错误！请输入正确的数字：");
        } while (ff < 1 || ff > 2);
        if (ff == 2)
        {
            system("cls");
            break;
        }
    }
}