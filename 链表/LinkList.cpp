#include<iostream>
#include<vector>
using namespace std;
typedef struct Node 
{
    int data;
    struct Node *next;
}Node, *LinkList;

//尾插法创建链表
void  CreatLinkList1(LinkList &L, vector<int> a, int n) //LinkList& L表示一个指向链表头节点的指针引用，通过该指针引用可以改变头节点的值。
                                                       //int n表示要创建的链表中节点的数量。
{
    L = new Node;     // 创建头节点，并将其指针赋值给指针引用L
    L->next = nullptr;
    Node * p = L;
    for(int i = 0; i < n; i++)
    {
        Node * q = new Node;
        q ->data = a[i];
        q ->next = p ->next;
        p ->next = q;
        p = q;
    }
}

//头插法创建链表
void  CreatLinkList2(LinkList &L, vector<int> a, int n) //LinkList& L表示一个指向链表头节点的指针引用，通过该指针引用可以改变头节点的值。
                                                       //int n表示要创建的链表中节点的数量。
{
    L = new Node;     // 创建头节点，并将其指针赋值给指针引用L
    L->next = nullptr;
    for(int i = 0; i < n; i++)
    {
        Node * p = new Node;
        p ->data = a[i];
        p ->next = L ->next;
        L ->next = p;
    }

}

//打印链表
void PrintLinkList(LinkList &L)
{
    Node * p = L ->next;
    cout << "输出链表：";
    while(p) 
    {
        cout << p ->data << " ";
        p = p ->next;
    }
    cout << endl;
}

//求链表长度
int LinkListLength(LinkList &L)
{
    int length = 0;
    Node * p = L ->next;
    while(p)
    {
        length++;
        p = p ->next;
    }
    return length;
}

//删除节点
int Delete(LinkList &L, int i, int &temp)
{
    Node * p = L;
    int j = 0;
    while(p && j < i - 1)
    {
        p = p -> next;
        j++;
    }
    Node * q = new Node;
    q  = p ->next;
    temp = q ->data;
    p ->next = q ->next;;
    delete q;
    return temp;
}

//按序号查询节点返回节点
Node * Get(LinkList L, int pos)
{
    Node * p = L;
    int i = 0;
    while(p && i < pos)
    {
        p = p -> next;
        i++;
    }
    return p;
}

//按值查询节点返回序号
int Locate(LinkList & L, int item)
{
    Node * p = L ->next;
    int i = 0;
    while(p && p ->data != item)
    {
        p = p ->next;
        i++;
    }
    return i + 1;
}

//尾插法，插在节点的后面
bool Insert1(LinkList &L, int m, int item)
{
    Node * p = L;
    int i = 0;
    while(p && i < m )
    {
        p = p ->next;
        i++;
    }                     //p -> t 
    Node * q = new Node;  //  q
    q -> next= p ->next;  //q指向p的下一个节点t 
    q ->data = item;
    p ->next = q;         //p指向q 
    return true;          //q = p ->next  q代替t，p指向q 
}  

//头插法
bool Insert2(LinkList &L, int n, int item)  //1  2  3  4  5
{
    Node * p = L;
    int i = 0;
    while(p && i < n - 1)
    {
        p = p ->next;
        i++;
    }
    Node * q = new Node;
    q ->next = p ->next; 
    q ->data = item;
    p ->next = q;
    return true; 
}

int main()
{
    LinkList L1;
    vector<int> a;
    vector<int> b = {1,2,3};
    int num;
    cout << "新建链表：" ;
    do
    {
        cin >> num;
        a.push_back(num);
    }while(getchar()!='\n');    
    int n = a.size();
    CreatLinkList1(L1, a, n);
    PrintLinkList(L1);
    int len = LinkListLength(L1);
    cout << "链表的长度为：" << len << endl;
    int i, temp;
    cout << "删除第几个节点:";
    cin >> i;
    Delete(L1, i, temp);
    cout << "删除节点的值为：" << temp << endl;
    PrintLinkList(L1);
    int pos1, pos2, pos3, pos4;
    cout << "查找第几个节点的值:";
    cin >> pos1; 
    Node * p1 = Get(L1, pos1);
    cout << "要查找节点的值:";
    cout << p1 ->data << endl;
    cout << "查找值为多少的节点：";
    cin >> pos2;
    cout << "查找节点的序号为：" << Locate(L1, pos2) << endl;
    int m1, m2;
    cout << "尾插法输入要插入节点的序号和值：";
    cin >> m1 >> pos3;
    Insert1(L1, m1, pos3);
    PrintLinkList(L1);
    cout << "头插法输入要插入节点的值：";
    cin >> m2 >> pos4;
    Insert2(L1, m2, pos4);
    PrintLinkList(L1);
    system("pause");
    return 0;
}


