#include<bits/stdc++.h>
#define ll long long

using namespace std;

// burfoce
void solve(){
    int t;
    ll n;
    cin>>t;
    while (t--) // 5.10^5
    {
        cin>>n;
        int t = 0;
        ll sum = 1;
        bool check = false;
        for (int  i = 2; i < n/2; i++) //o(n^q^logq)
        {
            t = 0;
            sum = 1;
            ll mutiple = i;
            while (sum<n)
            {
                sum += mutiple;
                mutiple *=i;
                t++;
            }
            if(sum==n){
                cout<< i<<" "<<t<<endl;
                check = true;
                break;
            }
        }
        if(!check){
            cout<<"-1"<<endl;
        }
    }
    
}


void optimizing(){
    unordered_map<ll,pair<int,int>> store_value;
    for (int i = 2; i <= 1e6; i++)
    {
        ll sum = 1+ i;
        ll mutiple = i;
        int t =1;
        while (sum <1e18)
        {
            if(mutiple >1e18/i) break; // giá trị ngoài ll thì không lưu trữ làm gì vì cũng không dùng
            mutiple *=i;
            sum += mutiple;
            if(sum > 1e18) break;
            t++;
            if(store_value.find(sum) == store_value.end()) store_value[sum] = {i,t}; // {x,i}
        }
    }
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        pair<int,int> ans = {INT32_MAX,0};
        if(store_value.find(n) != store_value.end()) ans = store_value[n];
        ll den = 1 + 4*(n-1);
        if(den >= 0){
            long double x = (sqrtl(den) -1)/2.0;
            if(abs(x - round(x))< 1e-9 && x>1) ans = min (ans, {x,2});
            // Nếu độ lệch giữa x và số nguyên gần nhất nhỏ hơn 
            //1e-9 ta coi đó là một số nguyên
        }
        if(ans.first == INT32_MAX) cout<<"-1"<<endl;
        else{
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    optimizing();
    return 0;
}