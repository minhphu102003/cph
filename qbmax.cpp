#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 105;
int n, m;
int a[maxn][maxn], b[maxn][maxn];

void solve() {
    cin >> n >> m;
    
    // Nhập giá trị mảng
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Khởi tạo giá trị cột đầu tiên cho mảng b
    for (int i = 0; i < n; i++) {
        b[i][0] = a[i][0];
    }

    // Tính giá trị tối ưu cho từng ô
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int temp = INT_MIN;

            if (i - 1 >= 0) temp = max(temp, b[i - 1][j - 1]); // Trái trên
            temp = max(temp, b[i][j - 1]);                     // Trái ngang
            if (i + 1 < n) temp = max(temp, b[i + 1][j - 1]);  // Trái dưới

            b[i][j] = a[i][j] + temp;
        }
    }

    // Tìm giá trị lớn nhất ở cột cuối
    int maxn = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxn = max(maxn, b[i][m - 1]);
    }

    cout << maxn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);
    solve();
    return 0;
}
