#include<bits/stdc++.h>
#define ll long long

using namespace std;

string mergeAlternately(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    int first = 0, second = 0;
    string result = "";
    while (first < len1 && second < len2)
    {
        result.push_back(word1[first]);
        result.push_back(word2[second]);
        first ++;
        second ++;
    }
    while (first < len1)
    {
        result.push_back(word1[first]);
        first ++;
    }

    while (second < len2)
    {
        result.push_back(word2[second]);
        second ++;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string s1,s2;
    cin>>s1>>s2;
    cout<<mergeAlternately(s1,s2);
    return 0;
}