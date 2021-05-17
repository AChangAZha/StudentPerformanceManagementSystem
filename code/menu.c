#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "tool.h"
#include "inforManage.h"
#include "scoreManage.h"
#include "sort.h"
#include "Statistics.h"

void outputMainMenu()
{
    printf("----------------------------------------------\n");
    printf("               学生成绩管理系统                 \n");
    printf("                     菜单                     \n");
    printf("  1---数据维护管理             2---查看排名     \n");
    printf("  3---查询信息                 4---统计成绩     \n");
    printf("  5---将学生信息另存为         6---关于         \n");
    printf("                   7---退出                     \n");
    printf("----------------------------------------------\n");
}

int initiateMenu()
{
    int item = 0;
    printf("----------------------------------------------\n");
    printf("        1---重试             2---退出系统       \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
    do
    {
        enterNum(&item);
        if (item < 1 || item > 2)
            printf("错误！请输入正确的数字：");
    } while (item < 1 || item > 2);
    return item;
}

int readTxtMenu()
{
    int item = 0;
    printf("----------------------------------------------\n");
    printf("     1---重试                                 \n");
    printf("     2---尝试从dat文件中读取                    \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
    do
    {
        enterNum(&item);
        if (item < 1 || item > 2)
            printf("错误！请输入正确的数字：");
    } while (item < 1 || item > 2);
    return item;
}

int readDatMenu()
{
    int item = 0;
    printf("----------------------------------------------\n");
    printf("     1---重试                                 \n");
    printf("     2---跳过（此操作可能会导致学生信息数据丢失） \n");
    printf("     3---退出                                 \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
    do
    {
        enterNum(&item);
        if (item < 1 || item > 3)
            printf("错误！请输入正确的数字：");
    } while (item < 1 || item > 3);
    return item;
}

int saveMenu()
{
    int item = 0;
    printf("----------------------------------------------\n");
    printf("     1---重试                                 \n");
    printf("     2---跳过（此操作可能会导致学生信息数据丢失） \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
    do
    {
        enterNum(&item);
        if (item < 1 || item > 2)
            printf("错误！请输入正确的数字：");
    } while (item < 1 || item > 2);
    return item;
}

int dataManageMenu()
{
    int item = 0;
    printf("----------------------------------------------\n");
    printf("                  数据维护管理                 \n");
    printf("  1---基本资料数据维护管理                      \n");
    printf("  2---成绩数据维护管理                          \n");
    printf("  3---返回                                     \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
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
        while ((inforManageMenu()) != 5)
            ;
        break;
    case 2:
        while ((scoreManageMenu()) != 5)
            ;
        break;
    }
    return item;
}

int inforManageMenu()
{
    int item = 0;
    printf("----------------------------------------------\n");
    printf("             基本资料数据维护管理               \n");
    printf("    1---添加学生               2---修改资料     \n");
    printf("    3---删除学生               4---查询         \n");
    printf("                    5---返回                  \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
    do
    {
        enterNum(&item);
        if (item < 1 || item > 5)
            printf("错误！请输入正确的数字：");
    } while (item < 1 || item > 5);
    system("cls");
    switch (item)
    {
    case 1:
        while ((addStuMenu()) != 3)
            ;
        break;
    case 2:
        alterData();
        break;
    case 3:
        while ((deleteData()) != 2)
            ;
        break;
    case 4:
        inforSearch();
        break;
    }
    return item;
}

int addStuMenu()
{
    int item = 0;
    printf("----------------------------------------------\n");
    printf("                    添加学生                   \n");
    printf("     1---添加本科生                            \n");
    printf("     2---添加研究生                            \n");
    printf("     3---返回                                 \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
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
        addUgNode();
        break;
    case 2:
        addPgNode();
        break;
    }
    return item;
}

int scoreManageMenu()
{
    int item = 0;
    printf("----------------------------------------------\n");
    printf("              成绩数据的维护管理               \n");
    printf("    1---录入成绩               2---修改成绩     \n");
    printf("    3---删除成绩               4---查询成绩     \n");
    printf("                   5---返回                    \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
    do
    {
        enterNum(&item);
        if (item < 1 || item > 5)
            printf("错误！请输入正确的数字：");
    } while (item < 1 || item > 5);
    system("cls");
    switch (item)
    {
    case 1:
        inputScore();
        break;
    case 2:
        alterScore();
        break;
    case 3:
        deleteScore();
        break;
    case 4:
        scoreSearch();
        break;
    }
    return item;
}

int sortMenu()
{
    int item = 0;
    printf("----------------------------------------------\n");
    printf("                    查看排名                   \n");
    printf("    1---全校排名                               \n");
    printf("    2---班级排名                               \n");
    printf("    3---返回                                   \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
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
        scoreSort();
        break;
    case 2:
        while ((classSort()) != 0)
            ;
        break;
    }
    return item;
}

int statisticsMenu()
{
    int item = 0;
    printf("----------------------------------------------\n");
    printf("                    统计成绩                   \n");
    printf("    1---统计各课程平均成绩                      \n");
    printf("    2---统计各课程不同等级的学生人数             \n");
    printf("    3---返回                                   \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
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
        while ((choseStuCate()) != 3)
            ;
        break;
    case 2:
        while ((choseClassCourse()) != 0)
            ;
        break;
    }
    return item;
}

int choseStuCate()
{
    int item = 0;
    printf("--------------------------------------------------------\n");
    printf("                      统计平均成绩                       \n");
    printf("  1.查看本科生成绩统计结果    2.查看研究生成绩统计结果      \n");
    printf("     (高数、英语、C语言)      (课程综合成绩、论文成绩)     \n");
    printf("                        3.退出                          \n");
    printf("--------------------------------------------------------\n");
    printf("请选择菜单编号：");
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
        countUgAvgMenu();
        break;
    case 2:
        countPgAvgMenu();
        break;
    }
    return item;
}