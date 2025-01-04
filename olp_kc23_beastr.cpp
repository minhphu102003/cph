#include<bits/stdc++.h>
#define ll long long
const int maxn = 1e6+5;

using namespace std;

int a[maxn][26];

void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int index = s[0] - 'a';
    a[0][index]++;
    for (int i = 1; i < n; i++)
    {
        index = s[i] - 'a';
        for (int  j = 0; j < 26; j++)
        {
            a[i][j] = a[i-1][j];
        }
        a[i][index]++;
    }
    while (q--)
    {
        int i,j;
        cin>>i>>j;
        int count[26];
        memset(count,0,sizeof count);
        for (int k = 0; k < 26; k++) {
            if (i > 0) {
                count[k] = a[j][k] - a[i-1][k];
            } else {
                count[k] = a[j][k];
            }
        }
        int result = 0;
        for (int  k = 0; k < 26; k++)
        {
            if (count[k] % 2) result++;
        }
        cout<<result/2<<endl;
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