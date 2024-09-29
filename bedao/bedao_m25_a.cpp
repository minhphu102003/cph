#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    
    // Đếm số lẻ và số chẵn
    long long sumOdd = 0, sumEven = 0;
    int countOdd = 0, countEven = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            sumEven = (sumEven + a[i]) % MOD;
            countEven++;
        } else {
            sumOdd = (sumOdd + a[i]) % MOD;
            countOdd++;
        }
    }
    
    // Tính trọng số tổng của các cặp
    long long result = (sumOdd * countEven + sumEven * countOdd) % MOD;
    cout << result << endl;
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