#ifndef FILEOPERATE_H
#define FILEOPERATE_H

int listInitiate();
int readFromUgtxt();
int readFromUgdat();
int readFromPgtxt();
int readFromPgdat();
int saveToUgtxt(FILE *ugFile);
int saveToUgdat(FILE *ugFile);
int saveToPgtxt(FILE *pgFile);
int saveToPgdat(FILE *pgFile);
void listDestroy();
int saveToFile();

#endif