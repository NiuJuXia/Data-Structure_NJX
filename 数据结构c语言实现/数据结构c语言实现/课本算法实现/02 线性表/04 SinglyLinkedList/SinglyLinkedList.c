/*******************************************
 *                                         *
 * 文件夹: ▲02 线性表\04 SinglyLinkedList *
 *                                         *
 * 文件名: SinglyLinkedList.c              *
 *                                         *
 * 算  法: 2.8、2.9、2.10、2.11            *
 *                                         *
 *******************************************/

#ifndef SINGLYLINKEDLIST_C
#define SINGLYLINKEDLIST_C

#include "SinglyLinkedList.h"

Status InitList_L(LinkList *L){  //外面绕来绕去其实对于此函数而言就是像最基础的一样传入一个结构体变量(不是指向变量的指针),然后以指针形式接受，这样就可以修改变量的值
    
    (*L) = (LinkList)malloc(sizeof(LNode));
    
    if(!(*L)) exit(OVERFLOW);;
    
    (*L)->next = NULL;
    
    return OK;
}

Status ListEmpty_L(LinkList L){
    
    if(L!=NULL&&L->next==NULL) return TRUE;
    
    return FALSE;
}

Status ListInsert_L(LinkList L, int i, LElemType_L e){
    
    LinkList p = L;
    
    LinkList s;
    
    int j = 1;
    
    while (p->next != NULL && j < i) {
        p = p->next;
        j++;
    }//获取i-1个节点的指针
    
    if(!p || j>i)
            return ERROR;
    
    s = (LinkList)malloc(sizeof(LNode));
    if(!s)
            exit(OVERFLOW);
    
    s->next = p->next;
    s->data = e;
    p->next = s;
    
    return OK;
}

Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L)){
    
    LinkList p = L->next;
    while (p) {
        Visit(p->data);
        p = p->next;
    }
    return OK;
}

int ListLength_L(LinkList L){
    
    LinkList p = L->next;
    
    int j = 0;
    
    while (p) {
        p = p->next;
        j++;
    }
    return j;
}

/*═════╗
║ 算法2.10 ║
╚═════*/
Status ListDelete_L(LinkList L, int i, LElemType_L *e)
{
    LinkList pre, p;
    int j;

    pre = L;
    j = 1;

    while(pre->next && j<i)            //寻找第i个结点，并令pre指向其前驱
    {
        pre = pre->next;
        ++j;
    }
    
    if(!pre->next || j>i)            //删除位置不合理
        return ERROR;

    p = pre->next;
    pre->next = p->next;
    *e = p->data;
    free(p);

    return OK;
}

/*════╗
║ 算法2.8║
╚════*/
Status GetElem_L(LinkList L, int i, LElemType_L *e)
{
    int j;
    LinkList p = L->next;
    
    j = 1;
    
    while(p && j<i)                        //p不为空且还未到达i处
    {
        j++;
        p = p->next;
    }

    if(!p || j>i)                        //第i个元素不存在
        return ERROR;

    *e = p->data;

    return OK;
}

int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L)){
    int i;
    LinkList p;
    
    i=-1;//L不存在返回-1
    if(L){
        i = 0;//不存在符合函数要求返回0
        p = L->next;
        
        while (p) {
            i++;
            if(!Compare(e, p->data)){
                p = p->next;
                if(p==NULL) return 0;
            }else{
                break;
            }
        }
    }
    
    return i;
}

/* 银行排队算法中，此处两个函数不能直接使用，原因是结构不能直接比较 */
#ifndef BANKQUEUING_C
Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e){
    
    LinkList p = L->next;
    LinkList sub;
    
    if(p->data != cur_e){ //当第一个元素等于比较元素时报错
        while (p->next) {
            sub = p->next;
            if(sub->data == cur_e){
                *pre_e = p->data;
                return OK;
            }
            p = sub;
        }
    }
    
    return ERROR;//当没有找到时也报错
}

Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e)
{
    LinkList p, suc;
    
    if(L)
    {
        p = L->next;
        
        while(p && p->next)
        {
            suc = p->next;
            
            if(suc && p->data==cur_e)
            {
                *next_e = suc->data;
                return OK;
            }
            
            if(suc)
                p = suc;
            else
                break;
        }
    }

    return ERROR;
}

#endif

Status CreateList_HL(FILE *fp, LinkList *L, int n){
    
    int i, tmp;
    LinkList p;
    
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    
    for (i=0; i<n; i++) {
        if(fscanf(fp, "%d", &tmp)==1){
            p = (LinkList)malloc(sizeof(LNode));
            p->data = tmp;
            p->next = (*L)->next;
            (*L)->next = p;
        }else{
            return ERROR;
        }
    }
    return OK;
}

Status CreateList_TL(FILE *fp, LinkList *L, int n)
{
    int i;
    LinkList p, q;
    LElemType_L tmp;
            
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L)->next = NULL;
        
    for(i=1,q=*L; i<=n; ++i)
    {
        if(fscanf(fp, "%d", &tmp)==1)
        {
            p = (LinkList)malloc(sizeof(LNode));
            if(!p)
                exit(OVERFLOW);
            p->data = tmp;                        //录入数据
            q->next = p;
            q = q->next;
        }
        else
            return ERROR;
    }
    
    q->next = NULL;

    return OK;
}
#endif
