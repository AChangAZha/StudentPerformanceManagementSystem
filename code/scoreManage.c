#define _CRT_SECURE_NO_WARNINGS
#include "scoreManage.h"
#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "inquire.h"
#include "tool.h"
#include "rankCalculate.h"

void scoreSearch() //查询学生成绩
{
    int num, opt = 0;
    ugnode *uPtr;
    pgnode *pPtr;
    while (1)
    {
        system("cls");
        //每个学号对应一个学生，不区分本科生和研究生
        printf("请输入学号（输入0可返回）：");
        enterNum(&num);
        if (num == 0)
        {
            system("cls");
            return;
        }
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
            enterNum(&opt);
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

void inputScore() //输入成绩
{
    int num, fi;
    ugnode *uPtr;
    pgnode *pPtr;

    fi = 0;
    while (1)
    {
        system("cls");
        printf("请输入要录入成绩的学生的学号（输入0结束录入）：");
        enterNum(&num);
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
            printf("\n正在录入第%d位学生的成绩（输入-1可放弃录入该项成绩）\n", fi);

            if (uPtr->data.math == -1)
            {
                printf("请输入该本科生的高数成绩：");
                do
                {
                    enterNum(&uPtr->data.math);
                    if (uPtr->data.math < -1 || uPtr->data.math > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (uPtr->data.math < -1 || uPtr->data.math > 100);
            }
            if (uPtr->data.english == -1)
            {
                printf("请输入该本科生的英语成绩：");
                do
                {
                    enterNum(&uPtr->data.english);
                    if (uPtr->data.english < -1 || uPtr->data.english > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (uPtr->data.english < -1 || uPtr->data.english > 100);
            }
            if (uPtr->data.cLanguguage == -1)
            {
                printf("请输入该本科生的C语言成绩：");
                do
                {
                    enterNum(&uPtr->data.cLanguguage);
                    if (uPtr->data.cLanguguage < -1 || uPtr->data.cLanguguage > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (uPtr->data.cLanguguage < -1 || uPtr->data.cLanguguage > 100);
            }
            calculate(); //计算总成绩、排名
            system("cls");
            printf("第%d位学生成绩录入结束\n", fi);
            outputUgScore(uPtr);
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
                    enterNum(&pPtr->data.compCourse);
                    if (pPtr->data.compCourse < -1 || pPtr->data.compCourse > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (pPtr->data.compCourse < -1 || pPtr->data.compCourse > 100);
            }
            if (pPtr->data.thesis == -1)
            {
                printf("请输入该研究生的论文成绩：");
                do
                {
                    enterNum(&pPtr->data.thesis);
                    if (pPtr->data.thesis < -1 || pPtr->data.thesis > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (pPtr->data.thesis < -1 || pPtr->data.thesis > 100);
            }
            calculate(); //计算总成绩、排名
            system("cls");
            printf("第%d位学生成绩录入结束\n", fi);
            outputPgScore(pPtr);
        }
        else
            printf("\n找不到该学生！\n"); //找不到对应学号的学生
        system("pause");
    }
}

void alterScore() //修改成绩
{
    int uflag = 0, pflag = 0, num, item, opt;
    ugnode *uPtr = NULL;
    pgnode *pPtr = NULL;
    printf("请输入要修改信息的学生的学号（输入0可返回）：");
    enterNum(&num);
    if (num == 0)
    {
        system("cls");
        return;
    }

    if ((uPtr = serchUg(num)) != NULL)
        uflag = 1;
    else if ((pPtr = serchPg(num)) != NULL)
        pflag = 1;
    else
    {
        system("cls");
        printf("没有找到该学生！\n");
        system("pause");
        system("cls");
        return;
    }
    system("cls");

    if (uflag == 1) //若uflag为一，则表示所输入学号是本科生的，否则为研究生的学号
    {
        while (1)
        {
            outputUgScore(uPtr);
            printf("------------------------------------------\n");
            printf("   1.修改高数成绩      2.修改英语成绩       \n");
            printf("   3.修改C语言成绩     4.退出              \n");
            printf("------------------------------------------\n");
            printf("\n请输入菜单编号：");
            do
            {
                enterNum(&item);
                if (item < 1 || item > 4)
                    printf("错误！请输入正确的数字：");
            } while (item < 1 || item > 4);
            printf("\n正在修改成绩（输入-1可删除该科成绩）\n");
            switch (item)
            {
            case 1:
            {
                printf("请输入高数成绩：");
                do
                {
                    enterNum(&uPtr->data.math);
                    if (uPtr->data.math < -1 || uPtr->data.math > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (uPtr->data.math < -1 || uPtr->data.math > 100);
                break;
            }
            case 2:
            {
                printf("请输入英语成绩：");
                do
                {
                    enterNum(&uPtr->data.english);
                    if (uPtr->data.english < -1 || uPtr->data.english > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (uPtr->data.english < -1 || uPtr->data.english > 100);
                break;
            }
            case 3:
            {
                printf("请输入C语言成绩：\n");
                do
                {
                    enterNum(&uPtr->data.cLanguguage);
                    if (uPtr->data.cLanguguage < -1 || uPtr->data.cLanguguage > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (uPtr->data.cLanguguage < -1 || uPtr->data.cLanguguage > 100);
                break;
            }
            case 4:
            {
                system("cls");
                return;
            }
            }
            system("cls");
            calculate(); //计算总成绩、排名
            outputUgScore(uPtr);
            printf("\n修改成功！请选择下一操作（1.继续修改 2.退出）：");
            do
            {
                enterNum(&opt);
                if (opt != 1 && opt != 2)
                    printf("错误！请输入正确的数字：");
            } while (opt != 1 && opt != 2);
            if (opt == 2)
            {
                system("cls");
                return;
            }
            system("cls");
        }
    }
    else
    {
        while (1)
        {
            outputPgScore(pPtr);
            printf("---------------------------------------------------\n");
            printf("   1---修改课程综合成绩      2----修改论文成绩       \n");
            printf("                     3---退出                      \n");
            printf("---------------------------------------------------\n");
            printf("\n请输入菜单编号：");
            do
            {
                enterNum(&item);
                if (item > 3 || item < 1)
                    printf("菜单编号输入错误，请重新输入：");
            } while (item > 3 || item < 1);
            printf("\n正在修改成绩（输入-1可删除该科成绩）\n");
            switch (item)
            {
            case 1:
            {
                printf("请输入课程综合成绩：");
                do
                {
                    enterNum(&pPtr->data.compCourse);
                    if (pPtr->data.compCourse < -1 || pPtr->data.compCourse > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (pPtr->data.compCourse < -1 || pPtr->data.compCourse > 100);
                break;
            }
            case 2:
            {
                printf("请输入论文成绩：");
                do
                {
                    enterNum(&pPtr->data.thesis);
                    if (pPtr->data.thesis < -1 || pPtr->data.thesis > 100)
                        printf("成绩取值范围为0-100，请重新输入：");
                } while (pPtr->data.thesis < -1 || pPtr->data.thesis > 100);
                break;
            }
            case 3:
            {
                system("cls");
                return;
            }
            }
            system("cls");
            calculate(); //计算总成绩、排名
            outputPgScore(pPtr);
            printf("修改成功！请选择下一操作（1.继续修改 2.退出）：");
            do
            {
                enterNum(&opt);
                if (opt != 1 && opt != 2)
                    printf("错误！请输入正确的数字：");
            } while (opt != 1 && opt != 2);
            if (opt == 2)
            {
                system("cls");
                return;
            }
            system("cls");
        }
    }
}

void deleteScore() //删除成绩
{
    int n, fi;
    ugnode *p;
    pgnode *q;

    while (1)
    {
        system("cls");
        printf("请输入要删除成绩的学生的学号（输入0可返回）：");
        enterNum(&n);
        if (n == 0)
        {
            system("cls");
            return;
        }

        if ((p = serchUg(n)) != NULL)
        {
            outputUgScore(p);
            if (p->data.math == -1 && p->data.english == -1 && p->data.cLanguguage == -1)
                printf("\n该学生暂无成绩！\n");
            else
            {
                p->data.math = -1;
                p->data.english = -1;
                p->data.cLanguguage = -1;
                printf("\n删除成功！\n");
                calculate(); //计算总成绩、排名
            }
            printf("请选择下一操作（1.继续删除其他学生成绩 2.退出 ）：");
            do
            {
                enterNum(&fi);
                if (fi != 1 && fi != 2)
                    printf("错误！请输入正确的数字：");
            } while (fi != 1 && fi != 2);
        }
        else if ((q = serchPg(n)) != NULL)
        {
            outputPgScore(q);
            if (q->data.compCourse == -1 && q->data.thesis == -1)
                printf("\n该学生暂无成绩！\n");
            else
            {
                q->data.compCourse = -1;
                q->data.thesis = -1;
                printf("\n删除成功！\n");
                calculate(); //计算总成绩、排名
            }
            printf("请选择下一操作（1.继续删除其他学生成绩 2.退出 ）：");
            do
            {
                enterNum(&fi);
                if (fi != 1 && fi != 2)
                    printf("错误！请输入正确的数字：");
            } while (fi != 1 && fi != 2);
        }
        else
        {
            printf("\n找不到该学生！\n");
            printf("请选择下一操作（1.继续删除其他学生成绩 2.退出 ）：");
            do
            {
                enterNum(&fi);
                if (fi != 1 && fi != 2)
                    printf("错误！请输入正确的数字：");
            } while (fi != 1 && fi != 2);
        }
        if (fi == 2)
        {
            system("cls");
            break;
        }
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
        else
            uPtr->data.totalScore = -1;
        uPtr = uPtr->next;
    }
    while (pPtr != NULL) //计算研究生总成绩
    {
        if (pPtr->data.compCourse != -1 && pPtr->data.thesis != -1)
            pPtr->data.totalScore = pPtr->data.compCourse + pPtr->data.thesis;
        else
            pPtr->data.totalScore = -1;
        pPtr = pPtr->next;
    }
    classRankCalculate();
    schoolRankCalculate();
}