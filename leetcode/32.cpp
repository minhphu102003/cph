#include <bits/stdc++.h>
#define ll long long

using namespace std;

int longestValidParentheses(string s)
{
  int len = s.size();
  stack<int> ind;
  ind.push(-1);
  int ans = 0;
  for (int i = 0; i < len; i++)
  {
    if (s[i] == '(')
    {
      ind.push(i);
    }
    else
    {
      ind.pop();
      if (ind.empty())
      {
        ind.push(i);
      }
      else
      {
        ans = max(ans, i - ind.top());
      }
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
  string s1;
  cin >> s1;
  cout << longestValidParentheses(s1);
  return 0;
}