#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool isMatch(string s, string p)
{
  int m = s.size(), n = p.size();
  vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

  dp[0][0] = true;
  for (int j = 1; j <= n; ++j)
  {
    if (p[j - 1] == '*')
      dp[0][j] = dp[0][j - 1];
  }

  for (int i = 1; i <= m; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      if (p[j - 1] == '*')
      {
        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
      }
      else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
    }
  }

  return dp[m][n];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("B001.inp", "r", stdin);
  freopen("B001.out", "w", stdout);
  string s1, s2;
  cin >> s1 >> s2;
  cout << isMatch(s1, s2);
  return 0;
}