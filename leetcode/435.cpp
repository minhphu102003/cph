#include <bits/stdc++.h>
#define ll long long

using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
  sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
       { return a[1] < b[1]; });

  int count = 0;
  int prevEnd = INT_MIN;
  int len = intervals.size();
  for (int i = 0; i < len; i++)
  {
    if (intervals[i][0] < prevEnd)
    {
      count++;
    }
    else
    {
      prevEnd = intervals[i][1];
    }
  }
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