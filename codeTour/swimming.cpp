#include<bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    int result = n / k;
    if (n % k != 0) {
        result++;
    }

    // Compute result * (result + 1) safely using long long
    ll result_ll = result;
    ll x = result_ll * (result_ll + 1) / 2;

    cout << x << endl;
}

int main(){
    solve();
    return 0;
}