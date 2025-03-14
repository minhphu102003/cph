#include<bits/stdc++.h>
#define ll long long

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    long long sum = 0;
    int temp = k;
    int len = nums.size();
    while (temp--)
    {
        sum += nums[temp];
    }
    long long result  = sum;
    for (int  i = k; i < len; i++)
    {
        sum -= nums[i - k];
        sum += nums[i];
        result = max(result,sum);
    }
    return result / (k *1.0);
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
    cout<<findMaxAverage(a,k);
    return 0;
}