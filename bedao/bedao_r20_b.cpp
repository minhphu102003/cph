#include<bits/stdc++.h>
#define ll long long

using namespace std;

void sovle(){
    int n = 3;
    int subtask = 0;
    vector<int> stime, sscore, spre;
    for (int  i = 0; i < n; i++)
    {
        int k;
        cin>>k;
        for (int  j = 0; j < k; j++)
        {
            int t,d,e, mask = 0;
            cin>>t>>d>>e;
            stime.push_back(t);
            sscore.push_back((i==0 ? 6: 7)* d);
            while (e--)
            {
                int x;
                cin>>x;
                x--;
                mask |= (1<<subtask +x);
            }

            spre.push_back(mask);
        }
        subtask +=k;
    }
    
    int ans = 0;
    for (int  i = 0; i < (1<<subtask); i++)
    {
        bool flag = true;
        int t = 0, s = 0;
        for (int  j = 0; j < subtask; j++)
        {
            if(i & (1<<j)){
                if((i& spre[j]) != spre[j]){
                    flag = true;
                    break;
                }
                t += stime[j];
                s += sscore[j];
            }
        }
        if(!flag) continue;
        if(t<= 180) ans = max(ans,s);
        
    }

   cout<<fixed<<setprecision(2)<<ans/100.0; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    sovle();
    return 0;
}