#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int nmax = 102;

string a[nmax];

void format(int n){
    cout<<a[n].substr(0,5);
    cout<<"...";
    cout<<a[n].substr(a[n].length()-5, 5)<<endl;
}

string addString(const string &a, const string &b){
    string ans = "";
    int du = 0;
    int i = a.size() -1, j = b.size() -1;
    while (i>=0 || j>=0 || du)
    {
        int first = (i>=0) ? a[i--]-'0':0;
        int second = (j>=0) ? b[j--]-'0':0;
        int sum = first + second + du;
        du = sum/10;
        ans.push_back(sum%10 + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string mulString(const string &a, const string &b){
    int n1 = a.size();
    int n2 = b.size();
    vector<int> ans(n1+ n2,0);
    for (int  i = n1-1; i >=0 ; i--)
    {
        for (int  j = n2-1; j >=0; j--)
        {
            int mul = (a[i] - '0')* (b[j] - '0');
            int sum = mul+ ans[i+j+1];
            ans[i+j] += sum/10;
            ans[i+j+1] = sum%10; 
        }
    }
    string result = "";
    for (int x: ans)
    {
        // Xóa 0 ở đầu
        if(!(result.empty()&& x==0)){
            result.push_back(x+'0');
        }
    }
    return result;
}

void catalan(){
    a[0] = '1';
    for (int  i = 1; i < nmax; i++)
    {
        string ans = "";
        for (int  j = 0; j < i; j++)
        {
            string temp = mulString(a[j],a[i-j-1]);
            ans = addString(ans,temp);
        }
        a[i] = ans;
    }
    
}

void solve(){
    catalan();
    int n;
    while (cin>>n)
    {
        if(n%2 != 0){
            cout<<"0"<<endl;
            continue;
        }else{
            n /=2;
            if(n<=18){
                cout<<a[n]<<endl;
            }else{
                format(n);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}