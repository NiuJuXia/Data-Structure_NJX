//
//  DualCycleLinkedList.c
//  数据结构c语言实现
//
//  Created by 宋宋梦醒 on 2020/11/14.
//

#include "DualCycleLinkedList.h"

Status NJXInitList_DuL(DuLinkList *L, int i){
    
    *L = (DuLinkList)malloc(sizeof(DuLNode));
    
    DuLinkList NPosition = *L;
    
    for (int j=0; j<i; j++) {
        DuLinkList body = (DuLinkList)malloc(sizeof(DuLNode));
        body->prior = NPosition;
        body->next = NULL;
        body->data = j+1;
        NPosition->next = body;
        NPosition = body;
    }
    
    return OK;
}

void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC)){
    
    DuLinkList H = L->next;
    while (H) {
        Visit(H->data);
        H = H->next;
    }
}

int ListLength_DuL(DuLinkList L){
    
    int length=0;
    DuLinkList H = L->next;
    while (H) {
        length++;
        H = H->next;
    }
    return length;
}

Status ListEmpty_DuL(DuLinkList L){
    return L->next ? FALSE : TRUE;
}

Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e){
    
    DuLinkList H = L;
    for (int j=1; j<i; j++) {
        if(H){
            H = H->next;
        }else{
            return ERROR;
        }
    }
    DuLinkList body = (DuLinkList)malloc(sizeof(DuLNode));
    body->prior = H;
    body->data = e;
    body->next = H->next;
    body->next->prior = body;
    H->next = body;
    return OK;
}

Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e){
    
    DuLinkList H = L;
    for (int j=1; j<i; j++) {
        if(H){
            H = H->next;
        }else{
            return ERROR;
        }
    }
    DuLinkList deleEle =  H->next;
    if(deleEle->next){
        deleEle->next->prior = H;
        H->next = deleEle->next;
    }else{
        H->next = NULL;  //删除最后一个元素
    }
    *e = deleEle->data;
    free(deleEle);
    return OK;
}

Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e){
    
    DuLinkList H = L;
    for (int j=0; j<i; j++) {
        H = H->next;
    }
    *e = H->data;
    return OK;
}

Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e){
    
    DuLinkList H = L->next->next; //从第二个元素开始
    while (H) {
        if(H->data == cur_e){
            *pre_e = H->prior->data;
            return OK;
        }
        H = H->next;
    }
    return ERROR;
}

Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e){
    
    DuLinkList H = L->next;
    while (H) {
        if(H->data == cur_e && H->next){
            *next_e = H->next->data;
            return OK;
        }
        H = H->next;
    }
    return ERROR;
}

DuLinkList GetElemPtr_DuL(DuLinkList L, int i){
    
    DuLinkList H = L;
    if(ListLength_DuL(L)<i) return H;
    for (int j=0; j<i; j++) {
        H = H->next;
    }
    return H;
}

int LocateElem_DuL(DuLinkList L, LElemType_DC e, Status (Compare)(LElemType_DC, LElemType_DC)){
    
    int i = 1;
    DuLinkList H = L->next;
    while (H&&!Compare(e,H->data)) {
        H = H->next;
        i++;
    }
    if(ListLength_DuL(L)<i){
        printf("没有符合要求的元素\n");
        return ERROR;
    }
    return i;
}

Status ClearList_DuL(DuLinkList L){
    
    int e;
    int j = ListLength_DuL(L); //for循环第二个条件如果用函数返回值，每次循环都会重新求值，而每次循环的结果会对ListLength_DuL(L)函数的值产生影响，所以要用变量j记录一开始的长度
    for (int i = 0; i<j; i++) {
        ListDelete_DuL(L,1,&e);
    }
    return OK;
}

void DestroyList_DuL(DuLinkList *L){
    ClearList_DuL(*L);
    free(*L);
    *L = NULL;
}
