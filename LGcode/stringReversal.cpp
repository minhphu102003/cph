#include<bits/stdc++.h>
#define ll long long

using namespace std;

string solve(const vector<string>& a){
  int n = a.size();
  vector<string> b(n);
  for (int i = 0; i < n; i++)
  {
    b[i] = a[i];
    reverse(b[i].begin(), b[i].end());
  }
  const string big(n + 1, '5');
  vector<string> dp(n, big), dp1(n, big);
  dp[0] = "0";
  dp1[0] = "1";
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] <= a[i]) {
      dp[i] = min(dp[i], dp[i - 1] + "0");
    }
    if (b[i - 1] <= a[i]) {
      dp[i] = min(dp[i], dp1[i - 1] + "0");
    }
    if (a[i - 1] <= b[i]) {
      dp1[i] = min(dp1[i], dp[i - 1] + "1");
    }
    if (b[i - 1] <= b[i]) {
      dp1[i] = min(dp1[i], dp1[i - 1] + "1");
    }
  }
  string res = min(dp[n - 1], dp1[n - 1]);
  // if (res == big) return "-1";
  return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
      int n;
      cin>>n;
      vector<string> a(n);
      for (int  i = 0; i < n; i++)
      {
        cin>>a[i];
      }
      cout<<solve(a)<<endl;
    }
    return 0;
}