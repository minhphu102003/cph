#include<bits/stdc++.h>
#define ll long long

const int maxn = 2e5+1;

using namespace std;

void findEuler(int start, vector<int> edge[], vector<int> &path){
    while (!edge[start].empty())
    {
        int v = edge[start].back();
        edge[start].pop_back();
        findEuler(v,edge,path);
    }
    path.push_back(start);
}

void solve(){
    vector<int> edge[maxn];
    vector<int> path;
    int out[maxn] = {0};
    int in[maxn] = {0};
    int n,m;
    cin>>n>>m;
    for (int  i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        out[a]++;
        in[b]++;
    }
    
    // Kiểm tra thử có phải là chu trình euleur không
    if(out[1] - in[1] != 1 || in[n] - out[n] != 1){
        cout<<"IMPOSSIBLE";
        return;
    }
    for (int  i = 2; i < n; i++)
    {
        if(in[i] != out[i]){
            cout<<"IMPOSSIBLE";
            return;
        }
    }
    findEuler(1,edge,path);

    if(path.size() != m+1){
        cout<<"IMPOSSIBLE";
        return;
    }
    reverse(path.begin(), path.end());

    for(int node : path){
        cout<<node<<" ";
    }
    cout<<endl;
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