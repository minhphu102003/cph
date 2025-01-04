#include<bits/stdc++.h>
#define ll long long
const int maxn = 101;

using namespace std;

int direction[2][2] = {{0,1},{1,0}};
int a[maxn][maxn];
string dp[maxn+1][maxn+1];

string addString(const string &a, const string &b){
    string ans = "";
    int du = 0;
    int i = a.size()-1, j = b.size()-1;
    while (i >=0 || j>=0 || du )
    {
        int first = (i>=0)? a[i--]- '0': 0;
        int second = (j>=0) ? b[j--]- '0':0;
        int sum = first + second + du;
        du = sum/10;
        ans.push_back(sum%10+'0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

ll dfs(int x,int y, int n){
    //? check trường hợp ra ngoài hoặc va phải đá 
    if(x>=n|| y>=n|| a[x][y]==1){
        return 0;
    }
    if(x==n-1&& y ==n-1){
        return 1;
    }
    ll ans = 0;
    for (int  i = 0; i < 2; i++)
    {
        int nextX = x+ direction[i][0];
        int nextY  = y+ direction[i][1];
        ans +=dfs(nextX, nextY, n);
    }
    return ans;
}  

void dynamic(int n){
    if (a[0][0] == 0) {
        dp[1][1] = '1';
    }
    for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (a[i-1][j-1] == 1) {
            dp[i][j] = '0';  
        } else {
            if (i > 1) dp[i][j] = addString(dp[i][j], dp[i-1][j]);
            if (j > 1) dp[i][j] = addString(dp[i][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][n];
}

void solve(){
    int n,m;
    cin>>n>>m;
    for (int  i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        a[x-1][y-1] = 1;
    }
    // cout<<dfs(1,1,n);
    // cout<<endl;
    dynamic(n);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    solve();
    return 0;
}