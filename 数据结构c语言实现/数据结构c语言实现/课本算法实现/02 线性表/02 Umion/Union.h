#ifndef Union_h
#define Union_h

#include <stdio.h>

#include "../01 SequenceList/SequenceList.h"    //**▲02 线性表**//

/* 并集函数列表 */
void Union(SqList *La, SqList Lb);
/*━━━━━━━━━━━┓
┃(01)算法2.1：A=A∪B。 ┃
┗━━━━━━━━━━━*/

Status equal(LElemType_Sq e1, LElemType_Sq e2);
/*━━━━━━━━━━━━┓
┃(02)判断两元素是否相等。┃
┗━━━━━━━━━━━━*/

#endif
