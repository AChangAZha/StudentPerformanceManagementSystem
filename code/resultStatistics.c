#include "model.h"
#include "resultStatistics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"

void countUgAvgMenu() //统计各班平均分菜单
{
    int item;
    ugnode *newUgHead;
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
            else
                countUgAvg(newUgHead, item);
            free(newUgHead);
        }
        else if (item == 2)
        {
            printf("各班英语平均成绩：\n\n");
            if (newUgHead->next == NULL)
                printf("暂无数据\n");
            else
                countUgAvg(newUgHead, item);
            free(newUgHead);
        }
        else if (item == 3)
        {
            printf("各班C语言平均成绩：\n\n");
            if (newUgHead->next == NULL)
                printf("暂无数据\n");
            else
                countUgAvg(newUgHead, item);
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

void countPgAvgMenu() //统计各班平均分菜单
{
    int item;
    pgnode *newPgHead;
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
            else
                countPgAvg(newPgHead, item);
            free(newPgHead);
        }
        else if (item == 2)
        {
            printf("各班论文平均成绩：\n\n");
            if (newPgHead->next == NULL)
                printf("暂无数据\n");
            else
                countPgAvg(newPgHead, item);
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

void countUgAvg(ugnode *newUgHead, int item) //统计各班平均分
{
    int sum, count;
    double avg;
    char cla[20];
    ugnode *p, *tmp;
    while (newUgHead->next != NULL) //每次都从头开始找相同班级的学生，直到链表为空
    {
        sum = 0;
        count = 0;
        p = newUgHead;
        strcpy(cla, p->next->data.classes); //将第一个学生所在班级作为第一个班级
        while (p->next != NULL)             //寻找与第一个学生的班级相同的学生
        {
            tmp = p->next;
            if ((strcmp(tmp->data.classes, cla)) == 0) //若班级相同，删除该节点
            {
                if (item == 1)
                {
                    if (tmp->data.math != -1) //计算相同班级学生的成绩
                    {
                        sum += tmp->data.math;
                        count++;
                    }
                }
                else if (item == 2)
                {
                    if (tmp->data.english != -1) //计算相同班级学生的成绩
                    {
                        sum += tmp->data.english;
                        count++;
                    }
                }
                else if (item == 3)
                {
                    if (tmp->data.cLanguguage != -1) //计算相同班级学生的成绩
                    {
                        sum += tmp->data.cLanguguage;
                        count++;
                    }
                }
                p->next = tmp->next;
                free(tmp); //销毁该节点
            }
            else
                p = p->next;
        }
        if (count != 0) //0不能作余数
        {
            avg = sum * 1.0 / count;
            printf("%s：%.2lf\n", cla, avg);
        }
        else
            printf("%s：暂无数据\n", cla);
    }
}

void countPgAvg(pgnode *newPgHead, int item) //统计各班平均分
{
    int sum, count;
    double avg;
    char cla[20];
    pgnode *p, *tmp;
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
                if (item == 1)
                {
                    if (tmp->data.compCourse != -1)
                    {
                        sum += tmp->data.compCourse;
                        count++;
                    }
                }
                else if (item == 2)
                {
                    if (tmp->data.thesis != -1)
                    {
                        sum += tmp->data.thesis;
                        count++;
                    }
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
            printf("%s：暂无数据\n", cla);
    }
}

int choseClassCourse() //查看各班课程各等级人数
{
    char cla[20], course[20];
    int mathGrade[5] = {0}, enGrade[5] = {0}, cGrade[5] = {0}, compGrade[5] = {0}, thGrade[5] = {0};
    int tmp[5] = {0}, item, i, uflag = 0, pflag = 0;
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
    else if (pflag == 1)
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

void staGrade(int grade[], int score) //统计各等级人数
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
