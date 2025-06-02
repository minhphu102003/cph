#include <bits/stdc++.h>
#define ll long long

using namespace std;

int minDistance(string word1, string word2)
{
  int m = word1.size();
  int n = word2.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i <= m; i++)
    dp[i][0] = i;
  for (int i = 0; i <= n; i++)
    dp[0][i] = i;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (word1[i - 1] == word2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
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
  cout<<minDistance(s1,s2);
  return 0;
}