#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 1005;
const int maxdp = 1e5 + 5;
int h[maxn], s[maxn];
ll dp[maxdp];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> h[i]; // Đọc giá trị của sách
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i]; // Đọc điểm số của sách
    }
    for (int  i = 0; i < n; i++)
    {
        for (int j = x; j >0; j--)
        {
            if( j >= h[i]){
                dp[j] = max(dp[j], dp[j - h[i]]+ s[i]);
            }
        }
    }
    
    cout << dp[x] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp", "r", stdin);
    // freopen("B001.out", "w", stdout);
    solve();
    return 0;
}
