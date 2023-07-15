#include<stdio.h>
#include<stdlib.h>

typedef int E;

typedef struct ListNode
{
    E element;
    struct ListNode *prev;
    struct ListNode *next;
}ListNode;

typedef struct ListNode * Node;

void InitList(ListNode * node){
    node->next = node->prev = NULL;
}

void InsertList(ListNode *head, E element, int index)       //插入节点
{
    ListNode *p = head;
    if(index < 1)   return;
    while(--index)
        p = p ->next;
    ListNode *q = malloc(sizeof(ListNode));
    q ->element = element;
    if(p ->next){
        p ->next ->prev = q;
        q ->next = p ->next;
    } else {    
        q ->next = NULL;
    }
    p ->next = q;
    q ->prev = p;
}

void DeleteListNode(ListNode *head, int index)      //删除节点
{
    if(index < 1)   return;
    ListNode *p = head;
    while(--index)
        p = p ->next;
    ListNode *q = p ->next;
    if(q ->next) {
        q ->next ->prev = p;
        p ->next = q ->next;
    } else 
        q ->next = NULL;
    free(q);
}

void PrintList(ListNode *head)          //打印链表
{
    while(head ->next)
    {
        head = head ->next;
        printf("%d -> ", head ->element);
    }
}

int main()
{

    ListNode *head = malloc(sizeof(ListNode));
    InitList(head);

    for(int i = 1; i <= 5; i++)
        InsertList(head, i * 10, i);

    ListNode *node = head;
    
    while(node ->next) {
        node = node ->next;
        printf("%d -> ", node ->element);
    }
    printf("\n");
    while(node ->prev) {
        printf("%d -> ", node ->element);
        node = node ->prev;
    }
    printf("\n");

    DeleteListNode(head, 2);
    PrintList(head);
    printf("\n");
    system("pause");

} 