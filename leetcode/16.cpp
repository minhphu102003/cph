#include<bits/stdc++.h>
#define ll long long

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closestSum = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; i++) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(target - sum) < abs(target - closestSum)) {
                closestSum = sum;
            }
            if (sum < target) {
                left++; 
            } else if (sum > target) {
                right--; 
            } else {
                return sum;
            }
        }
    }
    return closestSum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int target;
    cin>>target;
    cout<<threeSumClosest(nums, target);
    return 0;
}