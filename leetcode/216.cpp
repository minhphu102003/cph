#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> combinationSum3(int k, int n) {
        
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);

    int k,n;
    cin>>k>>n;
    
    vector<vector<int>> result = combinationSum3(k,n);
    int len = result.size();
    for (int  i = 0; i < len; i++)
    {
        int x = result[1].size();
        for (int  j = 0; j < x; j++)
        {
            cout<<result[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}