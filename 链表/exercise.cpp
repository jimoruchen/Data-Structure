#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution
{
public:                                      //合并两个有序链表
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy ->next = head;
        ListNode *tmp = dummy;
        ListNode *pre = head;
        while(tmp ->next && tmp ->next ->next)
        {
            ListNode *cur = pre ->next;
            tmp ->next = cur;
            pre ->next = cur ->next;
            cur ->next = pre;
            tmp = pre;
            pre = pre ->next;
        }
        return dummy ->next;
    }
};

ListNode *createlinklist(vector<int> a, int n)
{
    ListNode *head = new ListNode(a[0]);  //head节点即为第一个节点，值为a[0]
    ListNode *cur = head;
    for(int i = 1; i < n; i++)
    {
        cur ->next = new ListNode(a[i]);
        cur = cur ->next;
    }
    return head;
}

void PrintLinkList(ListNode *head)
{
    ListNode * p = head;
    while(p)
    {
        cout << p ->val << " ";
        p = p ->next;
    }
    cout << endl;

}

int main()
{
    Solution s;
    vector<int> nums1;
    int i;
    do
    {
        cin >> i;
        nums1.push_back(i);
    } while(getchar() != '\n');
    int n1 = nums1.size();
    ListNode *head = createlinklist(nums1, n1);
    PrintLinkList(head);
    ListNode *head1 = s.swapPairs(head);
    PrintLinkList(head1);
    system("pause");
    return 0;  
}