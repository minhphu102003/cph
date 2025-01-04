#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, n + 5); 
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int k = i;
        while (k) {
            int mod = k % 10;
            dp[i] = min(dp[i], 1 + dp[i - mod]);
            k /= 10;
        }
    }
    
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}