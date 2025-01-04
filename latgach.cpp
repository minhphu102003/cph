#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
string a[maxn];

// Hàm cộng hai chuỗi số lớn
string addStrings(const string &num1, const string &num2) {
    string result = "";
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Tính trước dãy Fibonacci
void init() {
    a[0] = "1";  // fib(0) = 1
    a[1] = "1";  // fib(1) = 1

    for (int i = 2; i < maxn; i++) {
        a[i] = addStrings(a[i - 1], a[i - 2]);
    }
}

// Xử lý truy vấn
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);

    init();
    solve();
    return 0;
}
