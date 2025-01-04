#include<bits/stdc++.h>
#define ll long long
const int maxn = 2e5+5;

using namespace std;

int visited[maxn];
vector<int> u[maxn];
int b[maxn][2];
int flat = 0;
int n,m;

void dfs(int i){
    if(flat) return;
    visited[i] = 1;
    for(int v : u[i]){
        if(!visited[v]) dfs(v);
        else if(visited[v] ==  1) flat  =1;
    }
    visited[i]=2;
}

void solve(){
    cin>>n>>m;
    if(m ==0 ){
        cout<<"0";
    }else{
        for (int  i = 1; i <= m; i++)
        {
            cin>>b[i][0]>>b[i][1];
            u[b[i][0]].push_back(b[i][1]);
        }
        for (int  i = 1; i <= n; i++)
        {
            if(!visited[i]) dfs(i);
        }
        
        cout<<flat +1<<endl;
        for (int  i = 1; i <= m; i++)
        {
            if(b[i][1]> b[i][0])    cout<<1<<endl;
            else cout<<flat+1<<endl;
        }
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