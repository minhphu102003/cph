#include<bits/stdc++.h>
#define ll long long

using namespace std;

string decodeString(string s) {
    stack<string> st;
    stack<int> countStack;
    string res = "";
    int num = 0;
    int len = s.length();
    for (int  i = 0; i < len; i++)
    {
        if(isdigit(s[i])){
            num = num *10 + (s[i] - '0');
        }else if(s[i] == '['){
            countStack.push(num);
            num = 0;
            st.push(res);
            res = "";
        }else if(s[i] ==']'){
            string temp = res;
            res = st.top();
            st.pop();
            int repeat = countStack.top();
            countStack.pop();
            while (repeat--)
            {
                res += temp;
            }
        }else{
            res += s[i];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string input;
    cin>>input;
    cout<<decodeString(input);
    return 0;
}