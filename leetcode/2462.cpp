#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll totalCost(vector<int>& costs, int k, int candidates) {
    int n = costs.size();
    ll total = 0;
    priority_queue<int, vector<int>, greater<int>> left, right;
    int i = 0, j = n - 1;
    while (i < candidates && i <= j) {
        left.push(costs[i++]);
    }
    while (j >= n - candidates && j >= i) {
        right.push(costs[j--]);
    }
    while (k--) {
        if (!left.empty() && (right.empty() || left.top() <= right.top())) {
            total += left.top();
            left.pop();
            if (i <= j) {
                left.push(costs[i++]);
            }
        } else {
            total += right.top();
            right.pop();
            if (i <= j) {
                right.push(costs[j--]);
            }
        }
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int k,h;
    cin>>k>>h;
    cout<<totalCost(a,k,h);
    return 0;
}