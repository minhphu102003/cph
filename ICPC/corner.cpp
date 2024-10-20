#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int fpow(int a, int n)
{
    int res = 1;
    a %= MOD;
    while (n)
    {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
void solve()
{
    int m, n;
    cin >> m >> n;
    int p, q;
    cin >> p >> q;
    int count = 0;
    for (int i = p - 1; i <= p + 1; i++)
    {
        for (int j = q - 1; j <= q + 1; j++)
        {
            if ((i >= 1 && i <= m) && (j >= 1 && j <= n))
            {
                count++;
            }
        }
    }
    cout << --count << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
