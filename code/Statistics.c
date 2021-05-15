#include "model.h"
#include "Statistics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"

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

void countugAvg()
{
    int sum, count, item;
    double avg;
    ugnode *p, *newUgHead, *tmp;
    char cla[20];
    while (1)
    {
        system("cls");
        printf("---------------------------------------------------------\n");
        printf("    1.查看高数成绩统计结果     2.查看英语成绩统计结果        \n");
        printf("    3.查看C语言成绩统计结果    4.退出                      \n");
        printf("---------------------------------------------------------\n");
        printf("请输入菜单编号：");
        do
        {
            enterNum(&item);
            if (item < 1 || item > 4)
                printf("菜单编号输入错误，请重新输入：");
        } while (item < 1 || item > 4);

        system("cls");
        newUgHead = copyUGList();
        if (item == 1)
        {
            printf("各班高数平均成绩：\n\n");
            if (newUgHead->next == NULL)
                printf("暂无数据\n");
            while (newUgHead->next != NULL)
            {
                sum = 0;
                count = 0;
                p = newUgHead;
                strcpy(cla, p->next->data.classes);
                while (p->next != NULL)
                {
                    tmp = p->next;
                    if ((strcmp(tmp->data.classes, cla)) == 0)
                    {
                        if (tmp->data.math != -1)
                        {
                            sum += tmp->data.math;
                            count++;
                        }
                        p->next = tmp->next;
                        free(tmp);
                    }
                    else
                        p = p->next;
                }
                if (count != 0)
                {
                    avg = sum * 1.0 / count;
                    printf("%s：%.2lf\n", cla, avg);
                }
                else
                    printf("%s：暂无数据\n", cla, avg);
            }
            free(newUgHead);
        }
        else if (item == 2)
        {
            printf("各班英语平均成绩：\n\n");
            if (newUgHead->next == NULL)
                printf("暂无数据\n");
            while (newUgHead->next != NULL)
            {
                sum = 0;
                count = 0;
                p = newUgHead;
                strcpy(cla, p->next->data.classes);
                while (p->next != NULL)
                {
                    tmp = p->next;
                    if ((strcmp(tmp->data.classes, cla)) == 0)
                    {
                        if (tmp->data.english != -1)
                        {
                            sum += tmp->data.english;
                            count++;
                        }
                        p->next = tmp->next;
                        free(tmp);
                    }
                    else
                        p = p->next;
                }
                if (count != 0)
                {
                    avg = sum * 1.0 / count;
                    printf("%s：%.2lf\n", cla, avg);
                }
                else
                    printf("%s：暂无数据\n", cla, avg);
            }
            free(newUgHead);
        }
        else if (item == 3)
        {
            printf("各班C语言平均成绩：\n\n");
            if (newUgHead->next == NULL)
                printf("暂无数据\n");
            while (newUgHead->next != NULL)
            {
                sum = 0;
                count = 0;
                p = newUgHead;
                strcpy(cla, p->next->data.classes);
                while (p->next != NULL)
                {
                    tmp = p->next;
                    if ((strcmp(tmp->data.classes, cla)) == 0)
                    {
                        if (tmp->data.cLanguguage != -1)
                        {
                            sum += tmp->data.cLanguguage;
                            count++;
                        }
                        p->next = tmp->next;
                        free(tmp);
                    }
                    else
                        p = p->next;
                }
                if (count != 0)
                {
                    avg = sum * 1.0 / count;
                    printf("%s：%.2lf\n", cla, avg);
                }
                else
                    printf("%s：暂无数据\n", cla, avg);
            }
            free(newUgHead);
        }
        else
        {
            system("cls");
            break;
        }
        printf("\n");
        system("pause");
    }
}

void countpgAvg()
{
    int sum, count, item;
    double avg;
    pgnode *p, *newPgHead, *tmp;
    char cla[20];

    while (1)
    {
        system("cls");
        printf("-------------------------------------------------------------\n");
        printf("   1.查看课程综合成绩统计结果       2.查看论文成绩统计结果      \n");
        printf("                             3.退出                           \n");
        printf("-------------------------------------------------------------\n");
        printf("请输入菜单编号：");
        do
        {
            enterNum(&item);
            if (item < 1 || item > 3)
                printf("菜单编号输入错误，请重新输入：");
        } while (item < 1 || item > 3);

        system("cls");
        newPgHead = copyPGList();
        if (item == 1)
        {
            printf("各班课程综合平均成绩：\n\n");
            if (newPgHead->next == NULL)
                printf("暂无数据\n");
            while (newPgHead->next != NULL)
            {
                sum = 0;
                count = 0;
                p = newPgHead;
                strcpy(cla, p->next->data.classes);
                while (p->next != NULL)
                {
                    tmp = p->next;
                    if ((strcmp(tmp->data.classes, cla)) == 0)
                    {
                        if (tmp->data.compCourse != -1)
                        {
                            sum += tmp->data.compCourse;
                            count++;
                        }
                        p->next = tmp->next;
                        free(tmp);
                    }
                    else
                        p = p->next;
                }
                if (count != 0)
                {
                    avg = sum * 1.0 / count;
                    printf("%s：%.2lf\n", cla, avg);
                }
                else
                    printf("%s：暂无数据\n", cla, avg);
            }
            free(newPgHead);
        }
        else if (item == 2)
        {
            printf("各班论文平均成绩：\n\n");
            if (newPgHead->next == NULL)
                printf("暂无数据\n");
            while (newPgHead->next != NULL)
            {
                sum = 0;
                count = 0;
                p = newPgHead;
                strcpy(cla, p->next->data.classes);
                while (p->next != NULL)
                {
                    tmp = p->next;
                    if ((strcmp(tmp->data.classes, cla)) == 0)
                    {
                        if (tmp->data.thesis != -1)
                        {
                            sum += tmp->data.thesis;
                            count++;
                        }
                        p->next = tmp->next;
                        free(tmp);
                    }
                    else
                        p = p->next;
                }
                if (count != 0)
                {
                    avg = sum * 1.0 / count;
                    printf("%s：%.2lf\n", cla, avg);
                }
                else
                    printf("%s：暂无数据\n", cla, avg);
            }
            free(newPgHead);
        }
        else
        {
            system("cls");
            break;
        }
        printf("\n");
        system("pause");
    }
}

int choseClassCourse()
{
    char cla[20], course[20];
    int mathGrade[5] = {0}, enGrade[5] = {0}, cGrade[5] = {0}, compGrade[5] = {0}, thGrade[5] = {0};
    int tmp[5], item, i, uflag = 0, pflag = 0;
    ugnode *uPtr = ugHead->next;
    pgnode *pPtr = pgHead->next;

    system("cls");
    outputAllClasses();
    printf("\n请输入需要查看等级统计结果的班级（输入0可退出）：");
    enterStr(cla, sizeof(cla));
    if (strcmp(cla, "0") == 0)
    {
        system("cls");
        return 0;
    }
    while (uPtr != NULL)
    {
        if ((strcmp(uPtr->data.classes, cla)) == 0)
        {
            uflag = 1;
            staGrade(mathGrade, uPtr->data.math);
            staGrade(enGrade, uPtr->data.english);
            staGrade(cGrade, uPtr->data.cLanguguage);
        }
        uPtr = uPtr->next;
    }
    if (uflag == 0)
    {
        while (pPtr != NULL)
        {
            if ((strcmp(pPtr->data.classes, cla)) == 0)
            {
                pflag = 1;
                staGrade(compGrade, pPtr->data.compCourse);
                staGrade(thGrade, pPtr->data.thesis);
            }
            pPtr = pPtr->next;
        }
    }
    if (uflag == 1)
    {
        while (1)
        {
            system("cls");
            printf("--------------------------------------------------------------\n");
            printf("   %s成绩等级统计结果                                          \n", cla);
            printf("   1.查看高数成绩等级统计结果                                   \n");
            printf("   2.查看英语成绩等级统计结果                                    \n");
            printf("   3.查看C语言成绩等级统计结果                                   \n");
            printf("   4.退出                                                      \n");
            printf("--------------------------------------------------------------\n");
            printf("请输入菜单编号：");
            do
            {
                enterNum(&item);
                if (item < 1 || item > 4)
                    printf("菜单编号输入错误，请重新输入：");
            } while (item < 1 || item > 4);
            system("cls");
            if (item == 4)
                break;
            if (item == 1)
            {
                strcpy(course, "高数");
                for (i = 0; i < 5; i++)
                {
                    tmp[i] = mathGrade[i];
                }
            }
            else if (item == 2)
            {
                strcpy(course, "英语");
                for (i = 0; i < 5; i++)
                {
                    tmp[i] = enGrade[i];
                }
            }
            else if (item == 3)
            {
                strcpy(course, "C语言");
                for (i = 0; i < 5; i++)
                {
                    tmp[i] = cGrade[i];
                }
            }
            printf("%s%s成绩统计结果:\n", cla, course);
            printf("等级为优的人数为：%d\n", tmp[0]);
            printf("等级为良的人数为：%d\n", tmp[1]);
            printf("等级为中的人数为：%d\n", tmp[2]);
            printf("等级为及格的人数为：%d\n", tmp[3]);
            printf("等级为不及格的人数为：%d\n", tmp[4]);
            system("pause");
        }
    }
    else if (pflag == 1) //输入班级为研究生班级
    {

        while (1)
        {
            system("cls");
            printf("------------------------------------------------------------------\n");
            printf("   %s成绩等级统计结果                                              \n", cla);
            printf("   1.查看课程综合成绩等级统计结果                                   \n");
            printf("   2.查看论文成绩等级统计结果                                      \n");
            printf("   3.退出                                                         \n");
            printf("------------------------------------------------------------------\n");
            printf("请输入菜单编号：");
            do
            {
                enterNum(&item);
                if (item < 1 || item > 3)
                    printf("菜单编号输入错误，请重新输入：");
            } while (item < 1 || item > 3);
            system("cls");
            if (item == 3)
                break;
            if (item == 1)
            {
                strcpy(course, "课程综合");
                for (i = 0; i < 5; i++)
                {
                    tmp[i] = compGrade[i];
                }
            }
            else if (item == 2)
            {
                strcpy(course, "论文");
                for (i = 0; i < 5; i++)
                {
                    tmp[i] = thGrade[i];
                }
            }
            printf("%s%s成绩统计结果:\n", cla, course);
            printf("等级为优的人数为：%d\n", tmp[0]);
            printf("等级为良的人数为：%d\n", tmp[1]);
            printf("等级为中的人数为：%d\n", tmp[2]);
            printf("等级为及格的人数为：%d\n", tmp[3]);
            printf("等级为不及格的人数为：%d\n", tmp[4]);
            system("pause");
        }
    }
    else
    {
        printf("该班级不存在！\n");
        system("pause");
    }
    return 1;
}

void staGrade(int grade[], int score)
{

    if (score != -1)
    {
        if (score >= 90)
            grade[0]++;
        else if (score >= 80)
            grade[1]++;
        else if (score >= 70)
            grade[2]++;
        else if (score >= 60)
            grade[3]++;
        else
            grade[4]++;
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