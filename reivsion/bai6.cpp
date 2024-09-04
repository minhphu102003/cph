#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B006.inp","r",stdin);
    freopen("B006.out","w",stdout);
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> a(n);
    ll result = 0;
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
        if(i<k){
            result += a[i];
        }
        else{
            cout<< result<<endl;
            result -= a[i-k];
            result += a[i];
        }
    }
    cout<< result;
    
    
    return 0;
}