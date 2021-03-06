#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "fileOperate.h"
#include "tool.h"
#include "menu.h"
#include "scoreManage.h"

int main()
{
    int item;

    /**************************************************************/
    //系统初始化
    while ((listInitiate()) == -1)
    {
        printf("系统初始化失败！\n");
        if ((initiateMenu()) == 2)
        {
            system("cls");
            printf("谢谢使用！");
            system("pause");
            return 0;
        }
        system("cls");
    }
    /**************************************************************/

    /**************************************************************/
    //读取学生数据
    printf("系统初始化成功！正在从文件中读取学生数据......\n\n");
    while ((readFromUgtxt()) == -1)
    {
        if ((readTxtMenu()) == 2)
        {
            system("cls");
            while ((readFromUgdat()) == -1)
            {
                item = readDatMenu();
                system("cls");
                if (item == 3)
                {
                    printf("谢谢使用！");
                    listDestroy(&ugHead, &pgHead);
                    system("pause");
                    return 0;
                }
                if (item == 2)
                    break;
            }
            break;
        }
        system("cls");
    }
    while ((readFromPgtxt()) == -1)
    {
        if ((readTxtMenu()) == 2)
        {
            system("cls");
            while ((readFromPgdat()) == -1)
            {
                item = readDatMenu();
                system("cls");
                if (item == 3)
                {
                    printf("谢谢使用！");
                    listDestroy(&ugHead, &pgHead);
                    system("pause");
                    return 0;
                }
                if (item == 2)
                    break;
            }
            break;
        }
        system("cls");
    }
    calculate();
    printf("\n欢迎使用学生成绩管理系统！");
    system("pause");
    system("cls");
    /**************************************************************/

    /*************************************************************/
    //主菜单
    while (1)
    {
        outputMainMenu();
        printf("\n请输入菜单编号：");
        do
        {
            enterNum(&item);
            if (item < 1 || item > 7)
                printf("错误！请输入正确的数字：");
        } while (item < 1 || item > 7);
        system("cls");
        switch (item)
        {
        case 1:
            while ((dataManageMenu()) != 3)
                ;
            break;
        case 2:
            while ((sortMenu()) != 3)
                ;
            break;
        case 3:
            while ((inquireMenu()) != 5)
                ;
            break;
        case 4:
            while ((statisticsMenu()) != 3)
                ;
            break;
        case 5:
            while ((saveToFile()) != 0)
                ;
            break;
        case 6:
            about();
            break;
        case 7:
            break;
        }
        if (item == 7)
            break;
        system("cls");
    }
    /*************************************************************/

    /********************************/
    //退出系统，保存学生信息
    printf("正在保存学生信息......\n");
    while ((saveToUgtxt(NULL)) == -1)
    {
        item = saveMenu();
        system("cls");
        if (item == 2)
            break;
    }
    while ((saveToUgdat(NULL)) == -1)
    {
        item = saveMenu();
        system("cls");
        if (item == 2)
            break;
    }
    while ((saveToPgtxt(NULL)) == -1)
    {
        item = saveMenu();
        system("cls");
        if (item == 2)
            break;
    }
    while ((saveToPgdat(NULL)) == -1)
    {
        item = saveMenu();
        system("cls");
        if (item == 2)
            break;
    }
    listDestroy(&ugHead, &pgHead);
    printf("\n谢谢使用！\n");
    /******************************/
    system("pause");
    return 0;
}