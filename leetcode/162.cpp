#include<bits/stdc++.h>
#define ll long long

using namespace std;

int findPeakElement(vector<int>& nums) {
    int l = 0; int r= nums.size() -1;
    while (l < r)
    {
        int m = (l + r)/ 2;
        if (nums[m] > nums[m + 1]) r = m;
        else l = m+1;
    }
    return l;
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
    cout<<findPeakElement(a);
    return 0;
}