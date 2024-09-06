#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD  = 1e9+7;
ll F[2][2], M[2][2];

//Nhân ma trận 
void Mul(ll f[2][2], ll m[2][2]){
    ll x = (f[0][0]*m[0][0]% MOD + f[0][1]* m[1][0]% MOD);
    ll y = (f[0][0]* m[0][1]% MOD + f[0][1] * m[1][1]% MOD);
    ll t = (f[1][0] * m[0][0] % MOD + f[1][1] * m[1][0]% MOD);
    ll z = (f[1][0] * m[0][1] % MOD + f[1][1] * m[1][1]% MOD);
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = t;
    F[1][1]  =z;
}

// nhân ấn độ dành cho ma trận
void pow(ll f[2][2], ll n){
    if(n<=1)   return;
    pow(f,n/2);
    Mul(f,f);
    if(n%2) Mul(f,M);
}

void sovle(ll n){
    F[0][0] =F[0][1] = F[1][0] = 1;
    F[1][1] = 0;
    M[0][0] = M[1][0] = M [0][1] = 1;
    M[1][1] = 0;
    if(n==0)    cout<<0;
    else{
        pow(F,n);
        cout<<F[0][0];
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B008.inp","r",stdin);
    freopen("B008.out","w",stdout);
    ll n;
    cin>>n;
    sovle(n);
    return 0;
}