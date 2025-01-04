#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[19];

// Refer to  : [https://www.youtube.com/watch?v=TN0qGN0YqDQ]

ll count(ll n){
    if(n<0) return 0;
    if(n==0) return 1;
    string n_str = to_string(n);
    ll ans = 0;
    int len = n_str.size();
    for (int  i = 0; i < len; i++)
    {
        ans += dp[i];
    }
    
    int pre = 0;
    for (int  i = 0; i < len; i++)
    {
        int cur = n_str[i] -'0';
        int diff = len - i - 1;
        int less = pre<cur ? cur -1 : cur;
        ans += (cur == 0) ? 0: less* dp[diff];
        // Trường hợp đặt biệt 
        if(cur == pre){
            return ans;
        }
        pre = cur;
    }
    return ans + 1; 
}

void solve(){
    ll a, b;
    cin>>a>>b;
    dp[0] = 1;
    dp[1] = 9;
    for (int  i = 2; i < 19; i++)
    {
        dp[i] = dp[i-1] * 9;
        // cout<<dp[i]<<endl;
    }
    ll ans = count(b) - count(a-1);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    solve();
    return 0;
}