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

void optimizing (){
    int n,q;
    cin>>n>>q;
    vector<pair<ll,int>> list(n);
    int x,y,w;
    for (int  i = 0; i < n; i++)
    {
        cin>>x>>y>>w;
        list[i].first = (ll)x*x + (ll)y*y;
        list[i].second = w;
    }
    sort(list.begin(), list.end()); // sort ở đây để phục vụ tìm kiếm nhị phân
    vector<ll> preFix(n+1); // hàm trên sort thì hàm dưới này chắc chắn cũng sort theo
    for (int  i = 0; i < n; i++)
    {
        preFix[i+1] = preFix[i] + list[i].second;
    }
    while (q--)
    {
        ll r;
        cin>>r;
        r *= r;
        int ans = -1;
        int low = 0, high = n-1;
        while (low <=high)
        {
            int mid = (low + high)/2;
            if(list[mid].first <= r){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout<<preFix[ans + 1]<<"\n";  
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    
    //solve();  // Gọi hàm solve() đã chỉnh sửa
    optimizing();
    return 0;
}
