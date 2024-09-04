#include<bits/stdc++.h>
#define ll long long
#define maxn 1000001
using namespace std;

int A[maxn * 4]; // Segment Tree
int a[maxn];     // Mảng dữ liệu

// Hàm xây dựng Segment Tree
void build(int id, int left, int right) {
    if (left == right) {
        A[id] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    build(id * 2, left, mid);
    build(id * 2 + 1, mid + 1, right);
    A[id] = A[id * 2] + A[id * 2 + 1];
}

// Hàm cập nhật giá trị tại vị trí index
void update(int id, int left, int right, int index, int value) {
    if (index < left || index > right) {
        return;
    }
    if (left == right) {
        A[id] = value;
        return;
    }
    int mid = (left + right) / 2;
    update(id * 2, left, mid, index, value);
    update(id * 2 + 1, mid + 1, right, index, value);
    A[id] = A[id * 2] + A[id * 2 + 1];
}

// Hàm truy vấn tổng từ đoạn u đến v
int get(int id, int left, int right, int u, int v) {
    if (v < left || u > right) {
        return 0;
    }
    if (u <= left && right <= v) {
        return A[id];
    }
    int mid = (left + right) / 2;
    return get(id * 2, left, mid, u, v) + get(id * 2 + 1, mid + 1, right, u, v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B008.inp", "r", stdin);
    freopen("B008.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Xây dựng Segment Tree từ mảng a
    build(1, 1, n);

    while (k--) {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << "\n";
    }

    return 0;
}
