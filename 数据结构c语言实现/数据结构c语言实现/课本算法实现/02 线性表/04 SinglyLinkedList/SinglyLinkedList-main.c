/*******************************************
 *                                         *
 * 文件夹: ▲02 线性表\04 SinglyLinkedList *
 *                                         *
 * 内  容: 单链表相关函数测试              *
 *                                         *
 *******************************************/

//#include <stdio.h>
//#include "SinglyLinkedList.h"                         //**▲02 线性表**//
//
///* 函数原型 */
//Status CmpGreater(LElemType_L e, LElemType_L data);    //判断data是否大于e //若data大于e，返回TRUE
//void PrintElem(LElemType_L e);                        //测试函数，打印整型
//
//
//int main(int argc, char **argv){
//    
//    LinkList L;//指向头节点的指针
//    int i;
//    LElemType_L e;
//    
//    printf("▼1\n▲函数 InitList_L 测试...\n");            //1.函数InitList_L测试
//        {
//            printf("初始化单链表 L ...\n");
//            InitList_L(&L);
//            printf("\n");
//        }
//    
//    printf("▼4\n▲函数 ListEmpty_L 测试...\n");        //4.函数ListEmpty_L测试
//        {
//            ListEmpty_L(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
//            printf("\n");
//        }
//    
//    printf("▼10\n▲函数 ListInsert_L 测试...\n");        //10.函数ListInsert_L测试
//        {
//            for(i=1; i<=6; i++)
//            {
//                printf("在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2*i);
//                ListInsert_L(L, i, 2*i);
//            }
//            printf("\n");
//        }
//    
//    printf("▼12\n▲函数 ListTraverse_L 测试...\n");    //12.函数ListTraverse_L测试
//        {
//            printf(" L 中的元素为：L = ");
//            ListTraverse_L(L, PrintElem);
//            printf("\n\n");
//        }
//    
//    printf("▼5\n▲函数 ListLength_L 测试...\n");        //5.函数ListLength_L测试
//        {
//            printf(" L 的长度为 %d \n", ListLength_L(L));
//            printf("\n");
//        }
//    
//    printf("▼11\n▲函数 ListDelete_L 测试...\n");        //11.函数ListDelete_L测试
//        {
//            ListDelete_L(L, 6, &e);
//            printf("删除 L 中第 6 个元素 \"%d\" ...\n", e);
//            printf(" L 中的元素为：L = ");
//            ListTraverse_L(L, PrintElem);
//            printf("\n\n");
//        }
//    
//    printf("▼6\n▲函数 GetElem_L 测试...\n");            //6.函数GetElem_L测试
//        {
//            GetElem_L(L, 4, &e);
//            printf(" L 中第 4 个位置的元素为 \"%d\" \n", e);
//            printf("\n");
//        }
//    
//    printf("▼7\n▲函数 LocateElem_L 测试...\n");        //7.函数LocateElem_L测试
//        {
//            i = LocateElem_L(L, 7, CmpGreater);
//            printf(" L 中第一个元素值大于 \"7\" 的元素的位置为 %d \n", i);
//            printf("\n");
//        }
//    
//    printf("▼8\n▲函数 PriorElem_L 测试...\n");        //8.函数PriorElem_L测试
//        {
//            PriorElem_L(L, 6, &e);
//            printf("元素 \"6\" 的前驱为 \"%d\" \n", e);
//            printf("\n");
//        }
//    
//    printf("▼9\n▲函数 NextElem_L 测试...\n");            //9.函数NextElem_L测试
//        {
//            NextElem_L(L, 6, &e);
//            printf("元素 \"6\" 的后继为 \"%d\" \n", e);
//            printf("\n");
//        }
//    
//    printf("▼14\n▲函数 CreateList_TL 测试...\n");        //14.函数CreateList_TL测试
//        {
//            FILE *fp;
//            LinkList L;
//            printf("尾插法建立单链表 L = ");
//            fp = fopen("TestData_TL.txt", "r");                //文件指针，指向数据源
//            CreateList_HL(fp, &L, 5);
//            fclose(fp);
//            ListTraverse_L(L, PrintElem);
//            printf("\n\n");
//        }
//    
//    printf("▼14\n▲函数 CreateList_TL 测试...\n");        //14.函数CreateList_TL测试
//        {
//            FILE *fp;
//            LinkList L;
//            printf("尾插法建立单链表 L = ");
//            fp = fopen("TestData_TL.txt", "r");                //文件指针，指向数据源
//            CreateList_TL(fp, &L, 5);
//            fclose(fp);
//            ListTraverse_L(L, PrintElem);
//            printf("\n\n");
//        }
//        
//        return 0;
//}
//
//void PrintElem(LElemType_L e)
//{
//    printf("%d ", e);
//}
//
//Status CmpGreater(LElemType_L e, LElemType_L data)
//{
//    return data>e ? TRUE : FALSE;
//}
