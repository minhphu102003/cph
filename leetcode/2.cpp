#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Hàm cộng hai danh sách liên kết
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* first = new ListNode(0);
    ListNode* ans = first;
    int temp = 0;
    
    while (l1 || l2 || temp) {
        int sum = temp;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        ans->next = new ListNode(sum % 10);
        temp = sum / 10;  // Cập nhật giá trị nhớ
        ans = ans->next;
    }
    return first->next;
}

// Hàm đọc danh sách liên kết từ file
ListNode* readListFromFile() {
    string line;
    if (!getline(cin, line)) return nullptr; // Đọc một dòng từ file

    stringstream ss(line);
    int num;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    while (ss >> num) {  // Đọc từng số trong dòng
        ListNode* newNode = new ListNode(num);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    return head;
}

// Hàm in danh sách liên kết
void printList(ListNode* head) {
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

    // Đọc hai danh sách liên kết từ file
    ListNode* l1 = readListFromFile();
    ListNode* l2 = readListFromFile();

    // Cộng hai danh sách liên kết
    ListNode* l3 = addTwoNumbers(l1, l2);

    // In kết quả ra file B001.out
    printList(l3);

    return 0;
}
