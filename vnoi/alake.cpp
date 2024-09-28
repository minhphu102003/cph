#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 100005;
int pre[maxn]; //? mảng chứa các chỉ số trước cột mà ta đang xét
int late[maxn]; // ? mảng chứa các chỉ số sau cột mà ta đang xét
ll result[maxn]; // ? mảng chứa giá trị thời gian nước đầy 

void solve(){
    int n;
    cin>>n;
    int w[n+2];
    int h[n+2];
    h[0] = INT32_MAX;
    h[n+1] = INT32_MAX;
    int minimun = 1;

    for (int  i = 1; i <= n; i++)
    {
        cin>>w[i]>>h[i];
        pre[i] = i-1;
        late[i] = i +1;
        if(h[i] < h[minimun]){
            minimun = i;
        }
    }
    ll ans = 0;
    while (h[minimun]< INT32_MAX)
    {
        result[minimun] = ans + w[minimun];
        late[pre[minimun]] = late[minimun];
        pre[late[minimun]] = pre[minimun];
        if(h[late[minimun]]< h[pre[minimun]]){
            w[late[minimun]] += w[minimun];
            ans += 1ll * (h[late[minimun]] - h[minimun]) * w[minimun];
            minimun = late[minimun];
            while (h[late[minimun]] < h [minimun])
            {
                minimun = late[minimun];
            }
            
        }else{
            w[pre[minimun]] += w[minimun];
            ans += 1ll * (h[pre[minimun]] - h[minimun]) * w[minimun];
            minimun = pre[minimun];
            while (h[pre[minimun]]< h[minimun])
            {
                minimun = pre[minimun];
            }
        }
    }
    for (int  i = 1; i <= n; i++)
    {
        cout<<result[i]<<endl;
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