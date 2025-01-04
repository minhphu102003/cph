#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 2005;
int dp[maxn][maxn] = {}; // Khởi tạo toàn bộ mảng dp về 0

void solve()
{
    string s;
    cin >> s;
    int len = s.length();

    if (len == 0) { // Xử lý trường hợp chuỗi rỗng
        cout << "" << endl;
        return;
    }

    int maxLength = 1; // Độ dài Palindrome lớn nhất
    int start = 0;     // Vị trí bắt đầu Palindrome

    // Khởi tạo: Từng ký tự là Palindrome
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }

    // Khởi tạo: Các chuỗi con độ dài 2
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            maxLength = 2;
            start = i;
        }
    }

    // Xét các chuỗi con có độ dài lớn hơn 2
    for (int l = 3; l <= len; l++) { // l là độ dài chuỗi con
        for (int i = 0; i <= len - l; i++) { // i là vị trí bắt đầu
            int j = i + l - 1; // j là vị trí kết thúc

            if (s[i] == s[j] && dp[i + 1][j - 1]) { // Kiểm tra Palindrome
                dp[i][j] = 1;
                if (l > maxLength) { // Cập nhật độ dài lớn nhất
                    maxLength = l;
                    start = i;
                }
            }
        }
    }

    // In kết quả
    cout << s.substr(start, maxLength) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);

    solve();
    return 0;
}
