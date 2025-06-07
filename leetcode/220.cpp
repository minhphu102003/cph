#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
{
  set<ll> window;
  int len = nums.size();
  for (int i = 0; i < len; i++)
  {
    auto pos = window.lower_bound((ll)nums[i] - valueDiff);
    if (pos != window.end() && *pos <= (ll)nums[i] + valueDiff)
      return true;
    window.insert(nums[i]);
    if (i >= indexDiff)
    {
      window.erase(nums[i - indexDiff]);
    }
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("B001.inp", "r", stdin);
  freopen("B001.out", "w", stdout);
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cout << containsNearbyAlmostDuplicate(a, k, m);
  return 0;
}