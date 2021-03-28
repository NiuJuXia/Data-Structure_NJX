//
//  ExtenLinkedList.c
//  数据结构c语言实现
//
//  Created by 宋宋梦醒 on 2020/11/16.
//

#include "ExtenLinkedList.h"

Status InitList_E(ELinkList *L){
    
    Link p = (Link)malloc(sizeof(Link));
    p->next = NULL;
    
    (*L).head = L->tail = p;  //两种写法等价
    L->len = 0;
    
    return OK;
}

Status LocatePos_E(ELinkList L, int i, Link *p){
    
        int count = 0;
        *p = L.head;                        //i=0时返回指向头节点的指针
        
        if(i<0 || i>L.len)
            return ERROR;

        while(count<i)
        {
            count++;
            *p = (*p)->next;
        }
        
        return OK;
}

Status MakeNode_E(Link *p, LElemType_E e)
{
    *p = (Link)malloc(sizeof(ELNode));        //申请空间
    if(!(*p))
        exit(OVERFLOW);
                
    (*p)->data = e;
    (*p)->next = NULL;
    
    return OK;
}

void InsFirst_E(ELinkList *L, Link h, Link s)
{
    s->next = h->next;
    h->next = s;
    
    if(h==(*L).tail)                    //若h为尾结点
        (*L).tail = h->next;

    (*L).len++;
}

/*═════╗
║ 算法2.20 ║
╚═════*/
 //算法2.9的改写
Status ListInsert_L_E(ELinkList *L, int i, LElemType_E e)   //创建两个指针，一个指向插入位置的前一个结构体，一个指向创建的新的赋值后的结构体。
                                                            //然后进行插入操作。当函数复杂或需要复用某些步骤（基本操作）的时候就可以这样抽离。
{
    Link h, s;

    if(!LocatePos_E(*L, i-1, &h))        //定位第i-1个结点位置
        return ERROR;                    //i值不合法

    if(!MakeNode_E(&s, e))                //创建结点
        return ERROR;                    //内存申请失败

    InsFirst_E(L, h, s);

    return OK;
}

Status DelFirst_E(ELinkList *L, Link h, Link *q){
    
    *q = h->next;
    
    if(*q){  //被删除节点是否存在
        h->next = (*q)->next;
        if(!h->next){  //被删除节点是否是最后一个节点
            (*L).tail = h;
        }
        
        (*L).len--;                        //并不释放被删结点所占空间

        return OK;
    }
    return ERROR;
}

/* 算法2.10的改写，调用了本文档中定义的函数 */
Status ListDelete_L_E(ELinkList *L, int i, LElemType_E *e){
    
        Link p, q;
        
        if(i<1 || i>(*L).len)
            return ERROR;

        LocatePos_E(*L, i-1, &p);
        DelFirst_E(L, p, &q);
        
        *e = q->data;
        free(q);
        q = NULL;
        
        return OK;
}

Status ListTraverse_E(ELinkList L, void(Visit)(LElemType_E))
{
    Link p;
    int j;
    
    p = L.head->next;
    
    for(j=1; j<=L.len; j++)
    {
        Visit(p->data);
        p = p->next;
    }
    
    return OK;
}

void FreeNode_E(Link *p)                    //释放空间
{
    free(*p);
    *p = NULL;  //传入二级指针是为了修改指针的值为NULL使其被垃圾回收
}

void Append_E(ELinkList *L, Link s){
    
    int count = 0;
        
        (*L).tail->next = s;
        
        while(s)                            //考虑s为空的情况,s是一串节点
        {
            (*L).tail = s;
            s = s->next;
            count++;
        }

        (*L).len += count;
}

Status Remove_E(ELinkList *L, Link *q){
    
    Link p;
    LocatePos_E(*L, L->len-1, &p);
    L->tail = p;
    L->len--;
    FreeNode_E(&(p->next));
    p->next = NULL;
    return OK;
}

PositionPtr PriorPos_E(ELinkList L, Link p)
{
    Link q;
    
    q = L.head->next;
    if(q==p)                            //首结点无前驱
        return NULL;
    else
    {
        while(q->next!=p)                //寻找p的前驱
            q = q->next;

        return q;
    }
}

PositionPtr NextPos_E(Link p)
{
    return p->next;
}

void InsBefore_E(ELinkList *L, Link *p, Link s)
{
    Link q;
    
    q = PriorPos_E(*L, *p);                //寻找p的前驱
    if(!q)                                //若p无前驱（只有一个结点）
        q = (*L).head;

    s->next = *p;
    q->next = s;
    *p = s;
    
    (*L).len++;                            //修改len，需用到*L
}

void InsAfter_E(ELinkList *L, Link *p, Link s)
{
    if(*p==(*L).tail)
        (*L).tail = s;

    s->next = (*p)->next;
    (*p)->next = s;
    *p = s;

    (*L).len++;
}

void SetCurElem_E(Link p, LElemType_E e){
    
    p->data = e;
}

LElemType_E GetCurElem_E(Link p)
{
    return p->data;
}

Status ListEmpty_E(ELinkList L)
{
    if(L.len)
        return FALSE;
    else
        return TRUE;
}

int ListLength_E(ELinkList L)
{
    return L.len;
}

PositionPtr GetHead_E(ELinkList L)
{
    return L.head;
}

PositionPtr GetLast_E(ELinkList L)
{
    return L.tail;
}

PositionPtr LocateElem_E(ELinkList L, LElemType_E e, Status(Compare)(LElemType_E,LElemType_E))
{
    Link p = L.head->next;

    while(p && !(Compare(e, p->data)))
        p = p->next;

    return p;
}
