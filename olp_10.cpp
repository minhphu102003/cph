#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<string> str_a(n);
    for (int  i = 0; i < n; i++)
    {
        str_a[i] = to_string(a[i]);
    }
    sort(str_a.begin(), str_a.end(), [](string &x, string &y){
        return x+y > y+x;
    });
    if (str_a[0] == "0") {
        cout <<0;
        return;
    }
    for (const string &s : str_a) {
        cout << s;
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