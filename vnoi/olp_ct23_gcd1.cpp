#include<bits/stdc++.h>
#define ll long long

ll a,b,m;

using namespace std;

ll multi(ll a, ll b){
    if(b == 0) return 0;
    ll res = multi (a,b/2);
    res = (res + res) % m;
    if(b%2) res = (res + a) % m;
    return res; 
}

struct matrix {
    ll val[2][2];
    matrix() {
        memset(val, 0, sizeof val);
    }
    matrix operator * (const matrix& other) const {
        matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.val[i][j] = (res.val[i][j] + multi(val[i][k], other.val[k][j])) % m;
                }
            }
        }
        return res;
    }

    matrix operator ^ (ll n) const {
        matrix a = *this, res;
        res.val[0][0] = res.val[1][1] = 1; 
        res.val[0][1] = res.val[1][0] = 0;

        while (n > 0) {
            if (n % 2) res = res * a;
            a = a * a;
            n /= 2;
        }
        return res;
    }
};

ll fin(ll n) {
    if (n <= 1) return 1 % m;
    matrix a;
    a.val[0][0] = 1, a.val[0][1] = 1;
    a.val[1][0] = 1, a.val[1][1] = 0;
    a = a ^ (n - 1);
    return a.val[0][0];
}

void solve(){
    cin>>a>>b>>m;
    cout<<fin(__gcd(a,b));
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