#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool isVowels(char x){
    return (x == 'a' || x == 'e' || x == 'i' || x =='o'|| x =='u');
}

int maxVowels(string s, int k) {
    int len = s.length();
    int temp = k;
    int count = 0;
    int result =  -1;
    while (temp--)
    {
        if(isVowels(s[temp])){
            count++;
        }
    }
    result = max(result, count);
    for (int  i = k; i < len; i++)
    {
        if(isVowels(s[i-k])){
            count--;
        }
        if(isVowels(s[i])){
            count++;
        }
        result = max(result, count);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string input;
    cin>>input;
    int k;
    cin>>k;
    cout<<maxVowels(input,k);
    return 0;
}