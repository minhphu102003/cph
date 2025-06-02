#include <bits/stdc++.h>
#define ll long long

using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
  int n = text1.size();
  int m = text2.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (text1[j - 1] == text2[i - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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
  cout << longestCommonSubsequence(s1, s2);
  return 0;
}