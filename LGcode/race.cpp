#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

void solve() { 
    int n, k;
    cin >> n >> k;
    
    vector<int> a;
    vector<int> b;
    int temp = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp >= 0) {
            a.push_back(temp);
        } else {
            b.push_back(temp);
        }
    }
    
    ll ans = 0;
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    int na = a.size();
    for (int i = 0; i < na; i += k) {
        if (i < a.size()) {
            ans += (a[i] * 2);
        }
    }
    int nb = b.size();
    for (int i = 0; i < nb; i += k) {
        if (i < b.size()) {
            ans += abs(b[i]) * 2; 
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}
