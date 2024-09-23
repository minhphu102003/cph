#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 500005;

void solve(){
    ll preFix[maxn] = {0};
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        // Tính khoảng cách từ (x, y) đến (0, 0) và làm tròn lên
        float distance = sqrt(x * x + y * y);
        int roundedDistance = ceil(distance);  // Làm tròn lên và ép về kiểu int
        preFix[roundedDistance] += w;          // Cộng dồn giá trị w vào preFix[roundedDistance]
    }

    // Cộng dồn giá trị cho preFix
    for (int i = 1; i < n + 1; i++) {
        preFix[i] += preFix[i - 1];
    }

    // Xử lý các truy vấn
    while (q--) {
        int r;
        cin >> r;
        if(r> n){
            cout<<preFix[n + 1];
        }
        else cout << preFix[r] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    
    solve();  // Gọi hàm solve() đã chỉnh sửa
    return 0;
}
