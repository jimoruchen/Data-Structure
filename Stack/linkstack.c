#include<stdio.h>
#include<stdlib.h>

typedef int E;

typedef struct ListNode
{
    E element;
    struct ListNode *next;
}ListNode;

typedef struct ListNode * Node;

void InitStack(ListNode *head)                      //初始化链栈
{
    head ->next = NULL;
}

_Bool PushStack(ListNode *head, E element)          //入栈，在head节点后依次插入
{
    ListNode *p = malloc(sizeof(ListNode));
    p ->element = element;
    p ->next = head ->next;
    head ->next = p;
    return 1;
}

E PopStack(ListNode *head)                          //出栈，依次出head后的节点
{
    ListNode * p = head ->next;
    head ->next = head ->next ->next;
    E e = p ->element;
    free(p);
    return e;
}

_Bool IsEmpty(ListNode *head)                       //判断栈是否为空
{
    return head ->next == NULL;
}

void PrintStack(ListNode *head)                     //打印栈中元素
{
    head = head ->next;
    while(head)
    {
        printf("%d ", head ->element);
        head = head ->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode *head = malloc(sizeof(struct ListNode));
    InitStack(head);
    for(int i = 0; i < 5; i++)
        PushStack(head, i * 10);
    PrintStack(head);
    while(!IsEmpty(head))
    {
        printf("%d ", PopStack(head));
    }
    system("pause");
    return 0;
}