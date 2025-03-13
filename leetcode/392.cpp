#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool isSubsequence(string s, string t) {
    int first = 0;
    int second = 0;
    int len1 = s.length();
    int len2 = t.length();
    while (first < len1 && second < len2)
    {
        if( s[first] == t[second]){
            first++;
        }
        second++;
    }
    return first == len1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string s1,s2;
    cin>>s1>>s2;
    cout<<isSubsequence(s1,s2);
    return 0;
}