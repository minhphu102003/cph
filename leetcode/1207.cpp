#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    int maxn = 1005;
    unordered_map<int,int> a;
    int len = arr.size();
    for (int  i = 0; i < len; i++)
    {
        a[arr[i]]++;
    }
    set<int> check;
    cout<<endl;
    for (int  i = -1005; i < maxn; i++)
    {
        if(a[i] && !check.count(a[i])){
            check.insert(a[i]);
        }else if ( a[i] && check.count(a[i])){
            return false;
        }
    }
    return true;
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
    cout<<uniqueOccurrences(a);
    return 0;
}