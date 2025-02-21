#include<bits/stdc++.h>
#define ll long long

using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1 || s.length() <= numRows) return s;

    vector<string> rows(min(numRows, int(s.length())));
    int currentRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[currentRow] += c;
        if (currentRow == 0 || currentRow == numRows - 1)
            goingDown = !goingDown;
        currentRow += goingDown ? 1 : -1;
    }

    string result;
    for (string row : rows) result += row;
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string inputString;
    int numRows;
    cin>>inputString;
    cin>>numRows;
    cout<<convert(inputString, numRows);
    return 0;
}