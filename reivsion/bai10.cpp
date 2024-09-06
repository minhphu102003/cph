#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B008.inp","r",stdin);
    freopen("B008.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    if(k>n){
        cout<<"false";
        return 0;
    }
    int first = 0;
    int second = k;
    while(second<n && a[first] != a[second]){
        first++;
        second++;
    }
    if(second == n && a[second] != a[first]){
        cout<<"false";
    }else{
        cout<<"true";
    }
    return 0;
}