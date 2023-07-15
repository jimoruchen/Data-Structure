#include<stdio.h>
#include<stdlib.h>
typedef int E;

typedef struct List{
    E * array;
    //E array[10];
    int capacity;
    int size; 
}List;  

typedef struct List * ArrayList;  

_Bool initList(ArrayList list)     //初始化
{
    list ->array = malloc(sizeof(E) * list->capacity);
    if(list ->array == NULL) return 0;  
    list ->capacity = 5;
    list ->size = 0;
    return 1;
}

_Bool InsertList(ArrayList list, E element, int index)     //插入
{
    if(index < 0 || index > list ->size + 1)
        return 0;
    if(list ->size == list ->capacity)
    {
        int newcapacity = list ->capacity + (list ->size >> 1);
        E * newarray = realloc(list ->array, newcapacity * sizeof(E));
        if(newarray == NULL)
            return 0;
        list ->array = newarray;
        list ->capacity = newcapacity;
    }
    for(int i = list ->size; i > index - 1; --i) 
        list ->array[i] = list ->array[i - 1];
    list ->array[index - 1] = element;
    list ->size++;
    return 1;
}

_Bool DeleteList(ArrayList list, int index)     //删除
{
    if(index < 1 || index > list ->size)
        return 0;
    for(int i = index - 1; i < list ->size - 1; i++)
    {
        list ->array[i] = list ->array[i + 1];
    }
    list ->size--;
    return 1;
}

int SizeList(ArrayList list)   //返回大小
{
    return list ->size;
}

E * GetList(ArrayList list, int index)      //按位查找
{
    if(index < 1 || index > list ->size)    
        return NULL;
    return &list ->array[index - 1];      //返回地址
}

int FindList(ArrayList list, E element)      //按值查找
{
    for(int i = 0; i < list ->size; i++)
    {
        if(element == list ->array[i])
            return i + 1; 
    }
    return -1;
}

void PrintList(ArrayList list)    //打印
{
    for(int i = 0; i < list->size; i++)
        printf("%d ", list->array[i]);
    printf("\n");
}

int main() 
{
    List list;
    if(initList(&list))
    {
        for(int i = 0; i < 10; i++)
            InsertList(&list, i * 10, i + 1);
        PrintList(&list);

        //DeleteList(&list, 2);  //删除第二个元素
        //PrintList(&list);

        //printf("%d ", *GetList(&list, 2));  //解引用，输出第二个元素

        printf("%d ", FindList(&list, 20));

        //printf("%d\n", list.capacity);  //输出容量

    }
    else
        printf("顺序表初始化失败，无法启动程序！");
    system("pause");
    return 0;
}
