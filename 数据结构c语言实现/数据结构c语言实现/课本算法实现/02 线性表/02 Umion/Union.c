////
////  Union.c
////  数据结构c语言实现
////
////  Created by 宋宋梦醒 on 2020/10/29.
////
//
//#ifndef Union_c
//#define Union_c
//
//#include "Union.h"
//
//void Union(SqList *La, SqList Lb){
//    int La_len, Lb_len;
//    int i;
//    LElemType_Sq e;
//
//    La_len = La->length;
//    Lb_len = Lb.length;
//
//    for (i=1; i<=Lb_len; i++) {
//        GetElem_Sq(Lb, i, &e); //取Lb中第i个元素赋给e
//        if(!LocateElem_Sq(*La, e, equal)){
//            ListInsert_Sq(La, ++La_len, e);
//        }     //若e不在La中则插入
//    }
//}
//
//Status equal(LElemType_Sq e1, LElemType_Sq e2)
//{
//   return e1==e2 ? TRUE : FALSE;
//}
//
//#endif
