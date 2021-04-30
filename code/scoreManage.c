#define _CRT_SECURE_NO_WARNINGS
#include "scoreManage.h"
#include <stdio.h>
#include "model.h"
#include "inquire.h"
#include "tool.h"

void scoreSearch()
{
    int num,opt=0;
    ugnode *uPtr;
    pgnode *pPtr;
    while (1)
    {
        printf("请输入学号：");
        enterNUM(&num);
        if((uPtr=serchUg(num))!=NULL)
        {
            printf("查询成功，以下是该学生的成绩：\n");
            printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "培养层次", "学号", "姓名", "高数", "英语", "C语言", "总成绩", "班级排名", "校级排名");
            printf("%-10s%-10d%-10s%-10d%-10d%-10d%-10d%-10d%-10d\n", "本科", uPtr->data.num, uPtr->data.name, uPtr->data.math, uPtr->data.english, uPtr->data.cLanguguage, uPtr->data.totalScore, uPtr->data.classRank, uPtr->data.schoolRank);
        }
        if((pPtr=serchPg(num))!=NULL)
        {
            printf("查询成功，以下是该学生的成绩：\n");
            printf("%-10s%-10s%-10s%-14s%-10s%-10s%-10s%-10s\n", "培养层次", "学号", "姓名", "课程综合成绩", "论文成绩", "总成绩", "班级排名", "校级排名");
            printf("%-10s%-10d%-10s%-14d%-10d%-10d%-10d%-10d\n", "研究生", pPtr->data.num, pPtr->data.name, pPtr->data.compCourse, pPtr->data.thesis, pPtr->data.totalScore, pPtr->data.classRank, pPtr->data.schoolRank);
        }
        else printf("没有查询到相关信息！\n");
        printf("请选择 1.继续查询 2.返回：");
        do
        {
            enterNUM(&opt);
            if (opt != 1 && opt != 2) printf("错误！请输入正确的数字：");
        } while (opt != 1 && opt != 2);
        printf("\n");
        if(opt==2) return;
        num=0;
        opt=0;
    }
}

void calculate()
{
    ugnode *uPtr=ugHead->next;
    pgnode *pPtr=pgHead->next;
    while (uPtr!=NULL)
    {
        if(uPtr->data.math!=-1 && uPtr->data.english!=-1 && uPtr->data.cLanguguage!=-1)
        uPtr->data.totalScore=uPtr->data.math+uPtr->data.english+uPtr->data.cLanguguage;
        uPtr=uPtr->next;
    }
    while (pPtr!=NULL)
    {
        if(pPtr->data.compCourse!=-1 && pPtr->data.thesis!=-1)
        pPtr->data.totalScore=pPtr->data.compCourse+pPtr->data.thesis;
        pPtr=pPtr->next;
    }
}