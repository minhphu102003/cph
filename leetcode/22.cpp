#include<bits/stdc++.h>
#define ll long long

using namespace std;

void backtrack(vector<string> &res, string cur, int open, int close, int n) {
    if (cur.length() == 2 * n) {
        res.push_back(cur);
        return;
    }
    if (open < n) {
        backtrack(res, cur + "(", open + 1, close, n);
    }
    if (close < open) {
        backtrack(res, cur + ")", open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack(res, "", 0, 0, n);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n;
    cin>>n;
    vector<string> s = generateParenthesis(n);
    int len = s.size();
    for (int  i = 0; i < len; i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}