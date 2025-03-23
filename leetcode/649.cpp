#include<bits/stdc++.h>
#define ll long long

using namespace std;

string predictPartyVictory(string senate) {
    int len = senate.size();
    queue<int> D;
    queue<int> R;
    for (int  i = 0; i < len; i++)
    {
        if( senate[i] == 'D'){
            D.push(i);
        }else{
            R.push(i);
        }
    }
    while (!R.empty() && !D.empty())
    {
        int r = R.front();
        int d = D.front();
        R.pop();
        D.pop();
        if(r< d){
            R.push(r + len);
        }else{
            D.push(d + len);
        }
    }
    if(!R.empty())  return "Radiant";
    return "Dire";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string input;
    cin>>input;
    cout<<predictPartyVictory(input);
    return 0;
}