#include "model.h"
#include "Statistics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"
#include "sort.h"

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
            while (newUgHead->next != NULL)
            {
                sum = 0;
                count = 0;
                tmp = setUGClassList(newUgHead);
                p = tmp->next;
                free(tmp);
                strcpy(cla, p->data.classes);
                while (p != NULL)
                {
                    if (p->data.math != -1)
                    {
                        sum += p->data.math;
                        count++;
                    }
                    tmp = p;
                    p = p->next;
                    free(tmp);
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
            while (newUgHead->next != NULL)
            {
                sum = 0;
                count = 0;
                tmp = setUGClassList(newUgHead);
                p = tmp->next;
                free(tmp);
                strcpy(cla, p->data.classes);
                while (p != NULL)
                {
                    if (p->data.english != -1)
                    {
                        sum += p->data.english;
                        count++;
                    }
                    tmp = p;
                    p = p->next;
                    free(tmp);
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
            while (newUgHead->next != NULL)
            {
                sum = 0;
                count = 0;
                tmp = setUGClassList(newUgHead);
                p = tmp->next;
                free(tmp);
                strcpy(cla, p->data.classes);
                while (p != NULL)
                {
                    if (p->data.cLanguguage != -1)
                    {
                        sum += p->data.cLanguguage;
                        count++;
                    }
                    tmp = p;
                    p = p->next;
                    free(tmp);
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
            while (newPgHead->next != NULL)
            {
                sum = 0;
                count = 0;
                tmp = setPGClassList(newPgHead);
                p = tmp->next;
                free(tmp);
                strcpy(cla, p->data.classes);
                while (p != NULL)
                {
                    if (p->data.compCourse != -1)
                    {
                        sum += p->data.compCourse;
                        count++;
                    }
                    tmp = p;
                    p = p->next;
                    free(tmp);
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
            while (newPgHead->next != NULL)
            {
                sum = 0;
                count = 0;
                tmp = setPGClassList(newPgHead);
                p = tmp->next;
                free(tmp);
                strcpy(cla, p->data.classes);
                while (p != NULL)
                {
                    if (p->data.thesis != -1)
                    {
                        sum += p->data.thesis;
                        count++;
                    }
                    tmp = p;
                    p = p->next;
                    free(tmp);
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

ugnode *setUGClassList(ugnode *newUgHead)
{
    char classtemp[20];
    int flag = 0;
    ugnode *p, *q, *class, *sameClassStu, *tmp;

    p = newUgHead;
    class = (ugnode *)malloc(sizeof(ugnode));
    class->next = NULL;
    q = class;

    strcpy(classtemp, p->next->data.classes); //将第一个学生所在班级作为第一个班级

    while (p->next != NULL)
    {
        flag = 0;
        tmp = p->next;
        if ((strcmp(tmp->data.classes, classtemp)) == 0) //若班级相同，则放入新链表，并删除原链表中该节点
        {
            sameClassStu = (ugnode *)malloc(sizeof(ugnode));
            sameClassStu->data = tmp->data;
            sameClassStu->next = NULL;

            p->next = tmp->next; //在原链表中删除结点
            free(tmp);

            sameClassStu->next = q->next; //将该结点复制后放入新链表
            q->next = sameClassStu;
            q = sameClassStu;
            flag = 1;
        }
        if (flag == 0)
            p = p->next;
    }
    return class; //返回新建的班级链表
}

pgnode *setPGClassList(pgnode *newPgHead)
{
    char classtemp[20];
    int flag = 0;
    pgnode *p, *q, *class, *sameClassStu, *tmp;

    p = newPgHead;
    class = (pgnode *)malloc(sizeof(pgnode));
    class->next = NULL;
    q = class;

    strcpy(classtemp, p->next->data.classes); //将第一个学生所在班级作为第一个班级

    while (p->next != NULL)
    {
        flag = 0;
        tmp = p->next;
        if ((strcmp(tmp->data.classes, classtemp)) == 0) //若班级相同，则放入新链表，并删除原链表中该节点
        {
            sameClassStu = (pgnode *)malloc(sizeof(pgnode));
            sameClassStu->data = tmp->data;
            sameClassStu->next = NULL;

            p->next = tmp->next; //在原链表中删除结点
            free(tmp);

            sameClassStu->next = q->next; //将该结点复制后放入新链表
            q->next = sameClassStu;
            q = sameClassStu;
            flag = 1;
        }
        if (flag == 0)
            p = p->next;
    }
    return class; //返回新建的班级链表
}

void choseClassCourse()
{
    char cla[20], course[20];
    int mathGrade[5] = {0}, enGrade[5] = {0}, cGrade[5] = {0}, compGrade[5] = {0}, thGrade[5] = {0};
    int tmp[5], item, i;
    ugnode *ugClass, *uPtr;
    pgnode *pgClass, *pPtr;

    while (1)
    {
        system("cls");
        printf("请输入需要查看等级统计结果的班级（输入0可退出）：");
        enterStr(cla, sizeof(cla));
        if (strcmp(cla, "0") == 0)
        {
            system("cls");
            return;
        }
        ugClass = setUClassList(cla);
        pgClass = setPClassList(cla);
        if (ugClass->next != NULL) //所输入班级为本科生班级
        {
            uPtr = ugClass->next;
            while (uPtr != NULL)
            {
                staGrade(mathGrade, uPtr->data.math);
                staGrade(enGrade, uPtr->data.english);
                staGrade(cGrade, uPtr->data.cLanguguage);
                uPtr = uPtr->next;
            }
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
        else if (pgClass->next != NULL) //输入班级为研究生班级
        {
            pPtr = pgClass->next;
            while (pPtr != NULL)
            {
                staGrade(compGrade, pPtr->data.compCourse);
                staGrade(thGrade, pPtr->data.thesis);
                pPtr = pPtr->next;
            }
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
        newlistDestroy(ugClass, pgClass);
    }
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