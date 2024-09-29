#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;
long long a[MAX_N], color[MAX_N];
long long sum[4 * MAX_N], lazy[4 * MAX_N];  // Segment tree cho mỗi màu
int n, q;
map<int, vector<int>> colorIndices;  // Lưu chỉ số các phần tử theo màu

// Build the segment tree for a specific color range
void build(int node, int start, int end, const vector<int>& indices) {
    if (start == end) {
        sum[node] = a[indices[start]];  // Sử dụng các phần tử có màu tương ứng
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid, indices);
        build(2 * node + 1, mid + 1, end, indices);
        sum[node] = sum[2 * node] + sum[2 * node + 1];
    }
}

// Lazy propagation for range updates
void updateRange(int node, int start, int end, int l, int r, long long val) {
    if (lazy[node] != 0) {
        sum[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > end || start > r || end < l)
        return;

    if (start >= l && end <= r) {
        sum[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, val);
    updateRange(2 * node + 1, mid + 1, end, l, r, val);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
}

// Query to get sum in range [l, r]
long long queryRange(int node, int start, int end, int l, int r) {
    if (start > end || start > r || end < l)
        return 0;

    if (lazy[node] != 0) {
        sum[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start >= l && end <= r)
        return sum[node];

    int mid = (start + end) / 2;
    long long p1 = queryRange(2 * node, start, mid, l, r);
    long long p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

// Binary search for query type 2
int binarySearch(int col, long long y) {
    if (colorIndices[col].empty()) return 0;  // Không có phần tử nào của màu đó

    int lo = 0, hi = colorIndices[col].size() - 1, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        long long totalSum = queryRange(1, 0, colorIndices[col].size() - 1, 0, mid);  // Sử dụng segment tree để tính tổng
        if (totalSum <= y) {
            ans = mid + 1;  // Tìm được số phần tử hợp lệ (vì chỉ số bắt đầu từ 0 nên +1)
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> color[i];
        colorIndices[color[i]].push_back(i);  // Lưu chỉ số của các phần tử theo màu
    }

    for (auto& [col, indices] : colorIndices) {
        // Xây dựng segment tree cho mỗi màu
        build(1, 0, indices.size() - 1, indices);
    }

    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int col;
            long long x;
            cin >> col >> x;
            // Chỉ cập nhật các phần tử không phải màu "col"
            for (auto& idx : colorIndices) {
                if (idx.first != col) {
                    for (int i = 0; i < idx.second.size(); i++)
                        updateRange(1, 0, idx.second.size() - 1, i, i, x);
                }
            }
        } else if (type == 2) {
            int col;
            long long y;
            cin >> col >> y;
            cout << binarySearch(col, y) << "\n";
        }
    }

    return 0;
}
