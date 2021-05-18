#ifndef TOOL_H
#define TOOL_H
#include "model.h"

void enterNum(int *num);
void enterStr(char *str, int num);
void outputUgInfor(ugnode *pPtr);
void outputPgInfor(pgnode *pPtr);
void outputUgScore(ugnode *uPtr);
void outputPgScore(pgnode *pPtr);
void printUList(ugnode *head, ugnode *end);
void printPList(pgnode *head, pgnode *end);
void printUHead();
void printPHead();
void printOneUg(ugnode *p);
void printOnePg(pgnode *q);
ugnode *copyUGList();
pgnode *copyPGList();
ugnode *setUClassList(char classTmp[]);
pgnode *setPClassList(char classTmp[]);
void listDestroy(ugnode **u, pgnode **p);
void outputAllClasses();
void about();

#endif