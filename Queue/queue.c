#include<stdio.h>
#include<stdlib.h>
typedef int E;

typedef struct Queue
{
    E *array;
    int capacity;
    int rear, front;
}Queue;
typedef struct Queue *ArrayQueue;

void InitQueue(Queue *queue)
{
    if(queue ->array == NULL)   return;
    queue ->array = malloc(sizeof(Queue));
    queue ->capacity = 10;
    queue ->front = queue ->rear = 0; 
}

void EnQueue(Queue *queue, E element)
{
    if(queue ->rear + 1 % queue ->capacity == queue ->front)    return;
    queue ->rear = (queue ->rear + 1) % queue ->capacity;
    queue ->array[queue ->rear] = element;
}

_Bool IsEmpty(Queue *queue)
{
    return queue ->rear == queue ->front;
}

E DeQueue(Queue *queue)
{
    queue ->front = (queue ->front + 1) % queue ->capacity;
    return queue ->array[queue ->front];
}

void PrintQueue(Queue *queue)
{
    int i = queue ->front;
    do{
        i = (i + 1) % queue ->capacity;
        printf("%d ", queue ->array[i]);
    }while(i != queue ->rear);
    printf("\n");
}

int main()
{
    Queue *queue;
    InitQueue(queue);
    for(int i = 0; i < 5; i++)
        EnQueue(queue, i * 10);
    PrintQueue(queue);
    while(!IsEmpty(queue))
    {
        printf("%d ", DeQueue(queue));
    }
    printf("\n");
    system("pause");
    return 0;
}
