#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(vector<int>& a, int n){
    ll x = 1;
    for (int  i = 0; i < n; i++)
    {
        if(a[i]> x){
            cout<<x;
            return;
        }
        x += a[i];
    }
    cout<<x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B008.inp","r",stdin);
    freopen("B008.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    solve(a,n);
    return 0;
}