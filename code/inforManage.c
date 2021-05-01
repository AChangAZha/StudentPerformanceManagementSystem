#define _CRT_SECURE_NO_WARNINGS
#include "inforManage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "model.h"
#include "inquire.h"
#include "tool.h"

void addUgNode()  //添加本科生 
{
    int sex=0,count=0;
    char tmp[12];
    ugnode *ug;

    while (1)
    {
        count++;
        printf("正在添加第%d名本科生\n",count);
        printf("姓名(最多可输入5个汉字,输入0可结束添加)：");
        enterStr(tmp,sizeof(tmp));
        if(strcmp(tmp,"0")==0) break;  //输入0结束输入

        ug=(ugnode *)malloc(sizeof(ugnode)); //不为0才分配存储空间
        ug->next=NULL;
        strcpy(ug->data.name,tmp);
		//对比两条链表头结点中的学号，较大者即为最新学号
        ug->data.num=(ugHead->data.num)>(pgHead->data.num)?(ugHead->data.num):(pgHead->data.num);
        ugHead->data.num=ug->data.num+1;
        printf("性别(请选择) 1.男 2.女：");
        do
        {
			enterNUM(&sex);
            if (sex!=1 && sex!=2) printf("错误！请输入正确的数字：");
        } while (sex!=1 && sex!=2);
        ug->data.sex=(sex==1)?male:female;
        printf("专业(最多可输入9个汉字)：");
        enterStr(ug->data.speciaty,sizeof(ug->data.speciaty));
        printf("班级(最多可输入9个汉字)：");
        enterStr(ug->data.classes,sizeof(ug->data.classes));

        ug->data.math=-1; //成绩初始化为-1
        ug->data.english=-1;
        ug->data.cLanguguage=-1;
        ug->data.totalScore=-1;
        ug->data.classRank=-1;
        ug->data.schoolRank=-1;
        if(ugTail!=NULL) ugTail->next=ug;
        else ugHead->next=ug;
        ugTail=ug; //尾指针后移
        printf("\n");
        sex=0;
    }
    printf("成功添加%d个本科生！\n",count-1);
    return;
}

void addPgNode()  //添加研究生
{
    int sex=0,count=0;
    char tmp[12];
    pgnode *pg;

    while (1)
    {
        count++;
        printf("正在添加第%d名研究生\n",count);
        printf("姓名(最多可输入5个汉字,输入0可结束添加)：");
        enterStr(tmp,sizeof(tmp));
        if(strcmp(tmp,"0")==0) break;

        pg=(pgnode *)malloc(sizeof(pgnode));
        pg->next=NULL;
        strcpy(pg->data.name,tmp);
        pg->data.num=(ugHead->data.num)>(pgHead->data.num)?(ugHead->data.num):(pgHead->data.num);
        pgHead->data.num=pg->data.num+1;
        printf("性别(请选择) 1.男 2.女：");
        do
        {
			enterNUM(&sex);
            if (sex!=1 && sex!=2) printf("错误！请输入正确的数字：");
        } while (sex!=1 && sex!=2);
        pg->data.sex=(sex==1)?male:female;
        printf("专业(最多可输入9个汉字)：");
        enterStr(pg->data.speciaty,sizeof(pg->data.speciaty));
        printf("班级(最多可输入9个汉字)：");
        enterStr(pg->data.classes,sizeof(pg->data.classes));
        printf("研究方向(最多可输入9个汉字)：");
        enterStr(pg->data.rschFields,sizeof(pg->data.rschFields));
        printf("导师(最多可输入5个汉字)：");
        enterStr(pg->data.advisor,sizeof(pg->data.advisor));

        pg->data.compCourse=-1;
        pg->data.thesis=-1;
        pg->data.totalScore=-1;
        pg->data.classRank=-1;
        pg->data.schoolRank=-1;
        if(pgTail!=NULL) pgTail->next=pg;
        else pgHead->next=pg;
        pgTail=pg;
        printf("\n");
        sex=0;
    }
    printf("成功添加%d个研究生！\n",count-1);
    return;
}

void inforSearch()  //查询学生基本信息
{
    int num=0,opt=0;
    ugnode *uPtr;
    pgnode *pPtr;
    while(1)
    {
		//每个学号对应一个学生，不区分本科生和研究生
        printf("请输入学号：");
		enterNUM(&num);
		//需要在两个链表中搜寻
		//调用查找函数(在inquire.c中定义)
        if((uPtr=serchUg(num))!=NULL)
        {
            printf("查询成功，以下是该学生的基本资料：\n");
            printf("%-10s%-8s%-12s%-6s%-20s%-20s\n","培养层次","学号","姓名","性别","专业","班级");
            printf("%-10s%-8d%-12s","本科",uPtr->data.num,uPtr->data.name);
            if(uPtr->data.sex==male) printf("%-6s","男");
            else printf("%-6s","女");
            printf("%-20s%-20s\n",uPtr->data.speciaty,uPtr->data.classes);
        }
        else if((pPtr=serchPg(num))!=NULL)
        {
            printf("查询成功，以下是该学生的基本资料：\n");
            printf("%-10s%-8s%-12s%-6s%-20s%-20s%-20s%-12s\n","培养层次","学号","姓名","性别","专业","班级","研究方向","导师");
            printf("%-10s%-8d%-12s","研究生",pPtr->data.num,pPtr->data.name);
            if(pPtr->data.sex==male) printf("%-6s","男");
            else printf("%-6s","女");
            printf("%-20s%-20s%-20s%-12s\n",pPtr->data.speciaty,pPtr->data.classes,pPtr->data.rschFields,pPtr->data.advisor);
        }
        else printf("没有查询到相关信息！\n");
        printf("请选择 1.继续查询 2.返回：");
        do
        {
			enterNUM(&opt);
			if (opt!=1 && opt!= 2) printf("错误！请输入正确的数字：");
        } while (opt!=1 && opt!=2);
        printf("\n");
        if(opt==2) return;
        num=0;
		opt=0;
    }
}

void alterData()  //修改学生基本信息
{
	int uflag,pflag,num,item,sex,opt;
    ugnode *uPtr;
    pgnode *pPtr;
    printf("请输入要修改信息的学生的学号：");
    enterNUM(&num);

	uflag=pflag=0;
	if((uPtr=serchUg(num))!=NULL) uflag=1;
	else if((pPtr=serchPg(num))!=NULL) pflag=1;
    else
    {
        printf("没有找到该学生！\n");
	    return;
    }

	if(uflag==1)   //若uflag为一，则表示所输入学号是本科生的，否则为研究生的学号
	{
		printf("----------------------------------------------\n");
		printf("  1---修改姓名                  2---修改性别  \n");
		printf("  3---修改专业                  4---修改班级  \n");
		printf("                  5---退出                    \n");
		printf("----------------------------------------------\n");
		
		printf("\n请输入菜单编号：");
        while(1)
		{
            enterNUM(&item);
            if(item>5 || item<1)
	    	{
		    	printf("菜单编号输入错误，请重新输入：");
                continue;
		    }
			switch(item){
				case 1:
				{
					printf("请修改姓名(最多可输入5个汉字)：");
					enterStr(uPtr->data.name,sizeof(uPtr->data.name));
					break;
				}
				case 2:
				{
                    printf("请修改性别(请选择) 1.男 2.女：");
                    do
                    {
            			enterNUM(&sex);
                        if (sex!=1 && sex!=2) printf("错误！请输入正确的数字：");
                    } while (sex!=1 && sex!=2);
                    uPtr->data.sex=(sex==1)?male:female;
					break;
				}
				case 3:
				{
                    printf("请修改专业(最多可输入9个汉字)：");
                    enterStr(uPtr->data.speciaty,sizeof(uPtr->data.speciaty));
					break;
				}
				case 4:
				{
                    printf("请修改班级(最多可输入9个汉字)：");
                    enterStr(uPtr->data.classes,sizeof(uPtr->data.classes));
					break;
				}
				case 5:
				{
					printf("谢谢使用！\n");
					return;
				}
			}
			printf("请选择下一操作（1.继续修改 2.退出）：");
            do
            {
                enterNUM(&opt);
                if (opt!=1 && opt!=2) printf("错误！请输入正确的数字：");
            } while (opt!=1 && opt!=2);
            if(opt==2)
            {
                printf("谢谢使用！\n");
                return;
            }
            else printf("\n请输入菜单编号：");
		}
		printf("修改后的学生信息：\n");
        printf("%-10s%-8s%-12s%-6s%-20s%-20s\n","培养层次","学号","姓名","性别","专业","班级");
        printf("%-10s%-8d%-12s","本科",uPtr->data.num,uPtr->data.name);
        if(uPtr->data.sex==male) printf("%-6s","男");
        else printf("%-6s","女");
        printf("%-20s%-20s\n",uPtr->data.speciaty,uPtr->data.classes);

	}
	else   //用户输入学号为研究生学号
	{
		printf("----------------------------------------------\n");
		printf("  1---修改姓名                  2---修改性别  \n");
		printf("  3---修改专业                  4---修改班级  \n");
		printf(" 5---修改研究方向               6---修改导师  \n");
		printf("                  7---退出                    \n");
		printf("----------------------------------------------\n");
		
		printf("\n请输入菜单编号：");
        while(1)
		{
            enterNUM(&item);
            if(item>7 || item<1)
	    	{
		    	printf("菜单编号输入错误，请重新输入：");
                continue;
		    }
			switch(item){
				case 1:
				{
					printf("请修改姓名(最多可输入5个汉字)：");
					enterStr(pPtr->data.name,sizeof(pPtr->data.name));
					break;
				}
				case 2:
				{
                    printf("请修改性别(请选择) 1.男 2.女：");
                    do
                    {
			            enterNUM(&sex);
                        if (sex!=1 && sex!=2) printf("错误！请输入正确的数字：");
                    } while (sex!=1 && sex!=2);
                    pPtr->data.sex=(sex==1)?male:female;
                    break;
                }
				case 3:
				{
                    printf("请修改专业(最多可输入9个汉字)：");
                    enterStr(pPtr->data.speciaty,sizeof(pPtr->data.speciaty));
					break;
				}
				case 4:
				{
                    printf("请修改班级(最多可输入9个汉字)：");
                    enterStr(pPtr->data.classes,sizeof(pPtr->data.classes));
					break;
                }
				case 5:
				{
                    printf("请修改研究方向(最多可输入9个汉字)：");
                    enterStr(pPtr->data.rschFields,sizeof(pPtr->data.rschFields));
					break;
				}
				case 6:
				{
                    printf("请修改导师(最多可输入5个汉字)：");
                    enterStr(pPtr->data.advisor,sizeof(pPtr->data.advisor));
					break;
				}
				case 7:
				{
					printf("谢谢使用！\n");
					return;
				}
			}
			printf("请选择下一操作（1.继续修改 2.退出）：");
            do
            {
                enterNUM(&opt);
                if (opt!=1 && opt!=2) printf("错误！请输入正确的数字：");
            } while (opt!=1 && opt!=2);
            if(opt==2)
            {
                printf("谢谢使用！\n");
                return;
            }
            else printf("\n请输入菜单编号：");
		}
		printf("修改后的学生信息：\n");
        printf("%-10s%-8s%-12s%-6s%-20s%-20s%-20s%-12s\n","培养层次","学号","姓名","性别","专业","班级","研究方向","导师");
        printf("%-10s%-8d%-12s","研究生",pPtr->data.num,pPtr->data.name);
        if(pPtr->data.sex==male) printf("%-6s","男");
        else printf("%-6s","女");
        printf("%-20s%-20s%-20s%-12s\n",pPtr->data.speciaty,pPtr->data.classes,pPtr->data.rschFields,pPtr->data.advisor);
	}
}