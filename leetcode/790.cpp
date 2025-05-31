#include <bits/stdc++.h>
#define ll long long

using namespace std;

int numTilings(int n)
{
  const int MOD = 1e9 + 7;

  if (n == 0)
    return 1;
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  vector<long long> dp(n + 1);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; ++i)
  {
    dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
  }

  return dp[n];
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
  cout << numTilings(n);
  return 0;
}