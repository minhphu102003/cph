#include <iostream>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
const int TWO_MOD_INV = 500000004;


ll total_sum(ll start, ll end) {
    ll count = (end - start + 1) % MOD;      // Số lượng phần tử
    ll sum = (start + end) % MOD;            // Tổng của phần tử đầu và cuối
    ll res = (count * sum) % MOD;            // Tích của số lượng và tổng
    return (res * TWO_MOD_INV) % MOD;        // Nhân với nghịch đảo modular của 2
}

void solve(ll n){
    ll total = 0;
	ll start = 1;
	while (start <= n) {
		ll add_amt = n / start;  // Our divisor to process
		// The largest number that still has the same value of q
		ll last_same = n / add_amt;

		total = (total + add_amt * total_sum(start, last_same)) % MOD;
		start = last_same + 1;
	}

	cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B008.inp","r",stdin);
    // freopen("B008.out","w",stdout);
	ll n;
	cin >> n;
    solve(n);
    return 0;
}