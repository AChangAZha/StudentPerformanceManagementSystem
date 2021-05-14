#define _CRT_SECURE_NO_WARNINGS
#include "scoreManage.h"
#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "inquire.h"
#include "tool.h"

void scoreSearch() //查询学生成绩
{
    int num, opt = 0;
    ugnode *uPtr;
    pgnode *pPtr;
    while (1)
    {
        system("cls");
        //每个学号对应一个学生，不区分本科生和研究生
        printf("请输入学号：");
        enterNUM(&num);
        //需要在两个链表中搜寻
        //调用查找函数(在inquire.c中定义)
        if ((uPtr = serchUg(num)) != NULL)
        {
            printf("查询成功，以下是该学生的成绩：\n");
            outputUgScore(uPtr);
        }
        else if ((pPtr = serchPg(num)) != NULL)
        {
            printf("查询成功，以下是该学生的成绩：\n");
            outputPgScore(pPtr);
        }
        else
            printf("没有查询到相关信息！\n");
        printf("\n请选择 1.继续查询 2.返回：");
        do
        {
            enterNUM(&opt);
            if (opt != 1 && opt != 2)
                printf("错误！请输入正确的数字：");
        } while (opt != 1 && opt != 2);
        printf("\n");
        if (opt == 2)
        {
            system("cls");
            return;
        }
        num = 0;
        opt = 0;
    }
}

void inputScore()
{
    int num, fi;
    ugnode *uPtr;
    pgnode *pPtr;

    fi = 0;
    while (1)
    {
        system("cls");
        printf("请输入要录入成绩的学生的学号（输入0结束录入）：");
        enterNUM(&num);
        if (num == 0)
        {
            system("cls");
            return;
        }

        if ((uPtr = serchUg(num)) != NULL) //需录入成绩的学生是本科生
        {
            outputUgScore(uPtr);
            if (uPtr->data.math != -1 && uPtr->data.english != -1 && uPtr->data.cLanguguage != -1)
            {
                printf("\n该学生无须录入成绩！");
                system("pause");
                continue;
            }

            fi++;
            printf("\n正在录入第%d位学生的成绩（输入-1可取消录入）\n", fi);

            if (uPtr->data.math == -1)
            {
                printf("请输入该本科生的高数成绩：");
                do
                {
                    enterNUM(&uPtr->data.math);
                    if (uPtr->data.math < -1 || uPtr->data.math > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (uPtr->data.math < -1 || uPtr->data.math > 100);
            }
            if (uPtr->data.english == -1)
            {
                printf("请输入该本科生的英语成绩：");
                do
                {
                    enterNUM(&uPtr->data.english);
                    if (uPtr->data.english < -1 || uPtr->data.english > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (uPtr->data.english < -1 || uPtr->data.english > 100);
            }
            if (uPtr->data.cLanguguage == -1)
            {
                printf("请输入该本科生的C语言成绩：");
                do
                {
                    enterNUM(&uPtr->data.cLanguguage);
                    if (uPtr->data.cLanguguage < -1 || uPtr->data.cLanguguage > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (uPtr->data.cLanguguage < -1 || uPtr->data.cLanguguage > 100);
            }

            printf("\n第%d位学生成绩录入结束\n", fi);
        }

        else if ((pPtr = serchPg(num)) != NULL) //输入的学生学号对应的是研究生
        {
            outputPgScore(pPtr);
            if (pPtr->data.compCourse != -1 && pPtr->data.thesis != -1)
            {
                printf("该学生无须录入成绩！");
                system("pause");
                continue;
            }
            fi++;

            printf("\n正在录入第%d位学生的成绩\n", fi);

            if (pPtr->data.compCourse == -1)
            {
                printf("请输入该研究生的课程综合成绩：");
                do
                {
                    enterNUM(&pPtr->data.compCourse);
                    if (pPtr->data.compCourse < -1 || pPtr->data.compCourse > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (pPtr->data.compCourse < -1 || pPtr->data.compCourse > 100);
            }
            if (pPtr->data.thesis == -1)
            {
                printf("请输入该研究生的论文成绩：");
                do
                {
                    enterNUM(&pPtr->data.thesis);
                    if (pPtr->data.thesis < -1 || pPtr->data.thesis > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (pPtr->data.thesis < -1 || pPtr->data.thesis > 100);
            }
            printf("\n第%d位学生成绩录入结束\n", fi);
        }
        else
            printf("\n找不到该学生！\n"); //找不到对应学号的学生
        system("pause");
    }
}

void calculate() //计算总成绩、排名
{
    ugnode *uPtr = ugHead->next;
    pgnode *pPtr = pgHead->next;
    while (uPtr != NULL) //计算本科生总成绩
    {
        //只有所有成绩均为有效成绩才可以计算
        if (uPtr->data.math != -1 && uPtr->data.english != -1 && uPtr->data.cLanguguage != -1)
            uPtr->data.totalScore = uPtr->data.math + uPtr->data.english + uPtr->data.cLanguguage;
        uPtr = uPtr->next;
    }
    while (pPtr != NULL) //计算研究生总成绩
    {
        if (pPtr->data.compCourse != -1 && pPtr->data.thesis != -1)
            pPtr->data.totalScore = pPtr->data.compCourse + pPtr->data.thesis;
        pPtr = pPtr->next;
    }
}