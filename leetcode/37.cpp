#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool row[9][9] = {}, col[9][9] = {}, box[9][9] = {};

void solveSudoku(vector<vector<char>> &board)
{
  // backtrack(board);
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (board[i][j] != '.')
      {
        int num = board[i][j] - '1';
        int b = (i / 3) * 3 + (j / 3);
        row[i][num] = col[j][num] = box[b][num] = true;
      }
    }
  }
  backtrack(board, 0, 0);
}

bool backtrack(vector<vector<char>> &board, int r, int c)
{
  if (r == 9)
    return true;
  if (c == 9)
    return backtrack(board, r + 1, 0);
  if (board[r][c] != '.')
    return backtrack(board, r, c + 1);

  int b = (r / 3) * 3 + (c / 3);
  for (int d = 0; d < 9; ++d)
  {
    if (!row[r][d] && !col[c][d] && !box[b][d])
    {
      board[r][c] = '1' + d;
      row[r][d] = col[c][d] = box[b][d] = true;

      if (backtrack(board, r, c + 1))
        return true;

      board[r][c] = '.';
      row[r][d] = col[c][d] = box[b][d] = false;
    }
  }

  return false;
}

// bool backtrack(vector<vector<char>> &board){
//   for (int  i = 0; i < 9; i++)
//   {
//     for (int  j = 0; j < 9; j++)
//     {
//       if(board[i][j] == '.'){
//         for (char k = '1'; k <= '9'; k++)
//         {
//           if(isValid(board, i,j,k)){
//             board[i][j] = k;
//             if (backtrack(board)) return true;
//             board[i][j] = '.';
//           }
//         }
//         return false;
//       }
//     }
//   }
//   return true;
// }

bool isValid(vector<vector<char>> &board, int row, int column, char value)
{
  for (int i = 0; i < 9; i++)
  {
    if (board[i][column] == value)
      return false;
    if (board[row][i] == value)
      return false;
    int boxRow = 3 * (row / 3) + i / 3;
    int boxCol = 3 * (column / 3) + i % 3;
    if (board[boxRow][boxCol] == value)
      return false;
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("B001.inp", "r", stdin);
  freopen("B001.out", "w", stdout);
  vector<vector<char>> board(9, vector<char>(9));
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cin >> board[i][j];
    }
  }
  solveSudoku(board);
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}