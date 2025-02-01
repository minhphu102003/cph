#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <array>

using namespace std;

typedef array<int, 3> Triple; // {start, end, index}

class FenwickTree {
public:
    vector<int> bit;
    int n;

    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    int N;
    cin >> N;

    vector<Triple> intervals(N);
    set<int> unique_vals;

    // Đọc dữ liệu và lưu các giá trị duy nhất
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        intervals[i] = {x, y, i};
        unique_vals.insert(x);
        unique_vals.insert(y);
    }

    // Sắp xếp các đoạn theo thứ tự tăng dần của điểm bắt đầu, nếu cùng thì giảm dần của điểm kết thúc
    sort(intervals.begin(), intervals.end(), [](const Triple &A, const Triple &B) {
        return (A[0] == B[0]) ? (A[1] > B[1]) : (A[0] < B[0]);
    });

    // Nén tọa độ
    map<int, int> mp;
    int val_id = 1;
    for (int x : unique_vals)
        mp[x] = val_id++;

    // Fenwick Tree
    FenwickTree fenwick(2 * N);

    // Mảng kết quả
    vector<vector<int>> ans(2, vector<int>(N, 0));

    // Đếm số đoạn chứa đoạn hiện tại
    for (int i = N - 1; i >= 0; --i) {
        int y = mp[intervals[i][1]];
        int id = intervals[i][2];

        ans[0][id] = fenwick.query(y);
        fenwick.update(y, 1);
    }

    // Reset Fenwick Tree
    fenwick = FenwickTree(2 * N);

    // Đếm số đoạn bị đoạn hiện tại chứa
    for (int i = 0; i < N; ++i) {
        int y = mp[intervals[i][1]];
        int id = intervals[i][2];

        ans[1][id] = i - fenwick.query(y - 1);
        fenwick.update(y, 1);
    }

    // In kết quả
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (ans[i][j] ? 1 : 0) << " ";
        }
        cout << "\n";
    }

    return 0;
}
