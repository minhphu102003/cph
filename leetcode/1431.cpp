#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int len  = candies.size();
    vector<bool> result(len);
    int target = candies[0];
    for (int i = 1; i < len; i++)
    {
        if(target < candies[i])
        target = candies[i];
    }
    for (int  i = 0; i < len; i++)
    {
        result[i] = (candies[i] + extraCandies >= target);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n,k;;
    cin>>n>>k;
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<bool> result = kidsWithCandies(a,k);
    int len = result.size();
    for (int  i = 0; i < len; i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}