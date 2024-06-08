#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[105];
map<int, int> check;

void solve()
{
    int n;
    cin >> n;
    int b, c;
    int cnt = 1;
    while (n--)
    {
        cin >> b >> c;
        if (a[c] || a[b])
        {
            if (a[c])
            {
                if (a[b])
                {
                    for (int i = 0; i < 105; i++)
                    {
                        if (a[i] = a[b])
                        {
                            check[a[c]]++;
                            a[i] = a[c];
                        }
                    }
                }
                a[b] = a[c];
            }
            else
            {
                if (a[c])
                {
                    for (int i = 0; i < 105; i++)
                    {
                        if (a[i] = a[c])
                        {
                            check[a[b]]++;
                            a[i] = a[b];
                        }
                    }
                }
                check[a[b]]++;
                a[c] = a[b];
            }
        }
        else
        {
            cnt++;
            check[cnt] = 2;
            a[b] = a[c] = cnt;
        }
    }
    int maxK = 0;
    for (auto &x : check)
    {
        maxK = max(maxK, x.second);
    }
    cout << maxK << endl;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
