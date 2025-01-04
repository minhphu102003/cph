#include<bits/stdc++.h>
#define ll long long

using namespace std;

// 1e8  thì tổng số không vượt quá 1e5
const int maxn = 1e5+5;

int a[maxn];

void init(){
    a[0] = 1;
    a[1] = 1;
    for (int  i = 2; i*i < maxn; i++)
    {
        if(!a[i]){
            for (int  j = i*i; j < maxn; j+=i)
            {
                a[j] = 1;
            }   
        }
    } 
}

void solve(){
    int a,b;
    cin>>a>>b;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    solve();
    return 0;
}