#include <bits/stdc++.h>
#define ll long long

using namespace std;

int totalNQueens(int n)
{
  int count = 0;
  vector<bool> cols(n, false);         
  vector<bool> diag1(2 * n - 1, false); 
  vector<bool> diag2(2 * n - 1, false);

  function<void(int)> backtrack = [&](int row)
  {
    if (row == n)
    {
      count++;
      return;
    }
    for (int col = 0; col < n; col++)
    {
      if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
        continue;

      cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

      backtrack(row + 1);

      cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
    }
  };

  backtrack(0);
  return count;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("B001.inp", "r", stdin);
  freopen("B001.out", "w", stdout);

  return 0;
}