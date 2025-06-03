#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{
  sort(products.begin(), products.end());
  vector<vector<string>> result;
  string prefix = "";
  int len = searchWord.size();
  for (int  i = 0; i < len; i++)
  {
    prefix += searchWord[i];
    vector<string> sugg;
    auto it = lower_bound(products.begin(), products.end(), prefix);
    for (int  j = 0; j < 3 && it + j != products.end(); j++)
    {
      string& candidate = *(it+j);
      if(candidate.find(prefix) == 0){
        sugg.push_back(candidate);
      }else{
        break;
      }
    }
    result.push_back(sugg);
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
  cin>>n;
  string s1;
  vector<string> products (n);
  for (int  i = 0; i < n; i++)
  {
    cin>>products[i];
  }
  cin>>s1;
  vector<vector<string>> result  = suggestedProducts(products, s1);
  int len = result.size();
  for (int  i = 0; i < len; i++)
  {
    int k = result[i].size();
    for (int  j = 0; j < k; j++)
    {
      cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}