#include<bits/stdc++.h>
#define ll long long

using namespace std;

int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int right = nums.size() -1;
    int left = 0;
    int count = 0;
    while (left < right)
    {
        if(nums[left] + nums[right] == k){
            left++;
            right--;
            count++;
        }else if(nums[left] + nums[right] > k){
            right--;
        }else{
            left++;
        }
    }
    return count;
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
    cout<<maxOperations(a,k);
    return 0;
}