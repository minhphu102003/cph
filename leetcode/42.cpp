#include <bits/stdc++.h>
#define ll long long

using namespace std;

int trap(vector<int> &height)
{
  int left = 0 ; int right = height.size() - 1;
  int leftMax = 0, rightMax = 0;
  int ans = 0;
  while (left < right)
  {
    if(height[left] < height[right]){
      if(height[left] >= leftMax){
        leftMax = height[left];
      }else{
        ans += leftMax - height[left];
      }
      left++;
    }else{
      if(height[right] >= rightMax){
        rightMax = height[right];
      }else{
        ans += rightMax - height[right];
      }
      right--;
    }
  }
  return ans;
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
  cout << trap(a);
  return 0;
}