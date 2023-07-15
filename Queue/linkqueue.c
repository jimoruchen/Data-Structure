#include<stdio.h>
#include<stdlib.h>
typedef int E;

struct Node
{
    E element;
    struct Node *next;
};
typedef struct Node * LinkNode;

struct Queue
{
    LinkNode rear, front;
};
typedef struct Queue * LinkQueue;

void InitQueue(LinkQueue queue)                     //初始化队列
{
    LinkNode node = malloc(sizeof(struct Node));
    if(node == NULL) return;
    node->next = NULL;
    queue ->rear = queue ->front = node;
}

void Enqueue(LinkQueue queue, E element)            //入队
{
    LinkNode node = malloc(sizeof(struct Node));
    if(node == NULL) return;
    node->next = NULL;                              //申明一个节点，它的后继节点为空，值为element
    node ->element = element;
    queue ->rear ->next = node;                     //用尾节点指向node，再将尾结点变为node
    queue ->rear = node;
}

_Bool IsEmpty(LinkQueue queue)                      //判断队列是否为空，rear和front都指向对首说明没有其它节点
{
    return queue ->front == queue ->rear;
}

E DeQueue(LinkQueue queue)                          //出队
{
    LinkNode node = queue ->front ->next;           //node指向队首节点后一个节点
    E e = node ->element;                           
    queue ->front ->next = node ->next;             //队首节点指向下下个节点
    if(node == queue ->rear)                        //如果node等于rear说明队列中只有一个节点和队首
        queue ->rear = queue ->front;               //将rear指向队首后再释放node节点
    free(node);
    return e;                                      //将队首front节点后一个节点的值返回
}

void PrintQueue(LinkQueue queue)                    //打印队列
{
    LinkNode node = queue ->front ->next;
    while(1)
    {
        printf("%d ", node ->element);
        if(node == queue ->rear)    break;
        else    node = node ->next;
    }
}

int main()
{
    struct Queue queue;   
    InitQueue(&queue);
    for(int i = 0; i < 5; i++)
        Enqueue(&queue, i * 10);
    PrintQueue(&queue);
    printf("\n");
    while(!IsEmpty(&queue))
        printf("%d ", DeQueue(&queue));
    printf("\n");
    system("pause");
    return 0;
}

