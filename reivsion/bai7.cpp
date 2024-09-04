#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B007.inp", "r", stdin);
    freopen("B007.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    int temp;
    //  Hàng đợi 2 đầu đùng để lưu value và index của mảng
    deque<pair<int,int>> deq;
    for (int i = 0; i < n; ++i) {
        cin>>temp;
        // Loại bỏ phần tử không nằm trong cửa sổ
        if (!deq.empty() && deq.front().second == i - k) {
            deq.pop_front();
        }
        
        // Loại bỏ các phần tử nhỏ hơn phần tử hiện tại
        while (!deq.empty() && deq.back().first <= temp) {
            deq.pop_back();
        }
        
        // Thêm chỉ số của phần tử hiện tại vào deque
        deq.push_back({temp,i});
        
        // In giá trị lớn nhất của cửa sổ hiện tại
        if (i >= k - 1) {
            cout << deq.front().first<<endl;
        }
    }

    return 0;
}