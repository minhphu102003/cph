#include<bits/stdc++.h>
#define ll long long

using namespace std;

void moveZeroes(vector<int>& nums) {
    int left = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (nums[i] != 0) {
            swap(nums[left], nums[i]);
            left++;
        }
    }
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
    moveZeroes(a);
    for (int  i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}