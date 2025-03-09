#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int len = flowerbed.size();

    for (int  i = 0; i < len; i++)
    {
        if (flowerbed[i] == 0 && (i ==0 || flowerbed[i-1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i+1] == 0)){
            flowerbed[i] = 1;
            count++;
            if(count >= n) return true;
        }
    }
    return (count >= n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<canPlaceFlowers(a,k);
    return 0;
}