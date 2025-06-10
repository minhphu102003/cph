#include <bits/stdc++.h>
#define ll long long

using namespace std;

void backtrack(int row, int n, vector<string> &board,
               vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2,
               vector<vector<string>> &result)
{
  if (row == n)
  {
    result.push_back(board);
    return;
  }

  for (int col = 0; col < n; ++col)
  {
    int d1 = row - col + n - 1;
    int d2 = row + col;
    if (cols[col] || diag1[d1] || diag2[d2])
      continue;

    board[row][col] = 'Q';
    cols[col] = diag1[d1] = diag2[d2] = true;

    backtrack(row + 1, n, board, cols, diag1, diag2, result);

    board[row][col] = '.';
    cols[col] = diag1[d1] = diag2[d2] = false;
  }
}

vector<vector<string>> solveNQueens(int n)
{
  vector<vector<string>> result;
  vector<string> board(n, string(n, '.'));
  vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
  backtrack(0, n, board, cols, diag1, diag2, result);
  return result;
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
  vector<vector<string>> result = solveNQueens(n);
  int len = result.size();
  for (int i = 0; i < len; i++)
  {
    int k = result[i].size();
    for (int j = 0; j < k; j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}