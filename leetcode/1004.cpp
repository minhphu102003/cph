#include<bits/stdc++.h>
#define ll long long

using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0;
    int count = 0;
    int result = 0;
    int len = nums.size();
    for (int  i = 0; i < len ; i++)
    {
        if(!nums[i])    count++;
        while (count >k)
        {
            if(nums[left] == 0)
             count--;
            left++;
        }
        result = max(result, i - left + 1);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<longestOnes(a,k);
    return 0;
}