#include<bits/stdc++.h>
#define ll long long

using namespace std;

void build(int a[],int node, int start, int end, int tree[]){
    if(start == end){
        tree[node] = a[start];
    }
    else{
        int mid = (start + end)/2;
        
        build(a,node*2,start,mid,tree);

        build(a,node*2+1,mid+1,end,tree);

        tree[node] = max(tree[node*2],tree[node*2+1]);
    }
}

int query(int node, int start, int end, int left, int right, int tree[]){
    if(start>right || end< left){
        return INT32_MIN;
    }
    if(start >=left && end<=right){
        return tree[node];
    }
    int mid = (start + end) /2;
    int l = query(2*node,start,mid,left,right,tree);
    int r = query(2*node+1,mid+1,end,left,right,tree);
    return max(l,r);
}


void solve(){
    int n;
    cin>>n;
    int t;
    cin>>t;
    int a[n+1];
    for (int  i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    int tree[(n+1)*4];
    build(a,1,1,n,tree);
    for (int  i = 0; i < t; i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<query(1,1,n,x,y,tree)<<endl;
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