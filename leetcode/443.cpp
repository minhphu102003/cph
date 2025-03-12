#include<bits/stdc++.h>
#define ll long long

using namespace std;

int compress(vector<char>& chars) {
    int first = 0;
    int second = 0;
    int len = chars.size();
    
    while (second < len)
    {
        char current = chars[second];
        int count = 0;
        while (second < len && chars[second] == current)
        {
            second++;
            count++;
        }
        chars[first++] = current;
        if(count > 1){
            for (char digit : to_string(count))
            {
                chars[first++] = digit;
            }
            
        }
    }
    return first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    vector<char> chars;
    char ch;
    
    while (cin >> ch) {
        chars.push_back(ch);
    }

    int newLength = compress(chars);

    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;
    return 0;
}