#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a = 1,b = 0;
    while (n > 0)
    {
        for (int  i = 2; i <= n; i+=2)
        {
            cout<< a * i + b << " ";
        }
        if (n&1)
        cout<< a + b <<" ", b+= a;
        else b -= a;
        a <<= 1;
        n >>= 1;
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