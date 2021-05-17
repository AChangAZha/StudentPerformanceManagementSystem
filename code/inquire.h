#ifndef INQUIRE_H
#define INQUIRE_H

ugnode *serchUg(int num);
pgnode *serchPg(int num);
void showAllUg();
void showAllPg();
void findInfor();
void stuClaInfor();
int serchUgName(char nameTemp[]);
int serchPgName(char nameTemp[]);
void failStu();
void unFailStu(ugnode *p);
void pnFailStu(pgnode *q);
#endif