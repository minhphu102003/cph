#include <bits/stdc++.h>
#define ll long long

using namespace std;

class SegmentTree {
public:
    SegmentTree(int size) : size(size) {
        tree.resize(4 * size, 0);
    }

    void update(int pos, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] += value;
        } else {
            int mid = (start + end) / 2;
            if (pos <= mid) {
                update(pos, value, 2 * node + 1, start, mid);
            } else {
                update(pos, value, 2 * node + 2, mid + 1, end);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int pos, int value) {
        update(pos, value, 0, 0, size - 1);
    }

    int query(int l, int r, int node, int start, int end) {
        if (r < start || l > end) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left = query(l, r, 2 * node + 1, start, mid);
        int right = query(l, r, 2 * node + 2, mid + 1, end);
        return left + right;
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size - 1);
    }

private:
    vector<int> tree;
    int size;
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    set<int> unique_vals;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        unique_vals.insert(a[i]);
    }

    vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
        unique_vals.insert(queries[i]);
    }

    unordered_map<int, int> value_to_index;
    int index = 0;
    for (int val : unique_vals) {
        value_to_index[val] = index++;
    }

    int compressed_size = unique_vals.size();
    SegmentTree seg_tree(compressed_size);

    for (int val : a) {
        seg_tree.update(value_to_index[val], 1);
    }

    for (int x : queries) {
        int idx = value_to_index[x];
        int pos = seg_tree.query(0, idx);
        cout << pos + 1 << endl;  
        seg_tree.update(idx, 1);
    }
}

int main() {
    solve();
    return 0;
}