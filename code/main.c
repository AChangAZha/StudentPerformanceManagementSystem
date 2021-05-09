#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "fileOperate.h"
#include "inforManage.h"
#include "scoreManage.h"
#include "tool.h"
#include "menu.h"

int main()
{
    int item;

    /**************************************************************/
    while ((listInitiate())==-1)
    {
        printf("系统初始化失败！\n");
        if((initiateMenu())==2)
        {
            system("cls");
            printf("谢谢使用！");
            return 0;
        }
        system("cls");
    }
    /**************************************************************/

    /**************************************************************/
    printf("系统初始化成功！正在从文件中读取学生数据......\n\n");
    while ((readFromUgtxt())==-1)
    {
        if((readTxtMenu())==2)
        {
            system("cls");
            while((readFromUgdat())==-1)
            {
                item=readDatMenu();
                system("cls");
                if(item==3)
                {
                    printf("谢谢使用！");
                    listDestroy();
                    return 0;
                }
                if(item==2) break;
            }
            break;
        }
        system("cls");
    }
    while ((readFromPgtxt())==-1)
    {
        if((readTxtMenu())==2)
        {
            system("cls");
            while((readFromPgdat())==-1)
            {
                item=readDatMenu();
                system("cls");
                if(item==3)
                {
                    printf("谢谢使用！");
                    listDestroy();
                    return 0;
                }
                if(item==2) break;
            }
            break;
        }
        system("cls");
    }
    printf("\n欢迎使用学生成绩管理系统！");
    system("pause");
    system("cls");
    /**************************************************************/






    /*************************************************************/
    while (1)
    {
        outputMenu();
        printf("\n请输入菜单编号：");
        do
        {
            enterNUM(&item);
            if (item<1 || item>7) printf("错误！请输入正确的数字：");
        } while (item<1 || item>7);
        system("cls");
        switch (item)
        {
            case 1: printf("待开发\n");break;
            case 2: printf("待开发\n");break;
            case 3: printf("待开发\n");break;
            case 4: printf("待开发\n");break;
            case 5: printf("待开发\n");break;
            case 6: printf("待开发\n");break;
            case 7: break;
        }
        if(item==7) break;
        system("pause");
        system("cls");
    }
    /*************************************************************/
    
    /********************************/
    printf("正在保存学生信息......\n");
    while ((saveToUgtxt(NULL))==-1)
    {
        item=saveMenu();
        system("cls");
        if(item==2) break;
    }
    while ((saveToUgdat(NULL))==-1)
    {
        item=saveMenu();
        system("cls");
        if(item==2) break;
    }
    while ((saveToPgtxt(NULL))==-1)
    {
        item=saveMenu();
        system("cls");
        if(item==2) break;
    }
    while ((saveToPgdat(NULL))==-1)
    {
        item=saveMenu();
        system("cls");
        if(item==2) break;
    }
    listDestroy();
    printf("\n谢谢使用！\n");
    /******************************/
    system("pause");
    return 0;
}