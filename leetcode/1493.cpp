#include<bits/stdc++.h>
#define ll long long

using namespace std;

int longestSubarray(vector<int>& nums) {
    int len = nums.size();
    int left = 0;
    int count = 0;
    int result = 0;
    for (int  i = 0; i < len; i++)
    {
        if(!nums[i]) count++;
        if(count > 1){
            while (nums[left])
            {
                left++;
            }
            left++;
            count--;
        }
        result = max(result, i - left);
    }
    return result;
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
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<longestSubarray(a);
    return 0;
}