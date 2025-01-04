#include <bits/stdc++.h>
#define ll long long
const int maxn = 2e5 + 5;

int a[maxn];
ll tree[4 * maxn][10];

using namespace std;

bool containDigit(int x,int i){
    while (x> 0)
    {
        if(x%10 == i){
            return true;
        }
        x /=10;
    }
    return false;
}

void build(int node, int left, int right)
{
    if (left == right)
    {
        for (int  i = 1; i < 10; i++)
        {
            if(left % i == 0 || containDigit(left, i)){
                tree[node][i] = 2* a[left];
            }else{
                tree[node][i] = a[left];
            }
        }
    }
    else
    {
        int mid = (right + left) / 2;
        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);
        for (int  i = 1; i < 10; i++)
        {
            tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
        }
    }
}

void update(int node, int tleft, int tright, int index, int val)
{
    if (index < tleft || tright < index)
    {
        return;
    }
    if (tleft == tright)
    {
        for (int  i = 1; i < 10; i++)
        {
            if(index % i == 0 || containDigit(index, i)){
                tree[node][i] = 2* val;
            }else{
                tree[node][i] = val;
            }
        }
        return;
    }
    int mid = (tleft + tright) / 2;
    update(2 * node, tleft, mid, index, val);
    update(node * 2 + 1, mid + 1, tright, index, val);
    for (int  i = 1; i < 10; i++)
    {
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }
}

ll query(int node, int tleft, int tright, int left,int k, int right)
{
    if (right < tleft || left > tright)
    {
        return 0;
    }
    if (left <= tleft && tright <= right)
    {
        return tree[node][k];
    }
    int mid = (tleft + tright) / 2;
    return query(node * 2, tleft, mid, left,k, right) + query(node * 2 + 1, mid + 1, tright, left,k, right);
}


void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            update(1, 1, n, x, y);
            a[x] = y;
        }
        if (t == 2)
        {
            int x, y, k;
            cin >> x >> y >> k;
            ll max = query(1, 1, n, x, k, y);
            cout<<max<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("B001.inp0","r",stdin);
    // freopen("B001.out","r",stdout);
    solve();
    return 0;
}
