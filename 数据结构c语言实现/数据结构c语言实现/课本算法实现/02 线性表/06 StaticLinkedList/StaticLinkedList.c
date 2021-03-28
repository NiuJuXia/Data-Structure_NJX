//
//  StaticLinkedList.c
//  数据结构c语言实现
//
//  Created by 宋宋梦醒 on 2020/11/5.
//

#include "StaticLinkedList.h"

//这些的实现思路没有大话数据结构里的好

void InitSpace_SL(component array){
    for (int i=0;  i < MAXSIZE ; i++) {
        array[i].cur = i+1;
        array[i].data = 0;          //将备用链表初始化，游标从1到MAXSIE，最后一位取0。    data全部初始化为0
    }
    array[MAXSIZE-1].cur = 0;
}

int Malloc_SL(component array){
    int i = array[0].cur;
    if(i){
        array[0].cur=array[i].cur;
        return i;
    }else{
        return ERROR;       //申请一个空间，返回空间位置，将此节点从备用链表中删除。
    }
}

Status InitList_SL(component array){
    InitSpace_SL(array);
    int i = Malloc_SL(array);
    array[i].cur = 0;        //设置静态链表的表头，其游标为0
    return OK;
}

Status ListInsert_SL(component array, int i , LElemType_S e ){   //有表头，即第一个数据存储在静态链表的第二个位置。
    //i是静态链表的逻辑位置
    int insert = Malloc_SL(array);
    int body = 1;
    for (int j=1; j<i ; j++) {
        body = array[body].cur;   //获取要插入的元素的前一个位置在数组中的位置
    }
    array[insert].data = e;
    array[insert].cur = array[body].cur;
    array[body].cur = insert;
    return OK;
}

Status ListEmpty_SL(component array){
    return array[1].cur == 0 ? TRUE :FALSE;
}

Status GetSlElem_SL(component array, int i, LElemType_S *e){
    int dataIndex = 1;
    for (int j=0; j<i; j++) {
        dataIndex = array[dataIndex].cur;
    }
    *e = array[dataIndex].data;
    return OK;
}

void Free_SL(component array, int k){
    array[k].cur = array[0].cur;
    array[0].cur = k;  //将被删除的元素重新纳入备用链表
}

Status ListDelete_SLW(component array, int i, LElemType_S *e){

    int beforeD = 1;  //被删除元素的前一个元素在数组中的位置
    int position;  //被删除元素在数组中的位置
    for (int j = 1; j< i; j++) {
        beforeD = array[beforeD].cur;
    }
    position = array[beforeD].cur;
    array[beforeD].cur = array[position].cur;
    *e = array[position].data;
    Free_SL(array, position);

    return OK;
}

Status ListTraverse_SL(component array, void(Visit)(LElemType_S)){

    int p = array[1].cur;

    while(p) {
        Visit(array[p].data);
        p = array[p].cur;
    }
    return OK;
}

int ListLength_SL(component array){
    int i = 0;
    int p = array[1].cur;
    while (p) {
        p = array[p].cur;
        i++;
    }
    return i;
}

int LocateElem_SL(component array, LElemType_S e){ //这个函数并不严格符合这种算法的要求，其实相当于默认使用了 == 函数
    int count = 0;
    int p = array[1].cur;
    while (p) {
        if(array[p].data == e) { //之前把p = array[p].cur  写在判断的前面，这样造成了第一个array[p].data为2 我一直以为array是[1,2,3],但其实到这里就会有偏差，所以一定要打断点
                                 //就在出问题的前一句打。  记住这个经验
            return count;
        }
        p = array[p].cur;
        count++;
    }
    return -1;
}

Status PrrriorElem_SL(component array, LElemType_S cur_e, LElemType_S *pre_e){

    int i = array[1].cur;   //前一个元素在数组中的位置
    int j = array[i].cur;   //当前比较元素在数组中的位置， 这是一个常用的技巧
    while (array[j].cur && array[j].data != cur_e) {  //第一个元素的前驱没有意义，直接从第二个元素的数据开始对比
        i = j;
        j = array[i].cur;
    }
    if(j){
        *pre_e = array[i].data;
    }
    return OK;
}

Status NeeextElem_SL(component array, LElemType_S cur_e, LElemType_S *next_e){

    int i = array[1].cur;
    while (array[i].data != cur_e && array[i].cur) {
        i = array[i].cur;
    }
    if(array[i].cur){
        *next_e = array[array[i].cur].data;
    }
    return OK;
}

Status ClearList_SL(component array){

    int i = 1;
    LElemType_S e;
    while (array[i].cur) {
        ListDelete_SLW(array, i, &e);
    }
    return OK;
}

void DestroyList_SL(component array){
    ClearList_SL(array);
    Free_SL(array,1); //释放头节点
    array = NULL;
}
