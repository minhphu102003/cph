#include<bits/stdc++.h>
#define ll long long
const int maxn = 2e5+5;
int a[maxn];
ll tree[4*maxn];
using namespace std;

// ? ok
int odd(int n){
    while (n%2==0)
    {
        n/=2;
    }
    return n;
}

// ? khỏi debug 
void build(int node, int left, int right){
    if(left == right){
        tree[node] = a[left] + a[odd(left)];
    }else{
        int mid = (right+ left) /2;
        build(node * 2, left, mid);
        build(node *2 +1, mid+1, right);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update(int node, int left, int right, int index, int val){
    if(left == right){
        tree[node] = val + a[odd(index)];
    }else{
        int mid = (right+ left)/ 2;
        if(index <= mid){
            update(node*2,left,mid,index,val);
        }else{
            update(node*2+1,mid+1,right,index,val);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

// ?ok
ll query(int node, int tleft, int tright, int left, int right){
    if(left > tright || right < tleft){
        return 0;
    }
    if(left<=tleft && right >= tright){
        return tree[node];
    }
    int mid = (tright+ tleft)/2;
    return query(node*2, tleft, mid,left, right) + query(node*2+1,mid+1, tright, left, right);
}

void solve(){
    int n,q;
    cin>>n>>q;
    for (int  i = 1; i <=n; i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    while (q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1){
            a[y] = z;
            if(y%2){
                update(1,1,n,y,z);
                for (int  i = y*2; i <= n; i*=2)
                {
                    update(1,1,n,i,a[i]);
                }
            }else{
                update(1,1,n,y,z);
            }
        }else if(x==2){
            cout<<query(1,1,n,y,z)<<endl;
        }
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