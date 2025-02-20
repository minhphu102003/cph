#include<bits/stdc++.h>
#define ll long long

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if (n <= 1) return s;

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int startIndex = 0;
    int maxLength = 1;

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            startIndex = i;
            maxLength = 2;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                startIndex = i;
                maxLength = len;
            }
        }
    }

    return s.substr(startIndex, maxLength);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string input;
    cin>>input;
    cout<<longestPalindrome(input);
    return 0;
}