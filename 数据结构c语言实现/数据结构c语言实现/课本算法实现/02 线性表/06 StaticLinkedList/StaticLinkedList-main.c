//
//  StaticLinkedList-main.c
//  数据结构c语言实现
//
//  Created by 宋宋梦醒 on 2020/11/5.
//

#include <stdio.h>
#include "StaticLinkedList.h"

void PrintElem(LElemType_S e);        //测试函数，打印整型


int main(){
    
    component H;
    int i;
    int e;
    {
        InitList_SL(H);
        for(i=1; i<=3; i++)
                {
                    printf("在 H 第 %d 个位置插入\"%d\" ...\n", i, i);
                    ListInsert_SL(H, i, i);
                }
                printf("\n");
        ListInsert_SL(H, 3, 4);
                    
        printf("在 H 第 %d 个的游标是\"%d\" ...\n", 4,H[4].cur );
        printf("在 H 第 %d 个的游标是\"%d\" ...\n", 5,H[5].cur );//如果忘记了，画一张图
                
                printf("\n");
    }
    
    {
    printf("▼7\n▲函数ListEmpty_SL测试...\n");                //7.函数ListEmpty_SL测试
        ListEmpty_SL(H) ? printf(" H 为空！！\n") : printf(" H 不为空！\n");
        printf("\n");
    }
    
    printf("▼9\n▲函数GetElem_SL测试...\n");                //9.函数GetElem_SL测试
        {
            GetSlElem_SL(H, 4, &e);
            printf(" H 中第 4 个位置的元素为 \"%d\" \n", e);
            printf("\n");
        }
    
    printf("▼3、14\n▲函数Free_SL、ListDelete_SL测试...\n");//3、14.函数Free_SL、ListDelete_SL测试
        {
            ListDelete_SLW(H, 3, &e);
            printf("删除 H 中第 3 个元素 \"%d\" ，用Free_SL释放空间...\n", e);
            printf("\n\n");
        }
    
    printf("▼15\n▲函数ListTraverse_SL测试...\n");            //15.函数ListTraverse_SL测试
    {
        printf(" H 中的元素为：H = ");
        ListTraverse_SL(H, PrintElem);
        printf("\n\n");
    }
    
    printf("▼8\n▲函数ListLength_SL测试...\n");            //8.函数ListLength_SL测试
        {
            printf(" H 的长度为 %d \n", ListLength_SL(H));
            printf("\n");
        }
    
    printf("▼10\n▲函数LocateElem_SL测试...\n");            //10.函数LocateElem_SL测试
        {
            printf("元素 \"1\" 在 H 中的位序为 %d \n", LocateElem_SL(H, 1));
            printf("\n");
        }
    
    printf("▼11\n▲函数PrrriorElem_SL测试...\n");            //11.函数PriorElem_SL测试
        {
            PrrriorElem_SL(H, 2, &e);
            printf("元素 \"2\" 的前驱为 \"%d\" \n", e);
            printf("\n");
        }
    
    printf("▼12\n▲函数NeeextElem_SL测试...\n");                //12.函数NextElem_SL测试
    {
        NeeextElem_SL(H, 2, &e);
        printf("元素 \"2\" 的后继为 \"%d\" \n", e);
        printf("\n");
    }
    
    printf("▼5\n▲函数ClearList_SL测试...\n");                //5.函数ClearList_SL测试
        {
            printf("清空 H 前：");
            ListEmpty_SL(H) ? printf(" H 为空！！\n") : printf(" H 不为空！\n");
            ClearList_SL(H);
            printf("清空 H 后：");
            ListEmpty_SL(H) ? printf(" H 为空！！\n") : printf(" H 不为空！\n");
            printf("\n");
        }
    
    printf("▼6\n▲函数DestroyList_SL测试...\n");            //6.函数DestroyList_SL测试
        {
            DestroyList_SL(H);
            printf("销毁 H 后：\n");
            if(H == NULL) printf("销毁 成功：");
        }
    return 0;
}

void PrintElem(LElemType_S e)
{
    printf("%d ", e);
}
