#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> result;
    int len = spells.size();
    int right = potions.size();
    for (int  i = 0; i < len; i++)
    {
        int l = 0, r = right;
        while (l < r)
        {
            int mid = (l + r)/2;
            if ((ll)spells[i] * potions[mid] >= success) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        result.push_back(right - l);
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);

    int n, m;
    ll success;
    cin >> n >> m >> success;

    vector<int> spells(n), potions(m);
    for (int i = 0; i < n; ++i) cin >> spells[i];
    for (int i = 0; i < m; ++i) cin >> potions[i];

    vector<int> res = successfulPairs(spells, potions, success);
    for (int x : res) cout << x << " ";
    cout << "\n";

    return 0;
}
