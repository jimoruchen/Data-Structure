#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int data;
    ListNode *next;
    ListNode *prev;
    ListNode() : data(0), next(NULL), prev(NULL) {}
    ListNode(int data) : data(data), next(NULL), prev(NULL) {}
};

ListNode *CreateLinkList(vector<int> nums, int n)
{
    if(n == 0)
        return NULL;
    ListNode *head = new ListNode;
    ListNode *cur = head;
    for(int i = 0; i < n; i++)
    {
        cur ->next = new ListNode(nums[i]);
        cur ->next ->prev = cur;
        cur = cur ->next;
    }
    return head;
}

void PrintLinkList(ListNode * head)
{
    ListNode *cur = head ->next;
    cout << "输出链表：";
    while(cur)
    {
        cout << cur ->data << " ";
        cur = cur ->next;
    }
    cout << endl;
}

int Length(ListNode *head)
{
    ListNode *cur = head ->next;
    int len = 0;
    while(cur)
    {
        len++;
        cur = cur ->next;
    }
    return len;
}

int Delete(ListNode *head, int idex)
{
    int i = 0;
    ListNode *cur = head;
    while(i < idex - 1 && cur != NULL)
    {
        cur = cur ->next;
        i++;
    }  
    if(cur == NULL)
        return false;
    ListNode *p = cur ->next;
    cur ->next = p ->next;
    if(p ->next != NULL)
        p ->next ->prev = cur;
    int data = p ->data;
    delete p;
    return data;
}

ListNode *Get(ListNode *head, int pos)
{
    ListNode *p = head;
    int i = 0;
    while(p && i < pos)
    {
        p = p ->next;
        ++i;
    }
    return p;

}

int Locate(ListNode *head, int pos, int length)
{
    ListNode *p = head;
    int i = 0;
    while(p && p ->data != pos)
    {
        p = p ->next;
        i++;
    }
    return i;
}


int main()
{
    vector<int> nums;
    int i, idex;
    cout << "新建链表：" ;
    do
    {
        cin >> i;
        nums.push_back(i);
    }while(getchar() != '\n');
    int m = nums.size();
    ListNode * head = CreateLinkList(nums, m);
    PrintLinkList(head);
    int length = Length(head);
    cout << "链表长度为：" << length << endl;
    cout << "删除第几个节点：";
    cin >> idex;
    cout << "删除节点的值为：";
    cout << Delete(head, idex) << endl;
    PrintLinkList(head);
    int pos1, pos2,pos3,pos4;
    cout << "输入要查找节点的序号：";
    cin >> pos1;
    ListNode *p = Get(head, pos1);
    cout << "要查找节点的值为:" << p ->data << endl;
    cout << "输入要查找节点的值：";
    cin >> pos2;
    cout << "查找节点的序号为：" << Locate(head, pos2, length) << endl;
    system("pause");
    return 0;
}