//
//  Deffrence-main.c
//  数据结构c语言实现
//
//  Created by 宋宋梦醒 on 2020/11/13.
//

#include <stdio.h>
#include "Diffrence.h"

void PrintElem(LElemType_S e);        //测试函数，打印整型

//int main(){
//    int i=0;
//    int A[30] = {1,2,3,4,5};
//    int B[30] = {2,4,6};
//    int len_A = 5;
//    int len_B = 3;
//    component H;
//    InitList_SL(H);
//    printf("A = ");
//        for(i=0; i<len_A; i++)
//            PrintElem(A[i]);
//        printf("\n");
//        printf("B = ");
//        for(i=0; i<len_B; i++)
//            PrintElem(B[i]);
//        printf("\n\n");
//    
//    printf("S = (A-B)∪(B-A) = ");
//    difference(H, A, len_A, B, len_B);
//    ListTraverse_SL(H, PrintElem);
//    printf("\n\n");
//
//    return 0;
//}
//
//void PrintElem(LElemType_S e)
//{
//    printf("%d ", e);
//}
