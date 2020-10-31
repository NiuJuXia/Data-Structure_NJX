//
//  SequenceList.c
//  数据结构c语言实现
//
//  Created by 宋宋梦醒 on 2020/10/25.
//

#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "SequenceList.h"     //线性表





//算法区

/*════╗
║算法2.3 ║
╚════*/

Status InitList_Sq(SqList *L){
    
    L->elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
    if(!L->elem)exit(OVERFLOW);       //分配内存失败
    L->length = 0;                    //初始化顺序表长度为0
    L->listsize = LIST_INIT_SIZE;    //顺序表初始内存分配量
    
    return OK;          //初始化成功
}

Status ListEmpty_Sq(SqList L){
    return L.length == 0 ? TRUE :FALSE;
}

/*════╗
║算法2.4 ║
╚════*/
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e){
    
    LElemType_Sq *p, *q;
    
    LElemType_Sq *newbase;
    
    if(i<1 || i>L->length+1) return ERROR; //i不符合
    
    if(L->length >= L->listsize){//若存储空间已满，需开辟更大的空间
        newbase = (LElemType_Sq*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(LElemType_Sq));
        if(!newbase)exit(OVERFLOW);
        L->elem = newbase;
        L->listsize +=LISTINCREMENT;
    }
    
    q = &L->elem[i-1];  //q为i元素插入的位置(指针)
    
    for(p=&L->elem[L->length-1]; p>=q; p--){//malloc申请的内存空间可以使用数组的[]
        *(p+1) = *p;     //*指针等于一个变量 例如int a = 1; a就是一个变量，也是一个指向真实值的指针
                         //它既可以在赋值的左边（改变这个指针变量指向的值），也可以在赋值的右边（将指针变量指向的值赋给别人）
    }
    
    *q = e;
    L->length++;
    
    return OK;
}

Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq)){//接受函数原型
    
    int i;
    for (i=0; i<L.length; i++) {
        Visit(L.elem[i]);
    }
    return OK;
}

int ListLength_Sq(SqList L)
{
    return L.length;
}

/*════╗
║算法2.5 ║
╚════*/
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e){
    
    LElemType_Sq *p,*q;
    
    if(i<1 || i>L->length) return ERROR;
    
    p = &L->elem[L->length-1];    //表尾元素的位置
    
    q = &L->elem[i-1];   //删除元素位置
    
    *e = *q;
    
    for (++q; q<p; q++) {//小技巧
        *(q-1) = *q;
    }
    
    L->length--;
    
    return OK;
}

Status GetElem_Sq(SqList L, int i, LElemType_Sq *e)
{
    if(i<1 || i>L.length)
        return ERROR;                    //i值不合法
    else
        *e = L.elem[i-1];

    return OK;
}

/*════╗
║算法2.6 ║
╚════*/
int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq))
{
    int i = 1;                            //i的初值为第一个元素的位序
    
    while(i<=L.length && !Compare(e, L.elem[i-1]))
        ++i;

    if(i<=L.length)
        return i;
    else
        return 0;
}

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e){
    
    int i = 0;
    if(L.elem[0] != cur_e){
        while (i<L.length && L.elem[i]!=cur_e) {//while小技巧
            ++i;
        }
        if(i<L.length)
                {
                    *pre_e = L.elem[i-1];
                    return OK;
                }
    }
    return ERROR;
}

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e)
{
    int i = 0;
    
    while(i<L.length && L.elem[i]!=cur_e)
        ++i;

    if(i<L.length-1)                    //最后一个结点无后继
    {
        *next_e = L.elem[i+1];
        return OK;
    }

    return ERROR;
}

void ClearList_Sq(SqList *L)
{
    int i;
    for (i=0 ; i<L->length; i++) {
        L->elem[i] = 0;
    }
    L->length = 0;
}

void DestroyList_Sq(SqList *L){
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
}



#endif
