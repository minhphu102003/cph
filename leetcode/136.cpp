#include <bits/stdc++.h>
#define ll long long

using namespace std;

int singleNumber(vector<int> &nums)
{
  int n = nums.size();
  int result = 0;
  for (int i = 0; i < n; i++)
  {
    result  = result ^ nums[i];
  }
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
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << singleNumber(arr);
  return 0;
}