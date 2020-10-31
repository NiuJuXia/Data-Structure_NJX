//
//  MergeSqList.c
//  数据结构c语言实现
//
//  Created by 宋宋梦醒 on 2020/10/29.
//

#include "MergeSqList.h"

void MergeSqList_1(SqList La, SqList Lb, SqList *Lc){
    int i = 1;
    int j = 1;
    int k = 0;
    LElemType_Sq ai, bj;
    int La_length = ListLength_Sq(La);
    int Lb_length = ListLength_Sq(Lb);
    
    InitList_Sq(Lc);
    
    
    while (i<=La_length&&j<=Lb_length) {
        GetElem_Sq(La, i, &ai);
        GetElem_Sq(Lb, j, &bj);
        if(ai<=bj){
            ListInsert_Sq(Lc, ++k, ai);
            ++i;
        }else{
            ListInsert_Sq(Lc, ++k, bj);
            ++j;
        }
    }
    
    while(i<=La_length)                    //表La还未扫描完
    {
        GetElem_Sq(La, i++, &ai);
        ListInsert_Sq(Lc, ++k, ai);
    }
   
    while(j<=Lb_length)                    //表Lb还未扫描完
    {
        GetElem_Sq(Lb, j++, &bj);
        ListInsert_Sq(Lc, ++k, bj);
    }
}

void MergeSqList_2(SqList La, SqList Lb, SqList *Lc){
    
    LElemType_Sq *pa,*pb,*pc;
    LElemType_Sq *La_last, *Lb_last;
    
    pa = La.elem;
    pb = Lb.elem;
    
    //不用InitList_Sq创建Lc
    Lc->listsize = Lc->length = La.length + Lb.length;
    pc = Lc->elem = (LElemType_Sq *)malloc(Lc->listsize*sizeof(LElemType_Sq));
    
    if(!pc)
            exit(OVERFLOW);
        
        La_last = La.elem + La.length - 1;    //指向La最后一个元素
        Lb_last = Lb.elem + Lb.length - 1;    //指向Lb最后一个元素
    
    while(pa<=La_last && pb<=Lb_last)     //La和Lb均未扫描完
    {
        if(*pa <= *pb)
            *pc++ = *pa++; //指针和值和递增的小技巧
        else
            *pc++ = *pb++;
    }
    
    while(pa <= La_last)                //表La未扫描完
        *pc++ = *pa++;                    //插入La的剩余元素

    while(pb <= Lb_last)                //表Lb未扫描完
        *pc++ = *pb++;                    //插入Lb的剩余元素
}
