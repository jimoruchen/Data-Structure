#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef int E;

struct Node
{
    E element;
    struct Node * next;
};

typedef struct Node * StackNode;

void InitNode(StackNode head)
{
    head ->next = NULL;
}

void PushStack(StackNode head, E element)
{
    StackNode node = malloc(sizeof(struct Node));
    node ->element = element;
    node ->next = head ->next;
    head ->next = node;
}

E PopStack(StackNode head)
{
    StackNode p = head ->next;
    E e = p ->element;
    head ->next = p ->next;
    free(p);
    return e;
}

bool IsEmpty(StackNode head)
{
    return head ->next == NULL;
}

bool isValid(char * s)
{
    StackNode head = malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("内存分配失败\n");
        return false; 
    }
    InitNode(head);
    int len = strlen(s);
    if(len % 2 == 1)    return false;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '[' || s[i] == '{' || s[i] == '(')
            PushStack(head, s[i]);
        else{
            if(IsEmpty(head))   return false;
            if(s[i] == ']')
                if(PopStack(head) != '[')   return false;
            if(s[i] == '}')
                if(PopStack(head) != '{')   return false;
            if(s[i] == ')')
                if(PopStack(head) != '(')   return false;
        }
    }
    return IsEmpty(head);
}
int main()
{
    char str[10];
    gets(str);
    printf("%d ", isValid(str));  //数组名即是指针，不用使用&str
    system("pause");
}

