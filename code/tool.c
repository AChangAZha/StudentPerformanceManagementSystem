#include <stdio.h>

void enterNUM(int *num) //从键盘输入数字
{
    while (scanf("%d",num)!=1) //保证输入的是数字
    {
        printf("错误！请输入正确的数字：");
        while (getchar()!='\n');
    }
}