#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;

    // Tập chứa vị trí của các đèn giao thông
    set<int> a{0, x};
    // Tập chứa khoảng cách giữa các đèn giao thông
    multiset<int> distance{x};

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        // Tìm vị trí đèn ngay trước và sau vị trí t
        auto upper = a.upper_bound(t);
        auto lower = upper;
        --lower;

        // Xóa khoảng cách cũ
        auto it = distance.find(*upper - *lower);
        if (it != distance.end()) distance.erase(it);

        // Thêm khoảng cách mới
        distance.insert(*upper - t);
        distance.insert(t - *lower);

        // Thêm vị trí đèn mới vào tập
        a.insert(t);

        // In khoảng cách lớn nhất
        auto ans = distance.end();
        --ans;
        cout << *ans << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Đọc từ file (hoặc bỏ nếu không sử dụng file)
    // freopen("B001.inp", "r", stdin);
    // freopen("B001.out", "w", stdout);
    solve();
    return 0;
}
