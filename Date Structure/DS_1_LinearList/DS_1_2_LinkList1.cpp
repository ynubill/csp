//
// Created by kim on 2020/6/19.
// Copyright (c) Kim Yang All rights reserved.
//

//带头节点的单链表

#include <stdio.h>
#include <stdlib.h>

/**定义模块**/

typedef struct LNode {
    int data;
    LNode* next;
} LNode, *LinkList;

bool InitList(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

bool Empty(LinkList L) {
    return (L->next == NULL);
}

//按位插入
bool ListInsert(LinkList& L, int i, int e) {
    if (i < 1)
        return false;
    LNode* p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertNextNode(LNode* p, int e) {
    if (p == NULL)
        return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertPriorNode(LNode* p, int e) {
    if (p == NULL)
        return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete(LinkList& L, int i, int& e) {
    if (i < 1)
        return false;
    LNode* p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    LNode* q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}



/**实现模块**/

/**测试模块**/
// Test
void TestPrint(bool test, char about[]) {
    if (test)
        printf("%s成功\n", about);
    else
        printf("%s失败\n", about);
}

void PrintList(LinkList L) {
    //循环打印整个链表
    LNode* p = L->next;  //扫描指针
    int j = 0;
    if (p == NULL)
        printf("这是一个空表\n");
    while (p != NULL) {
        printf("LinkList[%d]=%d\n", j, p->data);
        p = p->next;
        j++;
    }
}

void TestModule() {
    LinkList L;
    TestPrint(InitList(L), "初始化");
    PrintList(L);
    TestPrint(ListInsert(L, 1, 3), "按位插入");
    PrintList(L);
    int e;
    TestPrint(ListDelete(L, 1, e), "删除");
    PrintList(L);
    printf("被删除的数据是：%d\n", e);
}

/**测试模块**/

int main() {
    TestModule();
    return 0;
}