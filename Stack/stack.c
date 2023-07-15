#include<stdio.h>
#include<stdlib.h>
typedef int E;
typedef struct Stack
{
    E *array;
    int capacity;
    int top;
}Stack;

typedef struct Stack * Arraystack;

void InitStack(Arraystack stack)            //初始化
{
    stack ->array = malloc(sizeof(E) * 10);
    if(stack ->array == NULL)  return;
    stack ->capacity = 5;
    stack ->top= -1;
}

void PushStack(Arraystack stack, E element)         //入栈
{
    if(stack ->top + 1 == stack ->capacity)         //扩容
    {
        int newcapacity = stack ->capacity + (stack ->capacity >> 1);
        E *newarray = realloc(stack ->array, sizeof(E) * newcapacity);
        if(newarray == NULL)    return;
        stack ->capacity = newcapacity;
        stack ->array = newarray;
    }
    stack ->array[++stack ->top]= element;
}

_Bool IsEmpty(Arraystack stack)                     //判断栈是否为空
{
    return stack ->top == -1;
}

E PopStack(Arraystack stack)                        //出栈
{
    return stack ->array[stack ->top--];
}

void PrintStack(Arraystack stack)                   //打印栈
{
    for(int i = 0; i <= stack ->top; i++)
        printf("%d ", stack ->array[i]);
    printf("\n");
}

int main()
{
    Stack *stack = malloc(sizeof(Stack));
    InitStack(stack);
    for(int i = 0; i < 8; i++)
    {
        PushStack(stack, i * 10);
    }
    PrintStack(stack);
    while(!IsEmpty(stack))
    {
        printf("%d ", PopStack(stack));
    }
    system("pause");
    return 0;
}