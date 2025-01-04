#include<bits/stdc++.h>
#define ll long long

using namespace std;  

string addString (string a, string b){
    string ans = "";
    int du = 0;
    int i = a.size() -1, j = b.size() -1;
    while(i>= 0 || j>=0 || du){
        int first = (i>=0) ? a[i--]-'0': 0;
        int second = (j>=0) ? b[j--]-'0':0;
        int sum = first + second + du;
        du  = sum/10;
        ans.push_back(sum%10 +'0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void dynamic(int n,int m){
    vector<vector<string>> a(n+1, vector<string>(m+1, "0"));
    // memset(a, 0, sizeof(a)); 
    if(m<0 && n< 0){
        cout<<0<<endl;
        return;
    }
    if(n==0 and m ==0 ){
        cout<<1<<endl;
        return;
    } 
    a[0][0] = "1";
    for (int  i = 1; i <=n; i++)
    {
        for (int  j = 1; j <=m; j++)
        {
            for (int  d = 0; d < 10; d++)
            {
                if( j >= d){
                    a[i][j] = addString(a[i][j], a[i-1][j-d]);
                }
            }
        }
    }
    string result = "";
    for (int  i = 1; i <=n ; i++)
    {
        result = addString(result, a[i][m]);
    }
    cout<<result<<endl;
}

void solve(){
    int t;
    cin>>t; 
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        dynamic(n,m);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    solve();
    return 0;
}