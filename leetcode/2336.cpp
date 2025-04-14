#include <bits/stdc++.h>
#define ll long long

using namespace std;

class SmallestInfiniteSet {
private:
    int current;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> addedBack;

public:
    SmallestInfiniteSet() {
        current = 1;
    }

    int popSmallest() {
        if (!minHeap.empty()) {
            int smallest = minHeap.top();
            minHeap.pop();
            addedBack.erase(smallest);
            return smallest;
        } else {
            return current++;
        }
    }

    void addBack(int num) {
        if (num < current && addedBack.find(num) == addedBack.end()) {
            minHeap.push(num);
            addedBack.insert(num);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);

    int q;
    cin >> q;
    
    SmallestInfiniteSet sis;
    
    while (q--) {
        string op;
        cin >> op;

        if (op == "addBack") {
            int num;
            cin >> num;
            sis.addBack(num);
        } else if (op == "popSmallest") {
            cout << sis.popSmallest() << '\n';
        }
    }

    return 0;
}
