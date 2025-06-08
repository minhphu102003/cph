#include <bits/stdc++.h>
#define ll long long

using namespace std;

// int firstMissingPositive(vector<int> &nums)
// {
//   sort(nums.begin(), nums.end());
//   int count = 1;
//   for (int i = 0; i < nums.size(); ++i)
//   {
//     if (nums[i] <= 0)
//       continue;
//     if (nums[i] == count)
//     {
//       count++;
//     }
//     else if (nums[i] > count)
//     {
//       return count;
//     }
//   }
//   return count;
// }

int firstMissingPositive(vector<int> &nums)
{
  int len = nums.size();
  map<int,bool> check;
  for (int  i = 0; i < len; i++)
  {
    if(nums[i] <= 0) continue;
    check[nums[i] - 1] = true;
  }
  for (int  i = 0; i < len; i++)
  {
    if(!check[i]) return i+1;
  }
  return len + 1;
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
  cout << firstMissingPositive(arr);
  return 0;
}