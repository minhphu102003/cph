#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int tree[4*maxn];

void build(int node, int left, int right) {
    if (left == right) {
        tree[node] = a[left];
    } else {
        int mid = (left + right) / 2;
        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

int query(int node, int tleft, int tright, int left, int right) {
    if (left > right) return INT_MAX;
    if (left == tleft && right == tright) return tree[node]; 
    int mid = (tleft + tright) / 2;
    return min(
        query(node * 2, tleft, mid, left, min(right, mid)),
        query(node * 2 + 1, mid + 1, tright, max(left, mid + 1), right)
    );
}

void update(int node, int tleft, int tright, int pos, int val) {
    if (tleft == tright) {
        tree[node] += val; 
    } else {
        int mid = (tleft + tright) / 2;
        if (pos <= mid) {
            update(node * 2, tleft, mid, pos, val);
        } else {
            update(node * 2 + 1, mid + 1, tright, pos, val);
        }
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) a[i] = 0; 
    build(1, 1, n);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            update(1, 1, n, y, z);
        } else {
            if (z < y) {
                int minFirst = query(1, 1, n, y, n);
                int minSecond = query(1, 1, n, 1, z);
                cout << min(minFirst, minSecond) << endl;
            } else {
                cout << query(1, 1, n, y, z) << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    solve();
    return 0;
}
