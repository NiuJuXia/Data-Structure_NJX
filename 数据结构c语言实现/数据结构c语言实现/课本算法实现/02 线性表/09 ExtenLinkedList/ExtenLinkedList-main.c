/************************************
 *                                    *
 * 文件夹: ▲02 线性表              *
 *                                     *
 * 内  容: 扩展的单链表相关函数测试 *
 *                                  *
 ************************************/

#include <stdio.h>
#include "ExtenLinkedList.h"                             //**▲02 线性表**//
/* 函数原型 */
//Status CmpGreater(LElemType_E e, LElemType_E data);        //判断data是否大于e //若data>e，返回TRUE
//void PrintElem(LElemType_E e);
//
//int main(){
//
//        ELinkList L;
//        Link p, q, s;
//        PositionPtr r;
//        int i;
//        LElemType_E e;
//
//    printf("▼3\n▲函数 InitList_E 测试...\n");            //3.函数InitList_E测试
//        {
//            printf("初始化扩展的单链表 L ...\n");
//            InitList_E(&L);
//            printf("\n");
//        }
//
//    printf("▼23\n▲函数 ListInsert_L_E 测试...\n");    //23.函数ListInsert_L_E测试
//    {
//        for(i=1; i<=6; i++)
//        {
//            printf("在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2*i);
//            ListInsert_L_E(&L, i, 2*i);
//        }
////        printf("%d\n",L.head->next->data); //拥有头节点
//        printf("\n");
//    }
//
//    printf("▼24\n▲函数 ListDelete_E 测试...\n");        //24.函数ListDelete_L_E测试
//    {
//        ListDelete_L_E(&L, 6, &e);
//        printf("删除 L 中第 6 个元素 \"%d\" ...\n", e);
//        printf(" L 中的元素为：L = ");
//        ListTraverse_E(L, PrintElem);
//        printf("\n\n");
//    }
//
//    printf("▼1\n▲函数 MakeNode_E 测试...\n");            //1.函数MakeNode_E测试
//        {
//            printf("创建结点 p ...\n");
//            MakeNode_E(&p, 101);
//            printf("创建结点 q ...\n");
//            MakeNode_E(&q, 202);
//            printf("\n");
//        }
//
//    printf("▼8\n▲函数 Append_E 测试...\n");            //8.函数Append_E测试
//    {
//        printf("将 q 结点插在 L 最后一个结点之后...\n");
//        Append_E(&L, q);
//        printf(" L 中的元素为：L = ");
//        ListTraverse_E(L, PrintElem);
//        printf("\n\n");
//    }
//
//    printf("▼9\n▲函数 Remove_E 测试...\n");            //9.函数Remove_E测试
//    {
//        printf("删除 L 中最后一个结点，用 p 接收删除的结点...\n");
//        Remove_E(&L, &p);
//        printf(" L 中的元素为：L = ");
//        ListTraverse_E(L, PrintElem);
//        printf("\n\n");
//    }
//
//    printf("▼10\n▲函数 InsBefore_E 测试...\n");        //10.函数InsBefore_E测试
//        {
//            MakeNode_E(&q, 202);
//            Append_E(&L, q);
//            printf("创建值为 404 的结点 s ...\n");
//            MakeNode_E(&s, 404);
//            printf("将结点 s 插入到尾结点 q 之前...\n");
//            InsBefore_E(&L, &q, s);
//            printf("当前 L 的值为：L = ");
//            ListTraverse_E(L, PrintElem);
//            printf("\n\n");
//        }
//
//    printf("▼11\n▲函数 InsAfter_E 测试...\n");        //11.函数InsAfter_E测试
//    {
//        printf("创建值为 505 的结点 s ...\n");
//        MakeNode_E(&s, 505);
//        printf("将结点 s 插入到结点 q 之后...\n");
//        InsAfter_E(&L, &q, s);
//        printf(" L 中的元素为：L = ");
//        ListTraverse_E(L, PrintElem);
//        printf("\n\n");
//    }
//    return 0;
//}
//
//Status CmpGreater(LElemType_E e, LElemType_E data)
//{
//    return data>e ? TRUE : FALSE;
//}
//
//void PrintElem(LElemType_E e)
//{
//    printf("%d ", e);
//}
