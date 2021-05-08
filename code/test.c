#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "model.h"
#include "fileOperate.h"
#include "inforManage.h"
#include "scoreManage.h"
#include "tool.h"
/* 这里包含你要测试的头文件 */

int main()
{
    listInitiate();
    readFromUgtxt();
    readFromPgtxt();
    /***************************/



    saveToFile();
    /* 请在这里调用需要测试的函数*/




    /**************************/
    saveToUgtxt(NULL);
    saveToUgdat(NULL);
    saveToPgtxt(NULL);
    saveToPgdat(NULL);
    listDestroy(NULL);
    system("pause");
    system("cls");
}