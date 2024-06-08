#include<bits/stdc++.h>

using namespace std;

void print(const vector<int>& partition) {
    for (int i = 0; i < partition.size(); ++i) {
        if (i > 0) cout << " ";
        cout << partition[i];
    }
    cout << endl;
}

void partition(int n, int max, vector<int>& current) {
    if (n == 0) {
        print(current);
        return;
    }

    for (int i = min(n, max); i >= 1; --i) {
        current.push_back(i);
        partition(n - i, i, current);
        current.pop_back();
    }
}

void gen(int n) {
    vector<int> current;
    partition(n, n, current);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    gen(n);
    return 0;
}