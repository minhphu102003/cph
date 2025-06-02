#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> countBits(int n)
{
  vector<int> arr(n + 1, 0);
  for (int i = 1; i < n; i++)
  {
    arr[i] = arr[i >> i] + (i & 1);
  }
  return arr;
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
  vector<int> arr = countBits(n);
  int len = arr.size();
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i] << " ";
  }
  cout << endl;
  return 0;
}