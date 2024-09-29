#include<bits/stdc++.h>
#define ll long long

using namespace std;

// Hàm tính Ước Chung Lớn Nhất (GCD)
ll gcd(ll a, ll b){
    while (b)
    {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Hàm tính Bội Chung Nhỏ Nhất (LCM)
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

void solve(){
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    // Tính BCNN của các cặp
    ll lcm_ab = lcm(a, b);
    ll lcm_ac = lcm(a, c);
    ll lcm_bc = lcm(b, c);

    // Đếm số lượng số chia hết cho ít nhất hai trong ba số
    int result = 0;
    // Lặp qua tất cả các số từ 1 đến sqrt(n)
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if(i%lcm_ab == 0 || i% lcm_ac ==0 || i%lcm_bc ==0 ){
                result++;
            }
            if (i * i != n) {
                long long div = n / i;
                if (div % lcm_ab == 0 || div % lcm_ac == 0 || div % lcm_bc == 0) {
                    result++;
                }
            } 
        }
    }
    

    // Xuất kết quả
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
