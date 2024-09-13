// ! Thuật toán phân tách trọng tâm

#include<bits/stdc++.h>

using namespace std;

const int N = 200005;

int n,k,child[N], del[N]; // del[u] kiểm tra thử đỉnh u được xóa hay chưa
vector<int> adj[N];

void countChild(int u,int parent){
    child[u] = 1;
    for(int v: adj[u]){
        if (v!= parent && !del[v]){
            countChild(v,u);
            child[u] += child[v];
        }
    }
}

int centroid(int u , int parent , int n){
    for(int v : adj[u]){
        if(v!= parent && child[v]> n/2 && !del[v]){
            return centroid(v,u,n);
        }
    }
    return u;
}

void updateAns(int root, int n){

}

long long solve(int u){
    countChild(u,0);
    
    int n = child[u];
    int root = centroid(u,0,n);

    updateAns(root,n);

    long long ans = 0;
    del[root]  =1;
    for(int v : adj[root]){
        if(!del[v]){
            ans += solve(v);
        }
    }
    return ans;
}

// ? Giải thuật này ứng dụng trong bài toán điển hình : 
// ? Cho một cây con có n đỉnh, đếm số đường đi trên cây con có đội dài k

int main(){
    cin>>n>>k;
    for (int  i = 0; i < N; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<solve(1);

    return 0;
    
}

// link : [https://wiki.vnoi.info/algo/graph-theory/centroid-decomposition.md]