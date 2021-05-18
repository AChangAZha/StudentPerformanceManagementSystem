#ifndef RESULTSTATISTICS_H
#define RESULTSTATISTICS_H
#include "model.h"

ugnode *copyUGList();
pgnode *copyPGList();
void countUgAvgMenu();
void countPgAvgMenu();
void countUgAvg(ugnode *newUgHead, int item);
void countPgAvg(pgnode *newPgHead, int item);
int choseClassCourse();
void staGrade(int grade[], int score);

#endif