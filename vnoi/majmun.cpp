#include<bits/stdc++.h>
#define ll long long

using namespace std;

double kc(int x1, int y1, int x2, int y2) {
    return sqrt((ll)(x1 - x2) * (x1 - x2) + (ll)(y1 - y2) * (y1 - y2));
}

double min(double a, double b) {
    return (a < b) ? a : b;
}

void solve() {
    int a, b, X, Y, n;
    cin >> a >> b >> X >> Y;
    X = X - a;
    Y = Y - b;
    int finish_x = X, finish_y = Y;
    cin >> n;
    string s;
    cin >> s;

    vector<int> h(n + 1, 0);
    vector<int> x(n + 1, 0), y(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        h[i] = (h[i-1] - s[i-1] + 48);
        if(h[i] < 0) h[i] += 8;

        if(h[i] >= 1 && h[i] <= 3) x[i] = x[i-1] + 1;
        else if(h[i] >= 5 && h[i] <= 7) x[i] = x[i-1] - 1;
        else x[i] = x[i-1];

        if(h[i] == 0 || h[i] == 1 || h[i] == 7) y[i] = y[i-1] + 1;
        else if(h[i] >= 3 && h[i] <= 5) y[i] = y[i-1] - 1;
        else y[i] = y[i-1];
    }

    double kq = kc(x[n], y[n], finish_x, finish_y);

    vector<vector<int>> f(9, vector<int>(n + 2, 0));
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= 7; j++) {
            f[j][i] = f[j][i+1];
        }
        f[h[i]][i] = f[h[i]][i+1] + 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 7; j++) {
            vector<int> g(9, 0);

            for(int k = 0; k <= 7; k++)
                g[k] = f[(k + j) % 8][i];

            int new_x = x[i-1] + g[1] + g[2] + g[3] - g[5] - g[6] - g[7];
            int new_y = y[i-1] + g[7] + g[0] + g[1] - g[3] - g[4] - g[5];
            kq = min(kq, kc(new_x, new_y, finish_x, finish_y));
        }
    }

    cout << fixed << setprecision(6) << kq << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    solve();
    return 0;
}
