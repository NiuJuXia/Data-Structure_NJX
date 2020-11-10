/********************************
 *                                *
 * 文件夹: ▲02 线性表          *
 *                                 *
 * 文件名: StaticLinkedList.h   *
 *                                 *
 * 内  容: 静态链表相关操作列表 *
 *                              *
 ********************************/

/*━━━━━━━━━━━━━━━━━━━━━━━━┓
★备注：                                          ┃
★1.默认备用链表的起点为数组第一个元素┃
★2.模拟系统动态申请空间过程。                    ┃
★3.默认静态链表的起始位置为数组的第二个元素。    ┃
 ★4. 静态链表和备用链表的最后一个元素的游标为0.     ┃

 ┗━━━━━━━━━━━━━━━━━━━━━━━━*/

#ifndef StaticLinkedList_h
#define StaticLinkedList_h

#include <stdio.h>
#include <stdlib.h>                        //提供malloc、realloc、free、exit原型
#include "../../01 绪论/Status.h"        //**▲01 绪论**//

/* 宏定义 */
#define MAXSIZE 1000                    //静态链表的最大长度

typedef int LElemType_S;

typedef struct {
    LElemType_S data;
    int cur;
} component[MAXSIZE];

void InitSpace_SL(component);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法2.14：生成备用链表。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

int Malloc_SL(component);
/*━━━━━━━━━━━━━━━━━┓
┃(02)算法2.15：为插入数据申请空间。┃
┗━━━━━━━━━━━━━━━━━*/

void Free_SL(component, int );
/*━━━━━━━━━━━━━━━━━━━━┓
┃(03)算法2.16：将下标为k的空闲结点回收。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

Status InitList_SL(component);
/*━━━━━━━━━━━━━━━━┓
┃(04)初始化静态链表，建立头结点。┃
┗━━━━━━━━━━━━━━━━*/

Status ClearList_SL(component);
/*━━━━━┓
┃(05)置空。┃
┗━━━━━*/

void DestroyList_SL(component);
/*━━━━━┓
┃(06)销毁。┃
┗━━━━━*/

Status ListEmpty_SL(component);
/*━━━━━┓
┃(07)判空。┃
┗━━━━━*/

int ListLength_SL(component);
/*━━━━━┓
┃(08)求长。┃
┗━━━━━*/

Status GetSlElem_SL(component, int i, LElemType_S *e);
/*━━━━━┓
┃(09)取值。┃
┗━━━━━*/

int LocateElem_SL(component, LElemType_S e);
/*━━━━━━━━━━━━━━━━┓
┃(10)算法2.13：返回元素e的位序。 ┃
┗━━━━━━━━━━━━━━━━*/

Status PrrriorElem_SL(component array, LElemType_S cur_e, LElemType_S *pre_e);
/*━━━━━┓
┃(11)前驱。┃
┗━━━━━*/

Status NeeextElem_SL(component array, LElemType_S cur_e, LElemType_S *next_e);
/*━━━━━┓
┃(12)后继。┃
┗━━━━━*/

Status ListInsert_SL(component, int , LElemType_S );
/*━━━━━┓
┃(13)插入。┃
┗━━━━━*/

Status ListDelete_SLW(component array, int  i, LElemType_S *e);
/*━━━━━┓
┃(14)删除。┃
┗━━━━━*/

Status ListTraverse_SL(component, void(Visit)(LElemType_S));
/*━━━━━┓
┃(15)访问。┃
┗━━━━━*/



#endif /* StaticLinkedList_h */
