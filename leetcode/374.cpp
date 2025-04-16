#include<bits/stdc++.h>
#define ll long long

using namespace std;

int pickedNumber; 

int guess(int num) {
    if (num == pickedNumber) return 0;
    else if (num > pickedNumber) return -1; 
    else return 1;
}

int guessNumber(int n) {
    int left = 1, right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = guess(mid);
        if (res == 0) return mid;
        else if (res < 0) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n;
    cin>>n;
    srand(time(0));
    pickedNumber = 1 + rand() % n;
    cout<<guessNumber(n);
    return 0;
}