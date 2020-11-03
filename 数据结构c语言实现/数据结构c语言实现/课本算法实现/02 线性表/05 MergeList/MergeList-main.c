/************************************
 *                                    *
 * 文件夹: ▲02 线性表\05 MergeList *
 *                                     *
 * 内  容: 单链表归并相关函数测试   *
 *                                  *
 ************************************/

#include <stdio.h>

#include "MergeList.h"                    //**▲02 线性表**//
    
void PrintElem(LElemType_L e);            //测试函数，打印整型
    
//int main(int argc, char **argv)
//{
//
//    LinkList La,Lb,Lc;
//    LElemType_L a = 1;
//    LElemType_L b = 2;
//    LElemType_L c = 3;
//    LElemType_L d = 4;
//    InitList_L(&La);
//    InitList_L(&Lb);
//    InitList_L(&Lc);
//    ListInsert_L(La,1,a);
//    ListInsert_L(La,2,c);
//    ListInsert_L(Lb,1,b);
//    ListInsert_L(Lb,2,d);
//    printf("La = ");
//    ListTraverse_L(La, PrintElem);
//    printf("\n");
//    printf("Lb = ");
//    ListTraverse_L(Lb, PrintElem);
//    printf("\n\n");
//
//
//    MergeList_L(La, &Lb, &Lc);
//    printf("合并La和Lb为Lc = ");
//    ListTraverse_L(Lc, PrintElem);
//    printf("\n\n");
//
//
//    return 0;
//}
//
//void PrintElem(LElemType_L e)
//{
//    printf("%d ", e);
//}
