#include<bits/stdc++.h>
#define ll long long

using namespace std;

string convert(string s, int numRows) {
    int len = s.length();
    int currentIndex = 0;
    if (len < currentIndex) return "";
    string result;
    result.push_back(s[currentIndex]);
    cout<< s[currentIndex];
    // Tách trường hợp đặc biệt ra
    int loop = 2;
    while (currentIndex < len)
    {
        currentIndex = loop*numRows -4 + loop;
        loop++;
        if (len < currentIndex) break;
        result.push_back(s[currentIndex]);
        cout<< s[currentIndex];
    }
    int inter = 1;
    int step = 2 * numRows - 2;
    while (inter+1 < numRows)
    {
        int firstInter = inter;
        int secondInter = 2*numRows  - 2 - inter;
        while (firstInter < len)
        {
            result.push_back(s[firstInter]);
            cout<< s[firstInter];
            firstInter += step;
        }
        while (secondInter < len)
        {
            result.push_back(s[secondInter]);
            cout<< s[secondInter];
            secondInter += step;
        }
        inter++;
    }
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