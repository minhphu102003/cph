#include<bits/stdc++.h>
#define ll long long

using namespace std;
bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    int len = nums.size();
    for (int i = 0 ; i< len ; i++) {
        if (nums[i] <= first) {
            first = nums[i];
        } else if (nums[i] <= second) {
            second = nums[i];
        } else {
            return true;
        }
    }
    return false;
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
    cout<<increasingTriplet(a);
    return 0;
}