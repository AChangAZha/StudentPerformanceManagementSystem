#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "fileOperate.h"
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "tool.h"

int listInitiate()   //链表初始化
{
    char str0[]="-1";
    char str1[]="该数据";
    char str2[]="用于保存";
    char str3[]="最新学号";

    if((ugHead=(ugnode *)malloc(sizeof(ugnode)))==NULL)
    {
        printf("不能成功分配本科生链表存储块！\n");
        return -1;
    }
    (ugHead)->next=NULL;
    if((pgHead=(pgnode *)malloc(sizeof(pgnode)))==NULL)
    {
        free(pgHead);  //只有两个链表同时初始化成功程序才能正常运行
        pgHead=NULL;
        printf("不能成功分配研究生链表存储块！\n");
        return -1;
    }
    (pgHead)->next=NULL;

    //两链表的头结点用于保存最新学号
    //便于每次添加学生时都从最新学号开始
    ugHead->data.num=1;
    strcpy(ugHead->data.name,str1);
    ugHead->data.sex=(gand)0;
    strcpy(ugHead->data.speciaty,str2);
    strcpy(ugHead->data.classes,str3);
    ugHead->data.math=-1;
    ugHead->data.english=-1;
    ugHead->data.cLanguguage=-1;
    ugHead->data.totalScore=-1;
    ugHead->data.classRank=-1;
    ugHead->data.schoolRank=-1;

    pgHead->data.num=1;
    strcpy(pgHead->data.name,str1);
    pgHead->data.sex=(gand)0;
    strcpy(pgHead->data.speciaty,str2);
    strcpy(pgHead->data.classes,str3);
    strcpy(pgHead->data.rschFields,str0);
    strcpy(pgHead->data.advisor,str0);
    pgHead->data.compCourse=-1;
    pgHead->data.thesis=-1;
    pgHead->data.totalScore=-1;
    pgHead->data.classRank=-1;
    pgHead->data.schoolRank=-1;

    return 1;
}

int readFromUgtxt()  //从txt文件读取本科生数据
{
    FILE *ugFile;
    ugnode *ug,*uPtr=NULL;
    ugdata uTmp;
    int sex,count=-1;

    if((ugFile=fopen("ug.txt","r"))==NULL)
    {
        printf("无法打开本科生数据文件ug.txt或文件不存在！\n");
    	return -1;
    }

    do
    {
        if((fscanf(ugFile,"%d%s",&uTmp.num,uTmp.name))==EOF) break;
        fscanf(ugFile,"%d",&sex);
        uTmp.sex=(gand)sex;
        fscanf(ugFile,"%s%s",uTmp.speciaty,uTmp.classes);
        fscanf(ugFile,"%d%d%d%d%d%d",&uTmp.math,&uTmp.english,&uTmp.cLanguguage,&uTmp.totalScore,&uTmp.classRank,&uTmp.schoolRank);
        if(count==-1)  //读取最新学号
        {
            ugHead->data.num=uTmp.num;
            count++;
            continue;
        }
        ug=(ugnode *)malloc(sizeof(ugnode));
        memcpy(&ug->data,&uTmp,sizeof(ugdata)); //将临时变量uTmp的数据复制到链表新节点的数据中
        ug->next=NULL;
        if(count==0) ugHead->next=ug;
        else uPtr->next=ug;
        uPtr=ug;
        count++;
    } while (1);

    if(count==-1) printf("ug.txt打开成功，文件为空！\n");
    else printf("成功读取%d名本科生数据！\n",count);
    ugTail=uPtr;   //为方便添加学生，设计尾指针指向链表最后一个节点
    fclose(ugFile);
    return count;
}

int readFromUgdat()  //从dat读取本科生数据
{
    FILE *ugFile;
    ugnode *ug,*uPtr=NULL;
    ugdata uTmp;
    int count=-1;

    if((ugFile=fopen("ug.dat","rb"))==NULL)
    {
        printf("无法打开本科生数据文件ug.dat或文件不存在！\n");
    	return -1;
    }

    do
    {
        if(!(fread(&uTmp,sizeof(ugdata),1,ugFile))) break;
        if(count==-1)
        {
            ugHead->data.num=uTmp.num;
            count++;
            continue;
        }
        ug=(ugnode *)malloc(sizeof(ugnode));
        memcpy(&ug->data,&uTmp,sizeof(ugdata));
        ug->next=NULL;
        if(count==0) ugHead->next=ug;
        else uPtr->next=ug;
        uPtr=ug;
        count++;
    } while (1);

    if(count==-1) printf("ug.dat打开成功，文件为空！\n");
    else printf("成功读取%d名本科生数据！\n",count);
    ugTail=uPtr;
    fclose(ugFile);
    return count;
}

int readFromPgtxt()  //从txt文件读取研究生数据
{
    FILE *pgFile;
    pgnode *pg,*pPtr=NULL;
    pgdata pTmp;
    int sex,count=-1;

    if((pgFile=fopen("pg.txt","r"))==NULL)
    {
        printf("无法打开研究生数据文件pg.txt或文件不存在！\n");
    	return -1;
    }

    do
    {
        if((fscanf(pgFile,"%d%s",&pTmp.num,pTmp.name))==EOF) break;
        fscanf(pgFile,"%d",&sex);
        pTmp.sex=(gand)sex;
        fscanf(pgFile,"%s%s%s%s",pTmp.speciaty,pTmp.classes,pTmp.rschFields,pTmp.advisor);
        fscanf(pgFile,"%d%d%d%d%d",&pTmp.compCourse,&pTmp.thesis,&pTmp.totalScore,&pTmp.classRank,&pTmp.schoolRank);
        if(count==-1)
        {
            pgHead->data.num=pTmp.num;
            count++;
            continue;
        }
        pg=(pgnode *)malloc(sizeof(pgnode));
        memcpy(&pg->data,&pTmp,sizeof(pgdata));
        pg->next=NULL;
        if(count==0) pgHead->next=pg;
        else pPtr->next=pg;
        pPtr=pg;
        count++;
    } while (1);

    if(count==-1) printf("pg.txt打开成功，文件为空！\n");
    else printf("成功读取%d名研究生数据！\n",count);
    pgTail=pPtr;
    fclose(pgFile);
    return count;
}

int readFromPgdat()  //从dat文件读取研究生数据
{
    FILE *pgFile;
    pgnode *pg,*pPtr=NULL;
    pgdata pTmp;
    int count=-1;

    if((pgFile=fopen("pg.dat","rb"))==NULL)
    {
        printf("无法打开研究生数据文件pg.dat或文件不存在！\n");
    	return -1;
    }

    do
    {
        if(!(fread(&pTmp,sizeof(pgdata),1,pgFile))) break;
        if(count==-1)
        {
            pgHead->data.num=pTmp.num;
            count++;
            continue;
        }
        pg=(pgnode *)malloc(sizeof(pgnode));
        memcpy(&pg->data,&pTmp,sizeof(pgdata));
        pg->next=NULL;
        if(count==0) pgHead->next=pg;
        else pPtr->next=pg;
        pPtr=pg;
        count++;
    } while (1);

    if(count==-1) printf("pg.dat打开成功，文件为空！\n");
    else printf("成功读取%d名研究生数据！\n",count);
    pgTail=pPtr;
    fclose(pgFile);
    return count;
}

int saveToUgtxt(FILE *ugFile)  //将本科生数据保存到txt文件中
{
    ugnode *uPtr=ugHead;
    int sex,count=-1;
    if(ugFile==NULL)
    {
        if((ugFile=fopen("ug.txt","w"))==NULL)
        {
            printf("无法保存本科生数据到ug.txt！\n");
    	    return -1;
        }
    }

    while (uPtr!=NULL)  //从头结点开始保存
    {
        fprintf(ugFile,"%d %s ",uPtr->data.num,uPtr->data.name);
        sex=(int)uPtr->data.sex;
        fprintf(ugFile,"%d ",sex);
        fprintf(ugFile,"%s %s ",uPtr->data.speciaty,uPtr->data.classes);
        fprintf(ugFile,"%d %d %d %d %d %d\n",uPtr->data.math,uPtr->data.english,uPtr->data.cLanguguage,uPtr->data.totalScore,uPtr->data.classRank,uPtr->data.schoolRank);
        uPtr=uPtr->next;
        count++;
    }

    fclose(ugFile);
    if(count==0) printf("无本科生数据需要保存！\n");
    else printf("成功保存%d名本科生数据(文件类型：txt)！\n",count);
    return count;
}

int saveToUgdat(FILE *ugFile)  //将本科生数据保存到dat文件
{
    ugnode *uPtr=ugHead;
    int count=-1;
    if(ugFile==NULL)
    {
        if((ugFile=fopen("ug.dat","wb"))==NULL)
        {
            printf("无法保存本科生数据到ug.dat！\n");
    	    return -1;
        }
    }

    while (uPtr!=NULL)
    {
        fwrite(&uPtr->data,sizeof(ugdata),1,ugFile);
        uPtr=uPtr->next;
        count++;
    }

    fclose(ugFile);
    if(count==0) printf("无本科生数据需要保存！\n");
    else printf("成功保存%d名本科生数据(文件类型：dat)！\n",count);
    return count;
}

int saveToPgtxt(FILE *pgFile)  //将研究生数据保存到txt文件
{
    pgnode *pPtr=pgHead;
    int sex,count=-1;
    if(pgFile==NULL)
    {
        if((pgFile=fopen("pg.txt","w"))==NULL)
        {
            printf("无法保存研究生数据到pg.txt！\n");
    	    return -1;
        }
    }

    while (pPtr!=NULL)
    {
        fprintf(pgFile,"%d %s ",pPtr->data.num,pPtr->data.name);
        sex=(int)pPtr->data.sex;
        fprintf(pgFile,"%d ",sex);
        fprintf(pgFile,"%s %s %s %s ",pPtr->data.speciaty,pPtr->data.classes,pPtr->data.rschFields,pPtr->data.advisor);
        fprintf(pgFile,"%d %d %d %d %d\n",pPtr->data.compCourse,pPtr->data.thesis,pPtr->data.totalScore,pPtr->data.classRank,pPtr->data.schoolRank);
        pPtr=pPtr->next;
        count++;
    }

    fclose(pgFile);
    if(count==0) printf("无研究生数据需要保存！\n");
    else printf("成功保存%d名研究生数据(文件类型：txt)！\n",count);
    return count;
}

int saveToPgdat(FILE *pgFile)  //将研究生数据保存到dat文件
{
    pgnode *pPtr=pgHead;
    int count=-1;
    if(pgFile==NULL)
    {
        if((pgFile=fopen("pg.dat","wb"))==NULL)
        {
            printf("无法保存研究生数据到pg.dat！\n");
    	    return -1;
        }
    }

    while (pPtr!=NULL)
    {
        fwrite(&pPtr->data,sizeof(pgdata),1,pgFile);
        pPtr=pPtr->next;
        count++;
    }

    fclose(pgFile);
    if(count==0) printf("无研究生数据需要保存！\n");
    else printf("成功保存%d名研究生数据(文件类型：dat)！\n",count);
    return count;
}

void listDestroy()  //销毁两条链表
{
    ugnode *uTmp,*uPtr;
    pgnode *pTmp,*pPtr;
    uPtr=ugHead;
    pPtr=pgHead;
    
    while (uPtr!=NULL)
    {
        uTmp=uPtr;
        uPtr=uPtr->next;
        free(uTmp);
    }
    while (pPtr!=NULL)
    {
        pTmp=pPtr;
        pPtr=pPtr->next;
        free(pTmp);
    }
    ugHead=NULL;
    pgHead=NULL;
}

int saveToFile() //另存为
{
    int stuType,fileType,pathLen,nameLen,i,j;
    FILE *fp;
    char filePath[200];
    char fileName[25];
    char txt[]=".txt";
    char dat[]=".dat";
    printf("----------------------------------------------\n");
    printf("                 保存学生信息                 \n");
    printf("     1---本科生                 2---研究生     \n");
    printf("                    3---退出                  \n");
    printf("----------------------------------------------\n\n");
    printf("请选择菜单编号：");
    do
    {
        enterNUM(&stuType);
        if (stuType!=1 && stuType!=2 && stuType!=3) printf("错误！请输入正确的数字：");
    } while (stuType!=1 && stuType!=2 && stuType!=3);
    system("cls");
    if(stuType==3)
    {
        printf("谢谢使用！");
        system("pause");
        system("cls");
        return 0;
    }
    printf("请输入保存路径（请输入正确的路径，否则会保存失败或保存到默认目录）：");
    enterStr(filePath,150);
    printf("请输入文件名：");
    enterStr(fileName,25);
    printf("请选择保存类型 1.txt 2.dat：");
    do
    {
        enterNUM(&fileType);
        if (fileType!=1 && fileType!=2) printf("错误！请输入正确的数字：");
    } while (fileType!=1 && fileType!=2);
    for(i=0;filePath[i]!='\0';i++)
    {
        if(filePath[i]=='\\')
        {
            pathLen=strlen(filePath);
            for(j=pathLen+1;j>i+1;j--)
                filePath[j]=filePath[j-1];
            i++;
            filePath[i]='\\';
        }
    }
    pathLen=strlen(filePath);
    if(filePath[pathLen-1]!='\\')
    {
        for(i=0;i<2;i++)
            filePath[pathLen+i]='\\';
        filePath[pathLen+2]='\0';
    }
    pathLen=strlen(filePath);
    nameLen=strlen(fileName);
    for(i=0;i<nameLen;i++)
        filePath[pathLen+i]=fileName[i];
    if(fileType==1)
    {
        for(i=0;i<5;i++)
            filePath[pathLen+nameLen+i]=txt[i];
        if((fp=fopen(filePath,"w"))==NULL)
        {
            printf("保存失败，请检查保存路径是否正确！");
            system("pause");
            system("cls");
            return 1;
        }
        if(stuType==1) saveToUgtxt(fp);
        else saveToPgtxt(fp);
    }
    else
    {
        for(i=0;i<5;i++)
            filePath[pathLen+nameLen+i]=dat[i];
        if((fp=fopen(filePath,"wb"))==NULL)
        {
            printf("保存失败，请检查保存路径是否正确！");
            system("pause");
            system("cls");
            return 1;
        }
        if(stuType==1) saveToUgdat(fp);
        else saveToPgdat(fp);
    }
    system("pause");
    system("cls");
    return 1;
}