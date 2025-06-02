#include <bits/stdc++.h>
#define ll long long

using namespace std;

int minFlips(int a, int b, int c)
{
  int ans = 0;
  for (int  i = 0; i < 32; i++)
  {
    int abi = (a>>i) & 1;
    int bbi = (b>>i) & 1;
    int cbi = (c>>i) & 1;
    if((abi | bbi) != cbi){
      if(!cbi){
        ans += abi + bbi;
      }else{
        ans += 1;
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
  int a, b, c;
  cin >> a >> b >> c;
  cout << minFlips(a, b, c);
  return 0;
}