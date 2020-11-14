//
//  cycle.c
//  数据结构c语言实现
//
//  Created by 宋宋梦醒 on 2020/11/12.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode;

LNode* initLink(int n){
    
    LNode *head = NULL, *cycle = NULL;
    head = (LNode*)malloc(sizeof(LNode));
    
    cycle = head;
    
    for (int j=1; j<n; j++) {
        LNode *body = (LNode*)malloc(sizeof(LNode));
        body->data = j;
        body->next = NULL;
        cycle -> next = body;
        cycle = body;
    }
    cycle->next = head->next;//首尾相连,注意尾元素不是指向头节点，而是指向第一个有数据的元素
    return head;
}

void findAndKillK(LNode * head, int k, int m) {
    LNode *p = head, *tail = head;
    while (tail->next != head->next) {  //处理k=1的特殊情况
        tail = tail->next;
    }
    while (p->data != k) {
        tail = p;
        p = p->next;
    }
    
    while (p->next != p) {
        for (int i=1; i<m; i++) {
            tail = p;
            p=p->next;
        }
        tail->next = p->next;//从链表上将p结点摘下来
        printf("出列人的编号为:%d\n", p->data);
        free(p);
        p = tail->next;//继续使用p指针指向出列编号的下一个编号，游戏继续
    }
    printf("出列人的编号为:%d\n", p->data);
    free(p);
}

//int main() {
//    int n = 0, k = 0, m = 0;
//    LNode *head = NULL;
//    printf("输入圆桌上的人数:");
//    scanf("%d", &n);
//    head = initLink(n);
//    printf("从第几个人开始报数(k>1且k<%d)：", n);
//    scanf("%d", &k);
//    printf("数到几的人出列：");
//    scanf("%d", &m);
//    findAndKillK(head, k, m);
//
//    return 0;
//}
