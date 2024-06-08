#include<bits/stdc++.h>
#define ll long long
using namespace std;

string cipher(string x){
    string result = "";
    int len = x.length();
    int cnt = 1;
    for (int i = 0; i < len - 1; i++) {
        if(x[i] == x[i + 1]){
            cnt++;
        } else {
            result += to_string(cnt);  
            result += x[i];
            cnt = 1;
        }
    }
    result += to_string(cnt);
    result += x[len - 1];
    return result;
}

void solve(){
    int n;
    cin >> n;
    string input;
    cin >> input;
    while(n--) {
        input = cipher(input);
    }
    cout << input << endl; 
} 

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
