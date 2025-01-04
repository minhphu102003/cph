#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 1e6+5;
vector<int> u[maxn];
int c[maxn];
int n;
bool visited[maxn];
int dp[maxn][maxn];

void dfs(int i, int j){
    if(dp[i][j] || ap) return;
    visited[i] = true;
    int check = c[i];
    for(int x: u[i]){
        if(x == j) continue;
        if(!visited[x] && check == c[x]){
            dfs(x,j);
        }else{
            return;
        }
    }
}

void solve(){
    cin>>n;
    for (int  i = 1; i <=n; i++)
    {
        int x,y;
        cin>>x>>y;
        u[x].push_back(y);
        u[y].push_back(x);
    }
    for (int  i = 1; i <= n; i++)
    {
        cin>>c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
    }
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