#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(vector<int>& a, int n, ll sum){
    sort(a.begin(),a.end());
    int median = a[n/2];
    ll cost = 0;
    for (int  i = 0; i < n/2; i++)
    {
        cost += (median - a[i]);
    }
    for (int  i = n/2; i < n; i++)
    {
        cost += (a[i] - median);
    }
    cout<<cost<<endl;
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
    ll sum = 0;
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    solve(a,n,sum);
    return 0;
}