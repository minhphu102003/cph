#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B008.inp","r",stdin);
    freopen("B008.out","w",stdout);
    string s;
    cin>>s;
    ll x = 0;
    ll y = 0;;
    int n = s.length();
    for (int  i = 0; i < n; i++)
    {
        if(s[i]=='N'){
            x++;
        }
        if(s[i]=='S'){
            x--;
        }
        if(s[i]=='E'){
            y++;
        }
        if(s[i]=='W'){
            y--;
        }
    }
    long double result = sqrt(x*x + y*y);
    cout<<fixed<<setprecision(4)<<result<<endl;
    return 0;
}