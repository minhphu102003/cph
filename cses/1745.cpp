#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 105;
int a[maxn];
int dp[1000000];

void solve(){
    int n;
    cin>>n;
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll s = accumulate(a,a+n,0ll);
    dp[0] = 1;
    for (int  i = 0; i < n; i++)
    {
        for (int  j = s+1; j > 0 ; j--)
        {
            if(a[i] == j)   dp[j]  =1;
            if(a[i] <= j)   dp[j] = dp[j] | dp[j - a[i]];
        }
        
    }
    vector<int> result;
    for (int  i = 1; i <= s; i++)
    {
        if(dp[i])   result.push_back(i);
    }
    int len = result.size();
    cout<<len<<endl;
    for (int i = 0; i < len; i++)
    {
        cout<<result[i]<<" ";
    }
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