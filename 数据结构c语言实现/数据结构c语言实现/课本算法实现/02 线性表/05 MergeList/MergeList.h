
/************************************
 *                                    *
 * 文件夹: ▲02 线性表\05 MergeList *
 *                                     *
 * 文件名: MergeList.h              *
 *                                     *
 * 内  容: 单链表归并相关操作列表   *
 *                                  *
 ************************************/

#ifndef MergeList_h
#define MergeList_h

#include <stdio.h>
#include <stdlib.h>
#include "../04 SinglyLinkedList/SinglyLinkedList.h"    //**▲02 线性表**//

/* 单链表归并函数列表 */
void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc);
/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法2.12：C=A+B，且保持元素相对位置不变。   ┃
┃    Lc利用La的头结点，Lb中结点均插入新链表Lc中。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━*/

#endif /* MergeList_h */
