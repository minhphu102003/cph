#include<bits/stdc++.h>
#define ll long long

using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
  int len = points.size();
  if(!len) return 0;
  
  sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
  });

  int ans = 1;
  int end = points[0][1];

  for (int i = 1; i < len; i++)
  {
    if(points[i][0] > end){
      ans++;
      end = points[i][1];
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
    
    return 0;
}