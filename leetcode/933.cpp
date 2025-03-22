#include <bits/stdc++.h>
#define ll long long

using namespace std;

class RecentCounter
{
private:
    std::queue<int> requests;

public:
    RecentCounter() {}

    int ping(int t)
    {
        requests.push(t);
        while (!requests.empty() && requests.front() < t - 3000)
        {
            requests.pop();
        }

        return requests.size();
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);
    RecentCounter recentCounter;
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        cout<<recentCounter.ping(x)<<" ";
    }
    return 0;
}