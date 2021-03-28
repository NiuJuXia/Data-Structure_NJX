//
//  MergeEList.c
//  数据结构c语言实现
//
//  Created by 宋宋梦醒 on 2020/11/20.
//

#include "MergeEList.h"

int Cmp(LElemType_E c1, LElemType_E c2){
    
    return c1-c2;
}

Status MergeEList_L(ELinkList La, ELinkList Lb, ELinkList *Lc, int(Compare)(LElemType_E c1, LElemType_E c2)){
    
    Link ha,hb,pa,pb,q;
    LElemType_E c1,c2;
    InitList_E(Lc);
    ha = La.head;
    hb = Lb.head;
    pa = ha->next;
    pb = hb->next;
    
    while (!ListEmpty_E(La) && !ListEmpty_E(Lb)) {
        c1 = pa->data;
        c2 = pb->data;
        if(Compare(c1,c2)>0){
            DelFirst_E(&Lb, hb, &q);
            InsFirst_E(Lc, Lc->tail, q);
            pb = hb->next;
        }else{
            DelFirst_E(&La, ha, &q);
            InsFirst_E(Lc, Lc->tail, q);
            pa = ha->next;
        }
    }
    
    if(!ListEmpty_E(La))
            Append_E(Lc, pa);
        else
            Append_E(Lc, pb);

        FreeNode_E(&ha);
        FreeNode_E(&hb);
    
    return OK;
}

Status CreateList_ascend(FILE *fp, ELinkList *L, int count)
{                                                    //按非降序序列创建链表L
    int i;
        
    InitList_E(L);
    if(!L)
        return ERROR;

    for(i=1; i<=count; i++)
    {
        ListInsert_L_E(L, i, i);
    }
    
    return OK;
}
