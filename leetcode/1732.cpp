#include<bits/stdc++.h>
#define ll long long

using namespace std;

int largestAltitude(vector<int>& gain) {
    int len = gain.size();
    int result = max(0, gain[0]);
    for (int  i = 1; i < len; i++)
    {
        gain[i] += gain[i-1];
        result = max(result, gain[i]);
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
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<largestAltitude(a);
    return 0;
}