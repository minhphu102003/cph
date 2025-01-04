#include<bits/stdc++.h>
#define ll long long
using namespace std;

void multiply(ll f[2][2], ll m[2][2], ll mod) {
    ll x = (f[0][0] * m[0][0] % mod + f[0][1] * m[1][0] % mod) % mod;
    ll y = (f[0][0] * m[0][1] % mod + f[0][1] * m[1][1] % mod) % mod;
    ll z = (f[1][0] * m[0][0] % mod + f[1][1] * m[1][0] % mod) % mod;
    ll t = (f[1][0] * m[0][1] % mod + f[1][1] * m[1][1] % mod) % mod;
    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = z;
    f[1][1] = t;
}

void power(ll f[2][2], ll n, ll mod) {
    if (n <= 1) return;
    ll m[2][2] = {{1, 1}, {1, 0}};
    power(f, n / 2, mod);
    multiply(f, f, mod);
    if (n % 2 == 1) multiply(f, m, mod);
}

ll fibonacci_mod(ll n, ll mod) {
    if (n == 0) return 0;
    ll f[2][2] = {{1, 1}, {1, 0}};
    power(f, n - 1, mod);
    return f[0][0] % mod;
}

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;
    ll gcd_index = __gcd(a, b);
    ll result = fibonacci_mod(gcd_index, m);
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp", "r", stdin);
    // freopen("B001.out", "w", stdout);
    solve();
    return 0;
}
