#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(ll x, ll y){
    ll left_tu = 0,left_mau= 1, right_tu=1, right_mau = 0, root_tu=1, root_mau=1;
    while (root_tu != x && root_mau != y)
    {
        if(root_tu * y > x * root_mau){
            right_tu = root_tu;
            right_mau = root_mau;
            root_tu += left_tu;
            root_mau += left_mau;
            cout<<"L";
        }else{
            left_tu = root_tu;
            left_mau = root_mau;
            root_tu += right_tu;
            root_mau += right_mau;
            cout<<"R";
        }
        // cout<<root_tu<<" "<<root_mau<<endl;
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    ll x,y;
    while (true)
    {
        cin>>x>>y;
        if(x ==1 && y ==1){
            break;
        }
        solve(x,y);
    }
    
    return 0;
}