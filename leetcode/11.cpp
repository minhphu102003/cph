#include<bits/stdc++.h>
#define ll long long

using namespace std;


int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int result = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;             
        result = max(result, h * w);           
        if (height[left] < height[right])
            left++;
        else
            right--;
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
    vector<int> height(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>height[i];
    }
    cout<<maxArea(height);
    return 0;
}