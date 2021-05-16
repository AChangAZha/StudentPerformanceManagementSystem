#ifndef SORT_H
#define SORT_H

void scoreSort();
void recoverUList();
void recoverPList();
ugnode *setUClassList(char classTmp[]);
pgnode *setPClassList(char classTmp[]);
void newListDestroy(ugnode *newUgListHead, pgnode *newPgListHead);

#endif