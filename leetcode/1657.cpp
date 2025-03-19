#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool closeStrings(string word1, string word2) {
    int a[26], b[26];
    for (int  i = 0; i < 26; i++)
    {
        a[i] = 0;
        b[i] = 0;
    }
    int len1 = word1.length();
    int len2 = word2.length();
    for (int  i = 0; i < len1; i++)
    {
        a[word1[i] - 'a']++;
    }
    for (int i = 0; i < len2; i++)
    {
        b[word2[i] - 'a']++;
    }
    bool flat = true;
    for (int  i = 0; i < 26; i++)
    {
        if((a[i] != 0 && b[i] == 0) || (a[i]==0 && b[i] != 0)){
            flat = false;
            break;
        }
    }
    if(flat){
        sort(a,a+26);
        sort(b,b+26);
    }
    for (int  i = 0; i < 26; i++)
    {
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string input1, input2;
    cin>> input1>>input2;
    cout<<closeStrings(input1, input2);
    return 0;
}