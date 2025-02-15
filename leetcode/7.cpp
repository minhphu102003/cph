#include<bits/stdc++.h>
#define ll long long

using namespace std;

int reverse(int x) {
    long reversedNum = 0;
    while (x != 0) {
        int digit = x % 10;
        reversedNum = reversedNum * 10 + digit;
        x /= 10;
        if (reversedNum > INT_MAX || reversedNum < INT_MIN) {
            return 0;
        }
    }
    return static_cast<int>(reversedNum);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int x;
    cin>>x;
    cout<<reverse(x);
    return 0;
}