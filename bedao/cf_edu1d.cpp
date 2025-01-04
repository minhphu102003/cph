#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3+5;
int directX[4] = {1,0,-1,0}; // lên, xuống, trái, phải
int directY[4] = {0,1,0,-1};
int n,m,k;
char a[maxn][maxn];
int r[maxn][maxn]; // mảng chứa i,j thuộc thành phần liên thông thứ bao nhiêu
ll result[maxn * maxn]; // thành phần liên thông thứ i đọc được bao nhiêu bức tranh

bool check(int x, int y){
    return (x>=0 && x<n) && (y>=0 && y<m);
}

void dfs(int i,int j, int index){
    r[i][j] = index;
    for (int  k = 0; k < 4; k++)
    {
        int x = i + directX[k], y = j + directY[k];
        if(check(x,y) && a[x][y] == '*') result[index]++;
        else if(check(x,y)&& !r[x][y]) dfs(x,y,index);
    }
    
}

void solve(){
    cin>>n>>m>>k;
    for (int  i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }

    // đánh số thành phần liên thông 
    int index = 0;
    for (int  i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            if(a[i][j] == '*' || r[i][j]) continue;
            index++;
            dfs(i,j,index);
        }
    }
    while (k--)
    {
        int x,y;
        cin>>x>>y;
        cout<<result[r[--x][--y]]<<endl;
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