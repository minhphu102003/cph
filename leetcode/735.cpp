#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    int len = asteroids.size();
    for (int  i = 0; i < len; i++)
    {
        bool flat = false;
        while (!st.empty() && asteroids[i] < 0 && st.top() > 0) {
            if (st.top() < -asteroids[i]) {
                st.pop();
                continue;
            } else if (st.top() == -asteroids[i]) {
                st.pop();
            }
            flat = true;
            break;
        }
        if (!flat) {
            st.push(asteroids[i]);
        }
    }
    len = st.size();
    vector<int> result(len);
    for (int i = len - 1; i >= 0; --i) {
        result[i] = st.top();
        st.pop();
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<int> result = asteroidCollision(a);
    int len = result.size();
    for (int  i = 0; i < len; i++)
    {
        cout<<result[i]<<" ";
    }
    
    return 0;
}