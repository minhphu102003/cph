#include<bits/stdc++.h>
#define ll long long

using namespace std;

int pivotIndex(vector<int>& nums) {
    int len = nums.size();
    for (int i = 1; i < len; i++)
    {
        nums[i] += nums[i-1];
    }
    if (nums[len-1] - nums[0] == 0)   return 0;
    for (int  i = 0; i < len - 1; i++)
    {
        if(nums[i] == (nums[len-1] - nums[i+1]))  return i+1;
    }
    
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<pivotIndex(a);
    return 0;
}