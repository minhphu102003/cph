#include <bits/stdc++.h>
#define ll long long

using namespace std;

int rob(vector<int> &nums)
{
  int len = nums.size();
  int dp[len + 1];
  dp[0] = nums[0];
  if (len == 1)
    return dp[0];
  dp[1] = max(nums[0], nums[1]);
  for (int i = 2; i < len; i++)
  {
    if (i == 2)
    {
      dp[i] = nums[i] + dp[i - 2];
    }
    else
    {
      dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
    }
  }
  int result = INT_MIN;
  for (int i = 0; i < len; i++)
  {
    result = max(result, dp[i]);
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
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cout << rob(a);
  return 0;
}