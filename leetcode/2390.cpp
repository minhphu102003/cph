#include<bits/stdc++.h>
#define ll long long

using namespace std;

string removeStars(string s) {
    stack<char> result;
    int len = s.length();
    for (int  i = 0; i < len; i++)
    {
        if(s[i] == '*' && !result.empty()){
            result.pop();
        }
        if(s[i] != '*'){
            result.push(s[i]);
        }
    }
    string ans;
    while (!result.empty())
    {
        ans.push_back(result.top());
        result.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string input;
    cin>>input;
    cout<<removeStars(input);
    return 0;
}