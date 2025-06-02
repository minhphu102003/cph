#include <bits/stdc++.h>
#define ll long long

using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
  int n = prices.size(); 
  if (n == 0)
    return 0;

  int cash = 0;
  int hold = -prices[0];

  for (int i = 1; i < n; ++i)
  {
    cash = max(cash, hold + prices[i] - fee);
    hold = max(hold, cash - prices[i]);
  }

  return cash;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("B001.inp", "r", stdin);
  freopen("B001.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << maxProfit(arr, k);
  return 0;
}