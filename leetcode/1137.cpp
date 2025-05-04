#include <bits/stdc++.h>
#define ll long long

using namespace std;

int tribonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    int t0 = 0, t1 = 1, t2 = 1;
    for (int i = 3; i <= n; ++i)
    {
        int next = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = next;
    }
    return t2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);
    int n;
    cin >> n;
    cout << tribonacci(n);
    return 0;
}