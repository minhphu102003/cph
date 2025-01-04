#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int> (b+1,1e9));
    for (int  i = 0; i <= a; i++)
    {
        for (int  j = 0; j <= b; j++)
        {
            if(i == j){
                dp[i][j] = 0;
            }else{
                for (int  k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j],dp[i][k]+ dp[i][j-k]+ 1);
                }
                for (int  k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]+1);
                }
                
            }
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