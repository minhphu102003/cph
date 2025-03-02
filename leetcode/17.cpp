#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    unordered_map<char, string> phoneMap = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> result;
    function<void(int, string)> backtrack = [&](int index, string current) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        for (char c : phoneMap[digits[index]]) {
            backtrack(index + 1, current + c);
        }
    };
    backtrack(0, "");
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);
    string digits;
    cin >> digits;
    vector<string> combinations = letterCombinations(digits);
    for (const string& combo : combinations) {
        cout << combo << '\n';
    }

    return 0;
}
