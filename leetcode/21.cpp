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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode dummy;
    ListNode *tail = &dummy;

    while (list1 && list2)
    {
        if(list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next;
        }else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    return dummy.next;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);

    int n, m;
    cin >> n >> m;

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

    ListNode *head2 = nullptr, *tail2 = nullptr;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (!head2) {
            head2 = new ListNode(x);
            tail2 = head2;
        } else {
            tail2->next = new ListNode(x);
            tail2 = tail2->next;
        }
    }

    ListNode *mergedHead = mergeTwoLists(head1, head2);

    printList(mergedHead);

    return 0;
}