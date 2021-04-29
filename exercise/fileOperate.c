#define _CRT_SECURE_NO_WARNINGS

#include "fileOperate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"

int listInitiate()
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
        free(pgHead);
        pgHead=NULL;
        printf("不能成功分配研究生链表存储块！\n");
        return -1;
    }
    (pgHead)->next=NULL;

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

int readFromUgtxt()
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
    if(count==-1) printf("ug.txt打开成功，文件为空！\n");
    else printf("成功读取%d名本科生数据！\n",count);
    ugTail=uPtr;
    fclose(ugFile);
    return count;
}

int readFromUgdat()
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

int readFromPgtxt()
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

int readFromPgdat()
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

int saveToUgtxt()
{
    FILE *ugFile;
    ugnode *uPtr=ugHead;
    int sex,count=-1;

    if((ugFile=fopen("ug.txt","w"))==NULL)
    {
        printf("无法保存本科生数据到ug.txt！\n");
    	return -1;
    }
    while (uPtr!=NULL)
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
    else printf("成功保存%d名本科生数据到ug.txt！\n",count);
    return count;
}

int saveToUgdat()
{
    FILE *ugFile;
    ugnode *uPtr=ugHead;
    int count=-1;

    if((ugFile=fopen("ug.dat","wb"))==NULL)
    {
        printf("无法保存本科生数据到ug.dat！\n");
    	return -1;
    }
    while (uPtr!=NULL)
    {
        fwrite(&uPtr->data,sizeof(ugdata),1,ugFile);
        uPtr=uPtr->next;
        count++;
    }
    fclose(ugFile);
    if(count==0) printf("无本科生数据需要保存！\n");
    else printf("成功保存%d名本科生数据到ug.dat！\n",count);
    return count;
}

int saveToPgtxt()
{
    FILE *pgFile;
    pgnode *pPtr=pgHead;
    int sex,count=-1;

    if((pgFile=fopen("pg.txt","w"))==NULL)
    {
        printf("无法保存研究生数据到pg.txt！\n");
    	return -1;
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
    else printf("成功保存%d名研究生数据到pg.txt！\n",count);
    return count;
}

int saveToPgdat()
{
    FILE *pgFile;
    pgnode *pPtr=pgHead;
    int count=-1;

    if((pgFile=fopen("pg.dat","wb"))==NULL)
    {
        printf("无法保存研究生数据到pg.dat！\n");
    	return -1;
    }
    while (pPtr!=NULL)
    {
        fwrite(&pPtr->data,sizeof(pgdata),1,pgFile);
        pPtr=pPtr->next;
        count++;
    }
    fclose(pgFile);
    if(count==0) printf("无研究生数据需要保存！\n");
    else printf("成功保存%d名研究生数据到pg.dat！\n",count);
    return count;
}

void listDestroy()
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