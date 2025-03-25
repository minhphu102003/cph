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

ListNode *deleteMiddle(ListNode *head)
{
    if(!head || !head->next) return nullptr;
    ListNode *slow = head, *fast = head, *prev = nullptr;
    while (fast && fast ->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
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

    int n;
    cin >> n;

    ListNode *head1 = nullptr, *tail1 = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!head1) {
            head1 = new ListNode(x);
            tail1 = head1;
        } else {
            tail1->next = new ListNode(x);
            tail1 = tail1->next;
        }
    }

    
    ListNode *deleteMiddleHead = deleteMiddle(head1);

    printList(deleteMiddleHead);

    return 0;
}