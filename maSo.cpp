#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    string s;
    cin>>s;
    int len = s.length();
    map<char,int> a;
    for (int  i = 0; i < len; i++)
    {
        a[s[i]]++;
    }
    ll ans = 1;
    for (int  i = 0; i < len-1; i++)
    {
        ans +=(len - a[s[i]] - i);
        a[s[i]]--;
    }
    cout<<ans;
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