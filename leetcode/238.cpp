#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    long long mul = 1;
    int len = nums.size();
    bool flat = false;
    int count = 0;
    for (int  i = 0; i < len; i++)
    {
        if(nums[i] != 0){
            mul *= nums[i];
        }else{
            flat = true;
            count ++;
        }
    }
    for (int  i = 0; i < len; i++)
    {
        if(count > 1){
            nums[i] = 0;
        }else{
            if(flat && !nums[i]){
                nums[i] = mul;
            }else if(flat){
                nums[i] = 0;
            }else{
                nums[i] = mul/nums[i];
            }
        }
    }
    
    return nums;
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
    vector<int> result = productExceptSelf(a);
    int len = result.size();
    for (int  i = 0; i < len; i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}