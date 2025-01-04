#include<bits/stdc++.h>
#define ll long long
const int maxn = 1e5+5;
ll n,k;
ll a[2*maxn], prefix[2*maxn];
ll bitTre[2*maxn];
using namespace std;

void update(ll x){
    for (; x <= n; x += x & (-x))
    {
        bitTre[x]++;
    }
}

ll query(ll x){
    ll ans = 0;
    for ( ; x >0; x -=x & (-x))
    {
        ans += bitTre[x];
    }
    return ans;
}

bool previous(ll x){
    for (int  i = 1 ; i <= n ; i++)
    {
        bitTre[i] = 0;
    }
    ll cnt = 0, cur = 0;
    for (int  i = 1; i <= n; i++)
    {
        update(lower_bound(prefix+1, prefix +n +1, cur) - prefix);
        cur += a[i];
        cnt += query(upper_bound(prefix+1, prefix+n+1,cur -x) - prefix  -1);
    }
    return cnt>=k;
}

void solve(){
    cin>>n>>k;
    for (int  i = 1; i <= n; i++)
    {
        cin>>a[i];
        prefix[i] = a[i - 1] + prefix[i-1];
    }
    sort(prefix +  1, prefix + n +1);

    ll left  = -1e15 , right = 1e15, ans = 0;
    while (left<=right)
    {
        ll mid = (left + right)/2;
        if(previous(mid)){
            ans = mid;
            left = mid  + 1;
        }else{
            right = mid - 1;
        }
    }
    cout<<ans<<endl;
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