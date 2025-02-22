#include<bits/stdc++.h>
#define ll long long

using namespace std;

int myAtoi(string s) {
    int i = 0;
    int n = s.size();
    while (i < n && s[i]== ' ')
    {
        i++;
    }
    int sign = 1;
    if (i < n  && (s[i] == '-' || s[i] == '+')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    long result = 0;
    while (i < n && isdigit(s[i]))
    {
        result = result * 10 + (s[i] - '0');
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
        i++;
    }
    return static_cast<int>(result * sign);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string input;
    cin>>input;
    cout<<myAtoi(input);
    return 0;
}