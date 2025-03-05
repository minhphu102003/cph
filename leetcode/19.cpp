#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0,head);
    ListNode *fast = dummy, *slow = dummy;

    for (int  i = 0; i <= n; i++)
    {
        fast = fast->next;
    }
    
    while (fast)
    {
        fast = fast ->next;
        slow = slow -> next;
    }
    slow->next = slow->next->next;

    return dummy->next;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    ListNode *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!head) {
            head = new ListNode(x);
            tail = head;
        } else {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
    }

    head = removeNthFromEnd(head, k);
    printList(head);

    return 0;
}