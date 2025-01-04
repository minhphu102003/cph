#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int n;
    cin>>n;
    while (n--)
    {
        int a[3];
        int t;
        cin>>a[0]>>a[1]>>a[2]>>t;
        int count = 0;
        while (t>=0)
        {
            t -= a[count];
            if(t>=0){
                count++;
            }
            count %=3;
        }
        if(count==0){
            cout<<"Guiding Beat"<<endl;
        }else if(count==1){
            cout<<"Warning Beat"<<endl;
        }else{
            cout<<"Resting Phase"<<endl;  
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