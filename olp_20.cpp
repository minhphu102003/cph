#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int n, m;
    cin >> m >> n;
    map<ll, ll> base;

    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        for (ll j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                while (x % j == 0) {
                    base[j]++;
                    x /= j;
                }
            }
        }
        if (x > 1) {
            base[x]++;
        }
    }

    // for(pair<int,int> x: base){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    vector<ll> ans;
    for (int i = 0; i < n; i++) {
        map<ll, ll> temp = base;
        bool check = false;
        for (int j = 0; j < m; j++) {
            ll x;
            cin >> x;
            for (ll k = 2; k * k <= x; k++) {
                if (x % k == 0) {
                    if (temp.find(k) != temp.end()) {
                        while (x % k == 0 && temp[k] >= 0) {
                            temp[k]--;
                            x /= k;
                        }
                        if (temp[k] < 0) { 
                            check = true;
                            break;
                        }
                    } else {
                        check = true;
                        break;
                    }
                }
            }
            if (x > 1) { 
                if (temp.find(x) != temp.end() && temp[x] > 0) {
                    temp[x]--;
                } else {
                    check = true;
                }
            }
        }
        if (!check) {
            ans.push_back(i + 1);
        }
    }

    int len = ans.size();
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
