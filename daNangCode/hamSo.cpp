#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix multiply(matrix &A, matrix &B) {
    int n = A.size();
    matrix C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix power(matrix A, ll p) {
    int n = A.size();
    matrix result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
        result[i][i] = 1;
    while (p) {
        if (p % 2 == 1)
            result = multiply(result, A);
        A = multiply(A, A);
        p /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    if (n == 0) {
        cout << b % MOD << endl;
        return 0;
    }
    if (n == 1) {
        cout << a % MOD << endl;
        return 0;
    }

    matrix T = {
        {3, 2, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 2, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0}
    };

    T = power(T, n - 1);

    ll Fn = (T[0][0] * a + T[0][1] * b + T[0][2] * 0 + T[0][3] * c + T[0][4] * d + T[0][5] * 0) % MOD;
    cout << Fn << endl;

    return 0;
}
