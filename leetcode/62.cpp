#include <bits/stdc++.h>
#define ll long long

using namespace std;

int uniquePaths(int m, int n)
{
  ll arr[m][n];

  for (int i = 0; i < m; i++)
    arr[i][0] = 1;
  for (int j = 0; j < n; j++)
    arr[0][j] = 1;

  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    }
  }

  return arr[m - 1][n - 1];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("B001.inp", "r", stdin);
  freopen("B001.out", "w", stdout);
  int m, n;
  cin >> m >> n;
  cout << uniquePaths(m, n);
  return 0;
}