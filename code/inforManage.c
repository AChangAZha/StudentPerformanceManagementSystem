#include "inforManage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "model.h"
#include "inquire.h"

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
        scanf("%s",tmp);
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
            while (scanf("%d", &sex)!= 1) //保证输入的是数字
            {
                printf("错误！请输入正确的数字：");
                while (getchar()!='\n');
            }
            if (sex!=1 && sex!=2) printf("错误！请输入正确的数字：");
        } while (sex!=1 && sex!=2);
        ug->data.sex=(sex==1)?male:female;
        printf("专业(最多可输入9个汉字)：");
        scanf("%s",ug->data.speciaty);
        printf("班级(最多可输入9个汉字)：");
        scanf("%s",ug->data.classes);

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
        scanf("%s",tmp);
        if(strcmp(tmp,"0")==0) break;

        pg=(pgnode *)malloc(sizeof(pgnode));
        pg->next=NULL;
        strcpy(pg->data.name,tmp);
        pg->data.num=(ugHead->data.num)>(pgHead->data.num)?(ugHead->data.num):(pgHead->data.num);
        pgHead->data.num=pg->data.num+1;
        printf("性别(请选择) 1.男 2.女：");
        do
        {
            while (scanf("%d",&sex)!=1)
            {
                printf("错误！请输入正确的数字：");
                while (getchar()!='\n');
            }
            if (sex!=1 && sex!=2) printf("错误！请输入正确的数字：");
        } while (sex!=1 && sex!=2);
        pg->data.sex=(sex==1)?male:female;
        printf("专业(最多可输入9个汉字)：");
        scanf("%s",pg->data.speciaty);
        printf("班级(最多可输入9个汉字)：");
        scanf("%s",pg->data.classes);
        printf("研究方向(最多可输入9个汉字)：");
        scanf("%s",pg->data.rschFields);
        printf("导师(最多可输入5个汉字)：");
        scanf("%s",pg->data.advisor);

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
        while (scanf("%d",&num)!=1) //保证输入的数字
        {
            printf("错误！请输入数字：");
            while (getchar()!='\n');
        }
		//需要在两个链表中搜寻
		//调用查找函数(在inquire.c中定义)
        if((uPtr=serchUg(num))!=NULL)
        {
            printf("查询成功，以下是该学生的基本资料：\n");
            printf("%-14s%-14s%-14s%-14s%-14s%-14s\n","培养层次","学号","姓名","性别","专业","班级");
            printf("%-14s%-14d%-14s","本科",uPtr->data.num,uPtr->data.name);
            if(uPtr->data.sex==male) printf("%-14s","男");
            else printf("%-14s","女");
            printf("%-14s%-14s\n",uPtr->data.speciaty,uPtr->data.classes);
        }
        else if((pPtr=serchPg(num))!=NULL)
        {
            printf("查询成功，以下是该学生的基本资料：\n");
            printf("%-14s%-14s%-14s%-14s%-14s%-14s%-14s%-14s\n","培养层次","学号","姓名","性别","专业","班级","研究方向","导师");
            printf("%-14s%-14d%-14s","研究生",pPtr->data.num,pPtr->data.name);
            if(pPtr->data.sex==male) printf("%-14s","男");
            else printf("%-14s","女");
            printf("%-14s%-14s%-14s%-14s\n",pPtr->data.speciaty,pPtr->data.classes,pPtr->data.rschFields,pPtr->data.advisor);
        }
        else printf("没有查询到相关信息！\n");
        printf("请选择 1.继续查询 2.返回：");
        do
        {
            while (scanf("%d", &opt)!=1)
            {
                printf("错误！请输入正确的数字：");
                while (getchar()!='\n');
            }
            if (opt!=1 && opt!= 2) printf("错误！请输入正确的数字：");
        } while (opt!=1 && opt!=2);
        printf("\n");
        if(opt==2) return;
        num=0;
		opt=0;
    }
}

int alterData()  //修改学生基本信息
{
	int uflag,pflag,n,item,x,fi;
	ugnode *p;
	pgnode *q;
	
	printf("请输入要修改信息的学生的学号：");
	scanf("%d",&n);
	p=ugHead->next;
	q=pgHead->next;

	uflag=pflag=0;
	while(p!=NULL&&q!=NULL)              //遍历两个链表
	{
		if(p->data.num==n) 
		{
			uflag=1;
			break;
		}
		if(q->data.num==n)
		{
			pflag=1;
			break;
		}
		p=p->next;
		q=q->next;
	}

	if(uflag==0&&pflag==0)              //若在两个链表其中一个结束时还没有找到对应学号，在另一个链表中继续找
	{
		while(p!=NULL&&q==NULL)
		{
			if(p->data.num==n) 
			{
				uflag=1;
				break;
			}
			p=p->next;
		}
		while(p==NULL&&q!=NULL)
		{
			if(q->data.num==n)
			{
				pflag=1;
				break;
			}
			q=q->next;
		}
		if(uflag==0&&pflag==0)                        //若两个链表遍历完以后，两个标志没有改变，则表示没有找到学生
		{
			printf("找不到该学生！\n");
			return 0;
		}
	}

	if(uflag==1)                             //若uflag为一，则表示所输入学号是本科生的，否则为研究生的学号
	{
		fflush(stdin);
		printf("----------------------------------------------\n");
		printf("  1---修改姓名                  2---修改性别  \n");
		printf("  3---修改专业                  4---修改班级  \n");
		printf("                  5---退出                    \n");
		printf("----------------------------------------------\n");
		
		printf("\n请输入菜单编号：");
		scanf("%d",&item);
		if(item>5||item<1)
		{
			printf("菜单编号输入错误，请重新输入：");
		}
		else 
		{
			while(item<=5&&item>0)
			{
				switch(item){
					case 1:
					{
						fflush(stdin);
						printf("请输入要输入的新信息：");
						scanf("%s",p->data.name);
						break;
					}
					case 2:
					{
						fflush(stdin);
						printf("请选择要修改的性别序号(1.男 2.女) :  ");
						scanf("%d",&x);
						x=x-1;
						p->data.sex=(gand)x;
						break;
					}
					case 3:
					{
						fflush(stdin);
						printf("请输入要输入的新信息：");
						scanf("%s",p->data.speciaty);
						break;
					}
					case 4:
					{
						fflush(stdin);
						printf("请输入要输入的新信息：");
						scanf("%s",p->data.classes);
						break;
					}
					case 5:
					{
						printf("谢谢使用！\n");
						break;
					}
				}
				if(item==5) break;
				printf("请选择下一操作（1.继续修改 2.退出） ：  ");
				scanf("%d",&fi);
				if(fi==1)
				{
					printf("请再次选择菜单编号：");
					scanf("%d",&item);
				}
				else item=5;
			}

			printf("输出修改后的学生信息：\n");
			printf("%-14s%-14s%-14s%-14s%-14s%-14s\n","培养层次","学号","姓名","性别","专业","班级");
			printf("%-14s%-14d%-14s","本科",p->data.num,p->data.name);
			if(p->data.sex==male) printf("%-14s","男");
			else printf("%-14s","女");
			printf("%-14s%-14s\n",p->data.speciaty,p->data.classes);
		}
	}
	else                                                               //用户输入学号为研究生学号
	{
		fflush(stdin);
		printf("----------------------------------------------\n");
		printf("  1---修改姓名                  2---修改性别  \n");
		printf("  3---修改专业                  4---修改班级  \n");
		printf(" 5---修改研究方向               6---修改导师  \n");
		printf("                  7---退出                    \n");
		printf("----------------------------------------------\n");
		
		printf("\n请输入菜单编号：");
		scanf("%d",&item);
		if(item>7||item<1)
		{
			printf("菜单编号输入错误，请重新输入：");
		}
		else 
		{
			while(item<=7&&item>0)
			{
				switch(item){
					case 1:
					{
						fflush(stdin);
						printf("请输入要输入的新信息：");
						scanf("%s",q->data.name);
						break;
					}
					case 2:
					{
						fflush(stdin);
						printf("请选择要修改的性别序号(1.男 2.女) :  ");
						scanf("%d",&x);
						x=x-1;
						q->data.sex=(gand)x;
						break;
					}
					case 3:
					{
						fflush(stdin);
						printf("请输入要输入的新信息：");
						scanf("%s",q->data.speciaty);
						break;
					}
					case 4:
					{
						fflush(stdin);
						printf("请输入要输入的新信息：");
						scanf("%s",q->data.classes);
						break;
					}
					case 5:
					{
						fflush(stdin);
						printf("请输入要输入的新信息：");
						scanf("%s",q->data.rschFields);
						break;
					}
					case 6:
					{
						fflush(stdin);
						printf("请输入要输入的新信息：");
						scanf("%s",q->data.advisor);
						break;
					}
					case 7:
					{
						printf("谢谢使用！\n");
						break;
					}
				}
				if(item==7) break;
				printf("请选择下一操作（1.继续修改 2.退出） ：  ");
				scanf("%d",&fi);
				if(fi==1)
				{
					printf("请再次选择菜单编号：");
					scanf("%d",&item);
				}
				else item=7;
			}
			printf("输出修改后的学生信息：\n");
            printf("%-14s%-14s%-14s%-14s%-14s%-14s%-14s%-14s\n","培养层次","学号","姓名","性别","专业","班级","研究方向","导师");
            printf("%-14s%-14d%-14s","研究生",q->data.num,q->data.name);
            if(q->data.sex==male) printf("%-14s","男");
            else printf("%-14s","女");
            printf("%-14s%-14s%-14s%-14s\n",q->data.speciaty,q->data.classes,q->data.rschFields,q->data.advisor);
		}
	}
}	