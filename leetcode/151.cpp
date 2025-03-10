#include<bits/stdc++.h>
#define ll long long

using namespace std;

string reverseWords(string s) {
    int len = s.length();
    vector<string> words;
    int i = 0;
    while (i< len)
    {
        while (i<len && s[i] == ' ') 
        {
            i++;
        }
        int j = i;
        while (j < len && s[j] != ' ') j++;
        if (i < j) {
            words.push_back(s.substr(i, j - i));
        }
        i = j + 1;
    }
    int m = words.size();
    string result;
    for (int k = m - 1; k >= 0; --k) {
        result += words[k];
        if (k > 0) result += " ";
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
    cout<<reverseWords(input);
    return 0;
}