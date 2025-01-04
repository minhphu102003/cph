#include<bits/stdc++.h>
#define ll long long
const int maxn = 1e3+5;

char k[maxn][maxn];
int direction[4][2] = {{-1, 0}, {0,1}, {1,0}, {0,-1}};
using namespace std;

void dfs(int i, int j){
    string result = "";
    if(k[i][j] == '#') return;
    for (int  i = 0; i < 4; i++)
    {
        
    }
    
}

void solve(){
    int n,m;
    cin>>n>>m;
    pair<int ,int> a;
    pair<int, int> b;
    for (int  i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            cin>>k[i][j];
            if(k[i][j] == 'a' || k[i][j] == 'A')    a = {i,j};
            if(k[i][j] == 'b' || k[i][j] == 'B')    b = {i,j};
        }
        
    }
    dfs(a.first,a.second);
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