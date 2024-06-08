#include <bits/stdc++.h>
#define ll long long 

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    if (N == 0) {
        cout << "CANNOT GET DESTINATION" << endl;
        return;
    }

    int maxReach = 0;
    int steps = 0;
    int lastJumpedPos = 0;

    for (int i = 0; i < N; ++i) {
        if (i > maxReach) {
            cout << "CANNOT GET DESTINATION" << endl;
            return;
        }

        maxReach = max(maxReach, i + a[i]);
        
        if (i == lastJumpedPos) {
            steps++;
            lastJumpedPos = maxReach;

            if (lastJumpedPos >= N) {
                cout << steps << endl;
                return;
            }
        }
    }

    if (maxReach >= N) {
        cout << steps << endl;
    } else {
        cout << "CANNOT GET DESTINATION" << endl;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    solve();
    
    return 0;
}