#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9 + 7;

using namespace std;

ll giai(int x) {
    ll result = 1;
    for (int i = 2; i <= x; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

ll tinhMu(ll a, ll b) {
    ll result = 1;
    while (b) {
        if (b % 2) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

ll tophop(int n, int k) {
    return (giai(n) * tinhMu(giai(k),MOD-2)%MOD * tinhMu(giai(n-k),MOD-2)%MOD)%MOD;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int total = 0;
        for (char c : s)
        {
            if (c == '1')
                total++;
        }
        if (k == 1)
        {
            cout << 1 << endl;
            continue;
        }

        if (total % k != 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (total == 0)
        {
            cout<<tophop(n -1,k -1)<<endl;
        }
        else
        {
            int target = total / k;
            vector<int> positions;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    positions.push_back(i + 1);
                }
            }
            ll ways = 1;
            int size = positions.size();

            for (int i = 1; i < k; i++)
            {
                int start = i * target - 1;
                int end = i * target;

                if (end >= size)
                {
                    ways = 0;
                    break;
                }
                ways = (ways * (positions[end] - positions[start])) % MOD;
            }
            cout << ways << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp", "r", stdin);
    // freopen("B001.out", "w", stdout);
    solve();
    return 0;
}
