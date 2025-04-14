#include<bits/stdc++.h>
#define ll long long

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> q;
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        q.push(nums[i]);
    }
    for (int i = 0; i < k - 1; i++) {
        q.pop();
    }
    return q.top();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n,k;
    cin>>n,k;
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<findKthLargest(a,k);
    return 0;
}