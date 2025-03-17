#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    map<int, int> check1;
    map<int, int> check2;
    for (int  i = 0; i < len1; i++)
    {
        if(!check1[nums1[i]]){
            check1[nums1[i]] = 1;
        }
    }
    vector<int> result1, result2;
    for (int  i = 0; i < len2; i++)
    {
        if(!check2[nums2[i]]){
            check2[nums2[i]] = 1;
        }
    }
    for ( pair<int,int> a : check2)
    {
        if(!check1[a.first]){
            result2.push_back(a.first);
        }
    }
    for ( pair<int,int> a : check1)
    {
        if(!check2[a.first]){
            result1.push_back(a.first);
        }
    }
    vector<vector<int>> result;
    result.push_back(result1);
    result.push_back(result2);
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int  i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    vector<vector<int>> result = findDifference(a,b);
    int len = result.size();
    for (int  i = 0; i < len; i++)
    {
        for (int  j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}