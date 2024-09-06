#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool isPrime(int n){
    if(n<2) return false;
    if(n==2)    return true;
    for (int  i = 2; i <= n/2; i++)
    {
        if(n%i==0)  return false;
    }
    return true;
}

bool symmetrical (int n){
    int reverse = 0;
    int temp =n;
    while (n>0)
    {
        reverse *=10;
        reverse += n%10;
        n /=10;
    }
    return temp == reverse;
}


// tìm số nguyên tố đối xứng
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B008.inp","r",stdin);
    freopen("B008.out","w",stdout);
    int n;
    cin>>n;
    if(isPrime(n)&& symmetrical(n)){
        cout<<n;
    }
    else{
        cout<<0;
    }
    return 0;
}