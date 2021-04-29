#ifndef MODEL_H
#define MODEL_H

typedef enum Gander{male,female} gand; /* 枚举类型：性别 */
typedef struct UGdata   /* 本科生数据 */
{
    int num;             /* 学号 */
    char name[12];       /* 姓名 */
    gand sex;            /* 性别 */
    char speciaty[20];   /* 专业 */
    char classes[20];    /* 班级 */
    int math;            /* 高数 */
    int english;         /* 英语 */
    int cLanguguage;     /* C语言 */
    int totalScore;      /* 总成绩 */
    int classRank;       /* 班级排名 */
    int schoolRank;      /* 校级排名 */
}ugdata;
typedef struct PGdata   /* 研究生数据 */
{
    int num;             /* 学号 */
    char name[12];       /* 姓名 */
    gand sex;            /* 性别 */
    char speciaty[20];   /* 专业 */
    char classes[20];    /* 班级 */
    char rschFields[20]; /* 研究方向 */
    char advisor[12];    /* 导师 */
    int compCourse;      /* 课程综合成绩 */
    int thesis;          /* 论文成绩 */
    int totalScore;      /* 总成绩 */
    int classRank;       /* 班级排名 */
    int schoolRank;      /* 校级排名 */
}pgdata;
typedef struct UGnode    /* 本科生链表 */
{
    ugdata data;         /* 本科生数据 */
    struct UGnode *next; /* 指向下一个节点的指针 */
}ugnode;
typedef struct PGnode    /* 研究生链表 */
{
    pgdata data;         /* 研究生数据 */
    struct PGnode *next; /* 指向下一个节点的指针 */
}pgnode;

extern ugnode *ugHead;   /* 本科生头结点指针 */
extern pgnode *pgHead;   /* 研究生头结点指针 */
extern ugnode *ugTail;   /* 本科生尾指针 */
extern pgnode *pgTail;   /* 研究生尾指针 */

#endif