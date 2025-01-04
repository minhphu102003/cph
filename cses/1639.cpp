#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 5005;
int dp[maxn][maxn];

void solve(){
    string n,m;
    cin>>n>>m;
    int a = n.length();
    int b = m.length();
    for (int  i = 1; i <= a; i++)
    {
        dp[i][0] = i;
    }
    for (int  i = 1; i <= b; i++)
    {
        dp[0][i] = i;
    }
    for (int  i = 1; i <= a; i++)
    {
        for (int  j = 1; j <= b; j++)
        {
            int temp = (n[i-1] != m[j-1]);
            dp[i][j] = min(dp[i-1][j] +1 ,min(dp[i][j-1] + 1, dp[i-1][j-1] +temp ));
        }
    }
    cout<<dp[a][b]<<endl;
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