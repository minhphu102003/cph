#include<bits/stdc++.h>
#define ll long long

using namespace std;

string gcdOfStrings(string str1, string str2) {
    if(str1 + str2 != str2 + str1) return "";
    int gcdLenght = gcd(str1.length(), str2.length());
    return str1.substr(0, gcdLenght);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string s,t;
    cin>>s>>t;
    cout<<gcdOfStrings(s,t);
    return 0;
}