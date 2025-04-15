#include<bits/stdc++.h>
#define ll long long

using namespace std;


ll maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = {nums2[i], nums1[i]};
    }

    sort(pairs.rbegin(), pairs.rend());

    priority_queue<int, vector<int>, greater<int>> minHeap;
    ll sum = 0, result = 0;

    for (int i = 0; i < n; ++i) {
        sum += pairs[i].second;
        minHeap.push(pairs[i].second);

        if ((int)minHeap.size() > k) {
            sum -= minHeap.top();
            minHeap.pop();
        }

        if ((int)minHeap.size() == k) {
            result = max(result, sum * 1LL * pairs[i].first);
        }
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int  i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    maxScore(a,b,k);
    return 0;
}