#include "menu.h"
#include <stdio.h>
#include "tool.h"

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
    int item;
    printf("----------------------------------------------\n");
    printf("        1---重试             2---退出系统       \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
    do
    {
        enterNUM(&item);
        if (item < 1 || item > 2)
            printf("错误！请输入正确的数字：");
    } while (item < 1 || item > 2);
    return item;
}

int readTxtMenu()
{
    int item;
    printf("----------------------------------------------\n");
    printf("     1---重试                                 \n");
    printf("     2---尝试从dat文件中读取                    \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
    do
    {
        enterNUM(&item);
        if (item < 1 || item > 2)
            printf("错误！请输入正确的数字：");
    } while (item < 1 || item > 2);
    return item;
}

int readDatMenu()
{
    int item;
    printf("----------------------------------------------\n");
    printf("     1---重试                                 \n");
    printf("     2---跳过（此操作可能会导致学生信息数据丢失） \n");
    printf("     3---退出                                 \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
    do
    {
        enterNUM(&item);
        if (item < 1 || item > 3)
            printf("错误！请输入正确的数字：");
    } while (item < 1 || item > 3);
    return item;
}

int saveMenu()
{
    int item;
    printf("----------------------------------------------\n");
    printf("     1---重试                                 \n");
    printf("     2---跳过（此操作可能会导致学生信息数据丢失） \n");
    printf("----------------------------------------------\n");
    printf("\n请选择：");
    do
    {
        enterNUM(&item);
        if (item < 1 || item > 2)
            printf("错误！请输入正确的数字：");
    } while (item < 1 || item > 2);
    return item;
}