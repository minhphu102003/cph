#include <bits/stdc++.h>
#define ll long long

using namespace std;
// Refer to Vnoi : [https://wiki.vnoi.info/algo/algebra/nCk]
// Sử dụng định lý phần dư trung hoa để tính nghịch đảo modulo

ll MOD;
vector<ll> pri_pw, phi, rem;
vector<vector<ll>> fact, iFact;
vector<ll> pri;

ll binpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vector<pair<ll, int>> primeFactors(ll c) {
    vector<pair<ll, int>> ans;
    for (ll i = 2; i * i <= c; ++i) {
        if (c % i == 0) {
            int count = 0;
            while (c % i == 0) {
                c /= i;
                count++;
            }
            ans.emplace_back(i, count);
        }
    }
    if (c > 1) ans.emplace_back(c, 1);
    return ans;
}

ll C(ll N, ll K, ll R, int i) {
    return (fact[i][N] * iFact[i][R] % pri_pw[i]) * iFact[i][K] % pri_pw[i];
}

int count_carry(ll n, ll k, ll r, ll p, ll t) {
    ll res = 0;
    while (n >= t) {
        res += (n / t - k / t - r / t);
        t *= p;
    }
    return res;
}

ll calc(ll N, ll K, ll R, int ord_pr) {
    if (K > N) return 0;
    ll prime = pri[ord_pr];
    ll mod = pri_pw[ord_pr];
    ll res = 1;
    int vp = count_carry(N, K, R, prime, prime);
    int vp2 = count_carry(N, K, R, prime, mod);
    while (N > 0) {
        res = (res * C(N % mod, K % mod, R % mod, ord_pr)) % mod;
        N /= prime;
        K /= prime;
        R /= prime;
    }
    res = res * binpow(prime, vp, mod) % mod;
    if ((vp2 & 1) && (prime != 2 || mod <= 4))
        res = (mod - res) % mod;
    return res;
}

void solve() {
    int k, n, c;
    cin >> k >> n >> c;
    MOD = c;

    vector<pair<ll, int>> primeFactorsRes = primeFactors(c);
    int len = primeFactorsRes.size();

    pri.resize(len);
    pri_pw.resize(len);
    phi.resize(len);
    rem.resize(len);
    fact.resize(len);
    iFact.resize(len);

    for (int i = 0; i < len; i++) {
        pri[i] = primeFactorsRes[i].first;
        ll temp = pri[i];
        for (int j = 1; j < primeFactorsRes[i].second; j++) {
            temp *= pri[i];
        }
        pri_pw[i] = temp;
        phi[i] = pri_pw[i] * (pri[i] - 1) / pri[i];

        fact[i].assign(pri_pw[i], 0);
        iFact[i].assign(pri_pw[i], 0);
        fact[i][0] = 1;
        for (int j = 1; j < pri_pw[i]; j++) {
            if (j % pri[i] != 0)
                fact[i][j] = (fact[i][j - 1] * j) % pri_pw[i];
            else
                fact[i][j] = fact[i][j - 1];
        }
        iFact[i][pri_pw[i] - 1] = binpow(fact[i][pri_pw[i] - 1],
                                            pri_pw[i] / pri[i] * (pri[i] - 1) - 1, pri_pw[i]);
        for (int j = pri_pw[i] - 1; j > 0; j--) {
            if (j % pri[i] != 0)
                iFact[i][j - 1] = (iFact[i][j] * j) % pri_pw[i];
            else
                iFact[i][j - 1] = iFact[i][j];
        }

        int tmp = c / pri_pw[i];
        rem[i] = tmp * binpow(tmp, phi[i] - 1, pri_pw[i]) % c;
    }

    ll ans = 0;
    for (int i = 0; i<len; i++) {
        ll part = calc(n, k, n - k, i) *rem[i] %c;
        ans = (ans+part) %c;
    }

    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    solve();
    return 0;
}
