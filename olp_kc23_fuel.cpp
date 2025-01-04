#include<bits/stdc++.h>
#define ll long long
const int maxn = 1e5+5;

vector<pair<int,ll>> result;

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> a;
    int preheight[n];
    for (int  i = 0; i < n; i++)
    {
        int index, height;
        preheight[i] = height;
        if(i>0){
            preheight[i] += preheight[i-1];
        }
        cin>>index>>height;
        a.push_back({index,height});
    }
    ll temp = 0;
    stack<pair<ll,ll>> pre;
    if(a[0].first==1){
        pre.push(a[0]);
        result.push_back({0,0});
    }else{
        pre.push(a[0]);
        temp = (a[0].first -1)* a[0].second;
        result.push_back({0,temp});
    }
    for (int  i = 1; i < n; i++)
    {
        pair<ll,ll> b = pre.top();
        while (!pre.empty() && b.second< a[i].second)
        {
            pre.pop();
            b = pre.top();
        }
        if(pre.empty()){
            temp = (a[i].first -1) * a[i].second - 
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