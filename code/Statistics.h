#ifndef STATISTICS_H
#define STATISTICS_H
#include "model.h"

ugnode *copyUGList();
pgnode *copyPGList();
void countugAvg();
void countpgAvg();
ugnode *setUGClassList(ugnode *newUgHead);
pgnode *setPGClassList(pgnode *newPgHead);
void choseClassCourse();
void staGrade(int grade[], int score);

#endif