#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll sub1(int maxHigh, vector<int>& a, int n , int c1){
    ll ans = 0;
    for (int  i = 0; i < n; i++)
    {
        ans +=  1ll *(maxHigh - a[i]) * c1;
    }
    return ans;
} // ở dây ta luôn chọn c1

ll sub2(int maxHigh, vector<int> &a, int n, int c1, int c2){
    priority_queue<int> s;
    for (int  i = 0; i < n; i++)
    {
        if(maxHigh > a[i]) s.push(maxHigh - a[i]);
    }
    ll ans = 0;
    while (s.size()>1)
    {
        int top1 = s.top();
        s.pop();
        int top2 = s.top();
        s.pop();
        ans += 1ll*top2*c2;
        if(top1- top2 >0){
            s.push(top1 - top2);
        }
    }
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        ans += 1ll *top * c1;

    }
    return ans;
}

ll sub34(int maxHigh, vector<int>& a, int n, int c1, int c2){
    int minimun = 1e9 +5;
    ll sum = 0;
    int doubleHigh = 2 * maxHigh;
    for (int  i = 0; i < n; i++)
    {
        minimun = min(minimun,a[i]);
        sum += maxHigh - a[i];
    }
    ll ans = 9e18;
    for (int  i = maxHigh; i <= doubleHigh; i++)
    {
        ll temp = sum, priceTemp = 0;
        int maxi = i - minimun;
        temp -= maxi;
        if(temp< maxi){
            priceTemp = (1ll* c2* temp) + (1ll *c1 * (maxi - temp));
        }
        else{
            priceTemp = 1ll* c2 * maxi;
            temp -= maxi;
            priceTemp += 1ll* c2 * (temp/2);
            temp &= 1;
            if(temp) priceTemp += c1;
        }
        ans = min(ans, priceTemp);
        sum += n;
    }
    return ans;
}

void solve(){
    int n,c1,c2;
    cin>>n>>c1>>c2;
    vector<int> a(n);
    int maxHigh  = 0;
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
        maxHigh = max(maxHigh,a[i]);
    }
    // ! Ta chia theo subtask để giải bài này
    if(c1 *2 <= c2){
        cout<<sub1(maxHigh,a,n,c1);
    }
    else if(c1 <=c2){
        cout<<sub2(maxHigh,a,n,c1,c2);
    }else{
        cout<<sub34(maxHigh,a,n,c1,c2);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    solve();
    return 0;
}