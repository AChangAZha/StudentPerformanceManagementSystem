#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void enterNUM(int *num) //从键盘输入数字
{
    while (scanf("%d",num)!=1) //保证输入的是数字
    {
        printf("错误！请输入正确的数字：");
        while (getchar()!='\n');
    }
}

void enterStr(char *str,int num)
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