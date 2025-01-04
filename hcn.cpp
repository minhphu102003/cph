#include <iostream>
#include <vector>

using namespace std;


unsigned long long catalan(int n) {
    vector<unsigned long long> C(n + 1, 0);
    C[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            C[i] += C[j] * C[i - j - 1];
        }
    }
    
    return C[n];
}

int main() {
    int t; cin >> t;
    while (t--)
    {
int n;
   
    cin >> n;
    if (n & 1)
    {cout << 0; return 0;}
    n/= 2;
    
    string s = to_string(catalan(n));
    if (size(s) > 10)
    {
        for(int i = 0; i < 5; i++)
        {
            cout << s[i];
        }
        cout << "...";
        for(int i = size(s) - 5; i < size(s); i++) cout << s[i];
    }else cout << s;
    }
    
    
    
    return 0;
}
