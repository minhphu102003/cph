#include <bits/stdc++.h>
#define ll long long
const int MAX_N = 1000005;

using namespace std;

// Mảng prefix lưu trữ tổng số lượng ước và tổng các ước
vector<pair<ll, ll>> prefix(MAX_N + 1, {0, 0}); 

void sieve() {
    // Sử dụng sieve để tính số lượng ước và tổng các ước
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = i; j <= MAX_N; j += i) {
            prefix[j].first += 1;  // Tăng số lượng ước của j
            prefix[j].second += i; // Cộng i vào tổng các ước của j
        }
    }
}

// Hàm tính prefix sum cho số lượng ước và tổng các ước
void PrefixSum() {
    for (int i = 1; i <= MAX_N; i++) {
        prefix[i].first += prefix[i - 1].first; // Prefix sum cho số lượng ước
        prefix[i].second += prefix[i - 1].second; // Prefix sum cho tổng các ước
    }
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int start, end;
        cin >> start >> end;
        ll u_i = prefix[end].first - prefix[start - 1].first; // Tổng số lượng ước trong đoạn [start, end]
        ll v_i = prefix[end].second - prefix[start - 1].second; // Tổng các ước trong đoạn [start, end]
        cout << u_i << " " << v_i << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    sieve(); // Tính toán số lượng và tổng các ước trước
    PrefixSum(); // Tính prefix sum cho số lượng và tổng các ước
    solve();
    
    return 0;
}
