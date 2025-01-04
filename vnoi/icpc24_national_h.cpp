#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,x;
        cin>>n>>x;
        int a[n];
        int b[n];
        for (int  i = 0; i < n; i++)
        {
            cin>>a[i];
            if(a[i] != -1){
                b[i] = a[i]; 
            }else{
                b[i] = x;
            }
        }
        sort(b,b+n);
        // cout<<a[n/2]<<endl;
        // cout<<b[n/2]<<endl;
        if(b[n/2]==x){
            cout<<"YES"<<endl;
            for (int i = 0; i < n; i++)
            {
                if(a[i] != -1){
                    cout<<a[i]<<" ";
                }else{
                    cout<<x<<" ";
                }
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    solve();
    return 0;
}