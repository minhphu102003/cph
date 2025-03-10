#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool isVowels(char x){
    x = tolower(x);
    return (x == 'a' || x == 'e' || x == 'i' || x =='o' || x == 'u');
}

string reverseVowels(string s) {
    int left = 0;
    int right = s.length();
    while (left < right)
    {
        while (!isVowels(s[left]) && left < right)
        {
            left++;
        }
        while (!isVowels(s[right]) && right > left)
        {
            right--;
        }
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string input;
    cin>>input;
    cout<<reverseVowels(input);
    return 0;
}