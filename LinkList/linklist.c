#include<stdio.h>
#include<stdlib.h>

typedef int E;

typedef struct ListNode
{
    E element;
    struct ListNode * next;
} ListNode;

typedef struct ListNode * Node;

void InitList(Node head)    //void InitList(struct ListNode * head)
{
    head ->next = NULL;
}

void InsertList(ListNode *head, E element, int index)           //插入
{
    if(index < 1)
        return;
    ListNode *p = head;
    for(int i = 0; i < index - 1; i++)
        p = p ->next;
    ListNode *q = malloc(sizeof(ListNode));
    q ->element = element;
    q ->next = p ->next;
    p ->next = q;
}

void DeleteList(ListNode *head, int index)                      //删除第index个节点
{
    ListNode *p = head;
    if(index < 1)   return;
    while(--index)
    {
        p = p ->next;
        if(p == NULL)   return;
    }
    ListNode *q = p ->next;
    p ->next = p ->next ->next;
    free(q);
}

E  *GetList(Node head, int index)                               //返回第index个节点的值
{
    ListNode *p = head ->next;
    if(index < 1)   return 0;
    while(--index)
    {
        p = p ->next;
        if(p ==NULL)    return 0;
    }
    return &p ->element;    //返回地址，main函数中需解引用printf("%d ", *GetList(&head, 1));
}

/*
E  GetList(Node head, int index)
{
    ListNode *p = head ->next;
    if(index < 1)   return 0;
    while(--index)
    {
        p = p ->next;
        if(p ==NULL)    return 0;
    }
    return p ->element;    //返回值，main函数中直接输出printf("%d ", GetList(&head, 1));
}
*/

int FindList(ListNode *head, E element)                         //返回值为element的节点的序号
{
    ListNode *p = head ->next;
    int i = 1;
    while(p)
    {
        if(p ->element == element)
            return i;
        p = p ->next;
        i++;
    }
    return 0;
}


int SizeList(ListNode *head)                                    //返回链表的长度
{
    ListNode * p = head;
    int i = 0;
    while(p ->next)
    {
        p = p ->next;
        i++;
    }
    return i;
}   

void PrintList(ListNode *head)                                  //打印链表
{
    while(head ->next)
    {
        head = head ->next;
        printf("%d ", head ->element);
    }
    printf("\n");
} 

int main()
{
    ListNode *head = malloc(sizeof(ListNode));
    InitList(head);
    for(int i = 1; i <= 5; i++)
        InsertList(head, i * 10, i);           //输出10 20 30 40 50
    //InsertList(head, 60, 2);                 //在第二个位置插入60，输出10 60 20 30 40 50 
    //DeleteList(head, 1);                     //删除第一个节点20 30 40 50
    PrintList(head);
    printf("\n");
    //printf("%d ", *GetList(head, 1));        //查找第一个位置的元素
    //printf("%d ", FindList(head, 10));       //查找值为10的元素的序号
    //printf("%d ", SizeList(head));           //返回链表长度
    system("pause");
}