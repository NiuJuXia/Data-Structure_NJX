//
//  MergeList.c
//  数据结构c语言实现
//
//  Created by 宋宋梦醒 on 2020/11/3.
//

#include "MergeList.h"

/*═════╗
║ 算法2.12 ║
╚═════*/
void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc){
    
    LinkList pa,pb,pc;
    pa = La->next;
    pb = (*Lb)->next;
    pc = *Lc = La;
    
    while(pa&&pb){
        if(pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    
    pc->next = (pa ? pa : pb);
    
    free(*Lb);
    *Lb = NULL;
}
