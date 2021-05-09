#define _CRT_SECURE_NO_WARNINGS
#include "tool.h"
#include <stdio.h>
#include <string.h>
#include "model.h"

void enterNUM(int *num) //从键盘输入数字
{
    while (scanf("%d",num)!=1) //保证输入的是数字
    {
        printf("错误！请输入正确的数字：");
        while (getchar()!='\n');
    }
}

void enterStr(char *str,int num) //输入字符串
{
    char tmp[50];
    while(1)
    {
        scanf("%s",tmp);
        if(strlen(tmp)<num) break;
        printf("字数超过限制，请重新输入：");
        while (getchar()!='\n');
    }
    strcpy(str,tmp);
}

void outputUgInfor(ugnode *uPtr)
{
    printf("%-10s%-8s%-12s%-6s%-20s%-20s\n","培养层次","学号","姓名","性别","专业","班级");
    printf("%-10s%-8d%-12s","本科",uPtr->data.num,uPtr->data.name);
    if(uPtr->data.sex==male) printf("%-6s","男");
    else printf("%-6s","女");
    printf("%-20s%-20s\n",uPtr->data.speciaty,uPtr->data.classes);
}

void outputPgInfor(pgnode *pPtr)
{
    printf("%-10s%-8s%-12s%-6s%-20s%-20s%-20s%-12s\n","培养层次","学号","姓名","性别","专业","班级","研究方向","导师");
    printf("%-10s%-8d%-12s","研究生",pPtr->data.num,pPtr->data.name);
    if(pPtr->data.sex==male) printf("%-6s","男");
    else printf("%-6s","女");
    printf("%-20s%-20s%-20s%-12s\n",pPtr->data.speciaty,pPtr->data.classes,pPtr->data.rschFields,pPtr->data.advisor);
}