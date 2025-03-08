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

struct Compare
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

    for (auto list : lists)
    {
        if (list)
            pq.push(list);
    }

    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (!pq.empty())
    {
        ListNode *node = pq.top();
        pq.pop();

        tail->next = node;
        tail = node;

        if (node->next)
            pq.push(node->next);
    }

    return dummy.next;
}

ListNode* createLinkedList(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

vector<ListNode*> readInput() {
    vector<ListNode*> lists;
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> values;
        int num;
        while (ss >> num) {
            values.push_back(num);
        }
        if (!values.empty()) {
            lists.push_back(createLinkedList(values));
        }
    }

    return lists;
}

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void writeOutput(ListNode* head) {
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

    vector<ListNode*> lists = readInput();
    ListNode* mergedList = mergeKLists(lists);

    writeOutput(mergedList);

    return 0;
}