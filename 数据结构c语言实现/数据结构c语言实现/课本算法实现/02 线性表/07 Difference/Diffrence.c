
/*************************************
 *                                     *
 * 文件夹: ▲02 线性表\07 Difference *
 *                                      *
 * 文件名: Difference.c              *
 *                                      *
 * 算  法: 2.17                      *
 *                                   *
 *************************************/

#include "Diffrence.h"

//思路很简单，先建立包含集合A中元素的静态链表，然后遍历集合B，若B中元素不在A中，将其加入静态链表，否则，将其从静态链表中删掉，注意头、尾指针的修改。

void difference(component H, LElemType_S A[], int len_A, LElemType_S B[], int len_B){
    
    for (int i=1; i<=len_A; i++) {  //以数组A的元素初始化链表H
        ListInsert_SL(H, i, A[i-1]);
    }
    int len_H = len_A+1; //链表的元素个数+1,用于在链表末尾添加元素
    
    for (int j=0; j<len_B; j++) {
        
        int symbol = 0;  //0 表示当前B元素在A中， 1表示不在
        int cur = H[1].cur;
        int k = 0;
        LElemType_S e;
        while (cur) {
            k++;
            if(H[cur].data == B[j]){
                symbol = 1;
                break;
            }
            cur = H[cur].cur;
        }
        
        if(symbol){
            ListDelete_SLW(H, k, &e);
            len_H--;
        }else{
            ListInsert_SL(H, len_H , B[j] );
            len_H++;
        }
        
    }
    
}

