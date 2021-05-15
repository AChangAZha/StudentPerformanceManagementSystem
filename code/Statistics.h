#ifndef STATISTICS_H
#define STATISTICS_H
#include "model.h"

ugnode *copyUGList();
pgnode *copyPGList();
void countugAvg();
void countpgAvg();
int choseClassCourse();
void staGrade(int grade[], int score);
void outputAllClasses();

#endif