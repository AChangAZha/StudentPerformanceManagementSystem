#ifndef TOOL_H
#define TOOL_H
#include "model.h"

void enterNum(int *num);
void enterStr(char *str, int num);
void outputUgInfor(ugnode *pPtr);
void outputPgInfor(pgnode *pPtr);
void outputUgScore(ugnode *uPtr);
void outputPgScore(pgnode *pPtr);
void printUList(ugnode *head);
void printPList(pgnode *head);
void about();

#endif