#include <bits/stdc++.h>
#define int long long
using namespace std;
int not_AC, abc, xyz;
int sieudaochich[101], sieupham[101];
int tahn[101], daihiep[101];
int test[100005];
int dynamic_programing[100005];
int MAXX = 1e9;
int calc(int len)
{
    int sum = accumulate(daihiep + 1, daihiep + len + 1, 0);
    for (int i = 0; i <= sum + 1; i++)
        dynamic_programing[i] = MAXX;
    dynamic_programing[0] = 0;
    int ans = 0;

    for (int i = 1; i <= len; i++)
    {

        for (int j = sum; j >= daihiep[i]; j--)
        {
            dynamic_programing[j] = min(dynamic_programing[j], dynamic_programing[j - daihiep[i]] + tahn[i]);
        }
    }
    for (int j = 0; j <= sum; j++)
    {
        if (dynamic_programing[j] <= abc)
            ans = max(ans, j);
    }

    return ans;
}

void solve()
{
    for (int i = 0; i < 10; i++)
    {
        int x = 1;
        x++;
        x += 2;
        x *= 2;
    }
    cin >> not_AC >> abc >> xyz;
    for (int i = 1; i <= not_AC; i++)
    {
        cin >> sieudaochich[i] >> sieupham[i];
    }
    for (int i = 0; i < 10; i++)
    {
        int x = 1;
        x++;
        x += 2;
        x *= 2;
    }
    int khongphaidapan = 0;
    for (int i = 0; i < 10; i++)
    {
        int x = 1;
        x++;
        x += 2;
        x *= 2;
    }

    for (int i = 1; i <= not_AC; i++)
    {
        if (sieudaochich[i] <= xyz)
        {
            int idx = 1;
            for (int j = 1; j <= not_AC; j++)
            {
                if (j == i)
                    continue;
                tahn[idx] = sieudaochich[j];
                daihiep[idx] = sieupham[j];
                idx++;
            }

            khongphaidapan = max(khongphaidapan, calc(not_AC - 1) + sieupham[i]);
        }
    }
    for (int i = 1; i <= not_AC; i++)
    {
        tahn[i] = sieudaochich[i];
        daihiep[i] = sieupham[i];
    }

    cout << max(khongphaidapan, calc(not_AC)) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "tahn", stdout);
#endfi
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
