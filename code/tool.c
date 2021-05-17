#define _CRT_SECURE_NO_WARNINGS
#include "tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"

void enterNum(int *num) //从键盘输入数字
{
    while (scanf("%d", num) != 1) //保证输入的是数字
    {
        printf("错误！请输入正确的数字：");
        while (getchar() != '\n')
            ;
    }
    while (getchar() != '\n')
        ;
}

void enterStr(char *str, int num) //输入字符串
{
    int i;
    char tmp[200];
    while (1)
    {
        i = 0;
        while ((tmp[i] = getchar()) != '\n')
        {
            if (i >= num - 1)
                break;
            i++;
        }
        if (tmp[i] != '\n')
        {
            while (getchar() != '\n')
                ;
            printf("字数超过限制，请重新输入：");
        }
        else if (tmp[0] != '\n' && tmp[i] == '\n')
            break;
    }
    tmp[i] = '\0';
    strcpy(str, tmp);
}

void outputUgInfor(ugnode *uPtr)
{
    printf("%-10s%-8s%-12s%-6s%-20s%-20s\n", "培养层次", "学号", "姓名", "性别", "专业", "班级");
    printf("%-10s%-8d%-12s", "本科", uPtr->data.num, uPtr->data.name);
    if (uPtr->data.sex == male)
        printf("%-6s", "男");
    else
        printf("%-6s", "女");
    printf("%-20s%-20s\n", uPtr->data.speciaty, uPtr->data.classes);
}

void outputPgInfor(pgnode *pPtr)
{
    printf("%-10s%-8s%-12s%-6s%-20s%-20s%-20s%-12s\n", "培养层次", "学号", "姓名", "性别", "专业", "班级", "研究方向", "导师");
    printf("%-10s%-8d%-12s", "研究生", pPtr->data.num, pPtr->data.name);
    if (pPtr->data.sex == male)
        printf("%-6s", "男");
    else
        printf("%-6s", "女");
    printf("%-20s%-20s%-20s%-12s\n", pPtr->data.speciaty, pPtr->data.classes, pPtr->data.rschFields, pPtr->data.advisor);
}

void outputUgScore(ugnode *uPtr)
{
    printf("%-9s%-8s%-12s%-20s%-20s%-5s%-5s%-6s%-7s%-9s%-9s\n", "培养层次", "学号", "姓名", "专业", "班级", "高数", "英语", "C语言", "总成绩", "班级排名", "校级排名");
    printf("%-9s%-8d%-12s%-20s%-20s", "本科", uPtr->data.num, uPtr->data.name, uPtr->data.speciaty, uPtr->data.classes);
    if (uPtr->data.math != -1)
        printf("%-5d", uPtr->data.math);
    else
        printf("%-5s", "—");
    if (uPtr->data.english != -1)
        printf("%-5d", uPtr->data.english);
    else
        printf("%-5s", "—");
    if (uPtr->data.cLanguguage != -1)
        printf("%-6d", uPtr->data.cLanguguage);
    else
        printf("%-6s", "—");
    if (uPtr->data.totalScore != -1)
        printf("%-7d", uPtr->data.totalScore);
    else
        printf("%-7s", "—");
    if (uPtr->data.classRank != -1)
        printf("%-9d", uPtr->data.classRank);
    else
        printf("%-9s", "—");
    if (uPtr->data.schoolRank != -1)
        printf("%-9d\n", uPtr->data.schoolRank);
    else
        printf("%-9s\n", "—");
    printf("\n注：“—”表示暂无数据\n");
}

void outputPgScore(pgnode *pPtr)
{
    printf("%-9s%-8s%-12s%-20s%-20s%-9s%-5s%-7s%-9s%-9s\n", "培养层次", "学号", "姓名", "专业", "班级", "课程综合", "论文", "总成绩", "班级排名", "校级排名");
    printf("%-9s%-8d%-12s%-20s%-20s", "研究生", pPtr->data.num, pPtr->data.name, pPtr->data.speciaty, pPtr->data.classes);
    if (pPtr->data.compCourse != -1)
        printf("%-9d", pPtr->data.compCourse);
    else
        printf("%-9s", "—");
    if (pPtr->data.thesis != -1)
        printf("%-5d", pPtr->data.thesis);
    else
        printf("%-5s", "—");
    if (pPtr->data.totalScore != -1)
        printf("%-7d", pPtr->data.totalScore);
    else
        printf("%-7s", "—");
    if (pPtr->data.classRank != -1)
        printf("%-9d", pPtr->data.classRank);
    else
        printf("%-9s", "—");
    if (pPtr->data.schoolRank != -1)
        printf("%-9d\n", pPtr->data.schoolRank);
    else
        printf("%-9s\n", "—");
    printf("\n注：“—”表示暂无数据\n");
}

void printUList(ugnode *head, ugnode *end) //输出本科班级链表信息
{
    ugnode *p = head;
    printf("%-9s%-8s%-12s%-6s%-20s%-20s%-5s%-5s%-6s%-7s%-9s%-9s\n", "培养层次", "学号", "姓名", "性别", "专业", "班级", "高数", "英语", "C语言", "总成绩", "班级排名", "校级排名");
    while (p != end)
    {
        printf("%-9s%-8d%-12s", "本科", p->data.num, p->data.name);
        if (p->data.sex == male)
            printf("%-6s", "男");
        else
            printf("%-6s", "女");
        printf("%-20s%-20s", p->data.speciaty, p->data.classes);
        if (p->data.math != -1)
            printf("%-5d", p->data.math);
        else
            printf("%-5s", "—");
        if (p->data.english != -1)
            printf("%-5d", p->data.english);
        else
            printf("%-5s", "—");
        if (p->data.cLanguguage != -1)
            printf("%-6d", p->data.cLanguguage);
        else
            printf("%-6s", "—");
        if (p->data.totalScore != -1)
            printf("%-7d", p->data.totalScore);
        else
            printf("%-7s", "—");
        if (p->data.classRank != -1)
            printf("%-9d", p->data.classRank);
        else
            printf("%-9s", "—");
        if (p->data.schoolRank != -1)
            printf("%-9d\n", p->data.schoolRank);
        else
            printf("%-9s\n", "—");
        p = p->next;
    }
}

void printPList(pgnode *head, pgnode *end) //输出研究生班级链表信息
{
    pgnode *q = head;
    printf("%-9s%-8s%-12s%-6s%-20s%-20s%-20s%-12s%-9s%-5s%-7s%-9s%-9s\n", "培养层次", "学号", "姓名", "性别", "专业", "班级", "研究方向", "导师", "课程综合", "论文", "总成绩", "班级排名", "校级排名");
    while (q != end)
    {
        printf("%-9s%-8d%-12s", "研究生", q->data.num, q->data.name);
        if (q->data.sex == male)
            printf("%-6s", "男");
        else
            printf("%-6s", "女");
        printf("%-20s%-20s%-20s%-12s", q->data.speciaty, q->data.classes, q->data.rschFields, q->data.advisor);
        if (q->data.compCourse != -1)
            printf("%-9d", q->data.compCourse);
        else
            printf("%-9s", "—");
        if (q->data.thesis != -1)
            printf("%-5d", q->data.thesis);
        else
            printf("%-5s", "—");
        if (q->data.totalScore != -1)
            printf("%-7d", q->data.totalScore);
        else
            printf("%-7s", "—");
        if (q->data.classRank != -1)
            printf("%-9d", q->data.classRank);
        else
            printf("%-9s", "—");
        if (q->data.schoolRank != -1)
            printf("%-9d\n", q->data.schoolRank);
        else
            printf("%-9s\n", "—");
        q = q->next;
    }
}

void printUHead()
{
    printf("%-9s%-8s%-12s%-6s%-20s%-20s%-5s%-5s%-6s%-7s%-9s%-9s\n", "培养层次", "学号", "姓名", "性别", "专业", "班级", "高数", "英语", "C语言", "总成绩", "班级排名", "校级排名");
}

void printPHead()
{
    printf("%-9s%-8s%-12s%-6s%-20s%-20s%-20s%-12s%-9s%-5s%-7s%-9s%-9s\n", "培养层次", "学号", "姓名", "性别", "专业", "班级", "研究方向", "导师", "课程综合", "论文", "总成绩", "班级排名", "校级排名");
}

void printOneUg(ugnode *p)
{
    if (p != NULL)
    {
        printf("%-9s%-8d%-12s", "本科", p->data.num, p->data.name);
        if (p->data.sex == male)
            printf("%-6s", "男");
        else
            printf("%-6s", "女");
        printf("%-20s%-20s", p->data.speciaty, p->data.classes);
        if (p->data.math != -1)
            printf("%-5d", p->data.math);
        else
            printf("%-5s", "—");
        if (p->data.english != -1)
            printf("%-5d", p->data.english);
        else
            printf("%-5s", "—");
        if (p->data.cLanguguage != -1)
            printf("%-6d", p->data.cLanguguage);
        else
            printf("%-6s", "—");
        if (p->data.totalScore != -1)
            printf("%-7d", p->data.totalScore);
        else
            printf("%-7s", "—");
        if (p->data.classRank != -1)
            printf("%-9d", p->data.classRank);
        else
            printf("%-9s", "—");
        if (p->data.schoolRank != -1)
            printf("%-9d\n", p->data.schoolRank);
        else
            printf("%-9s\n", "—");
    }
}

void printOnePg(pgnode *q)
{
    if (q != NULL)
    {

        printf("%-9s%-8d%-12s", "研究生", q->data.num, q->data.name);
        if (q->data.sex == male)
            printf("%-6s", "男");
        else
            printf("%-6s", "女");
        printf("%-20s%-20s%-20s%-12s", q->data.speciaty, q->data.classes, q->data.rschFields, q->data.advisor);
        if (q->data.compCourse != -1)
            printf("%-9d", q->data.compCourse);
        else
            printf("%-9s", "—");
        if (q->data.thesis != -1)
            printf("%-5d", q->data.thesis);
        else
            printf("%-5s", "—");
        if (q->data.totalScore != -1)
            printf("%-7d", q->data.totalScore);
        else
            printf("%-7s", "—");
        if (q->data.classRank != -1)
            printf("%-9d", q->data.classRank);
        else
            printf("%-9s", "—");
        if (q->data.schoolRank != -1)
            printf("%-9d\n", q->data.schoolRank);
        else
            printf("%-9s\n", "—");
    }
}

ugnode *copyUGList()
{
    ugnode *copy, *p, *node, *q;
    copy = (ugnode *)malloc(sizeof(ugnode));
    copy->next = NULL;
    q = copy;
    p = ugHead->next;

    while (p != NULL)
    {
        node = (ugnode *)malloc(sizeof(ugnode));
        node->data = p->data;
        node->next = NULL;
        q->next = node;
        p = p->next;
        q = node;
    }
    return copy;
}

pgnode *copyPGList()
{
    pgnode *copy, *p, *node, *q;
    copy = (pgnode *)malloc(sizeof(pgnode));
    copy->next = NULL;
    q = copy;
    p = pgHead->next;

    while (p != NULL)
    {
        node = (pgnode *)malloc(sizeof(pgnode));
        node->data = p->data;
        node->next = NULL;
        q->next = node;
        p = p->next;
        q = node;
    }
    return copy;
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

void outputAllClasses()
{
    char cla[20];
    ugnode *newUgHead, *p, *uTmp;
    pgnode *newPgHead, *q, *pTmp;
    newUgHead = copyUGList();
    newPgHead = copyPGList();
    printf("本科班级:\n\n");
    if (newUgHead->next == NULL)
        printf("暂无数据\n");
    while (newUgHead->next != NULL)
    {

        p = newUgHead;
        strcpy(cla, p->next->data.classes);
        while (p->next != NULL)
        {
            uTmp = p->next;
            if ((strcmp(uTmp->data.classes, cla)) == 0)
            {
                p->next = uTmp->next;
                free(uTmp);
            }
            else
                p = p->next;
        }
        printf("%s\n", cla);
    }
    free(newUgHead);
    printf("\n研究生班级:\n\n");
    if (newPgHead->next == NULL)
        printf("暂无数据\n");
    while (newPgHead->next != NULL)
    {
        q = newPgHead;
        strcpy(cla, q->next->data.classes);
        while (q->next != NULL)
        {
            pTmp = q->next;
            if ((strcmp(pTmp->data.classes, cla)) == 0)
            {
                q->next = pTmp->next;
                free(pTmp);
            }
            else
                q = q->next;
        }
        printf("%s\n", cla);
    }
    free(newPgHead);
}

void about()
{
    printf("----------------------------------------------------\n");
    printf("                  学生成绩管理系统                 \n");
    printf("                  version 1.5.0 Beta                  \n");
    printf("                       2021/5                     \n");
    printf("                    东莞理工学院                   \n");
    printf("                  网络空间安全学院                 \n");
    printf("                   2020软件卓越2班                 \n");
    printf("                   指导教师：肖捷                  \n");
    printf("         作者邮箱：202041404130@dgut.edu.cn        \n");
    printf("   代码库：https://github.com/AChangAZha/Student   \n");
    printf("           Copyright (C) 2021 张瀚 陈蕴鋆          \n");
    printf("----------------------------------------------------\n");
    system("pause");
    system("cls");
}