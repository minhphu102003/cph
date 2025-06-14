#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool canWin(int z, int x, int val, const vector<int>& a){
  double time;
  if(z >= x){
    time = 1;
  }else{
    time = 1 + (double)(x- z)/ val;
  }
  int len = a.size();
  for (int i = 0; i < len - 1; i++)
  {
    double arrTime = (double)x/ a[i];
    if(arrTime <= time) return false;
  }
  return true;
}

int solve(int n, int x, int y, const vector<int>& a){
  int val = a[n-1];

  bool flat = true;
    for (int i = 0; i < n - 1; ++i) {
      if (val <= a[i]) {
        flat = false;
        break;
    }
    }
  if (flat) return 0;
  int l = 0; int r = y;
  int ans = -1;
  while (l <= r) {
    // cout<<l << " "<< r<< endl;
    int m = (l + r) / 2;
    if (canWin(m, x, val, a)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
    }
  return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
      int n,x,y;
      cin>>n>>x>>y;
      vector<int> a(n);
      for (int i = 0; i < n; i++)
      {
        cin>>a[i];
      }
      cout<<solve(n,x,y,a)<<endl;
    }
    return 0;
}