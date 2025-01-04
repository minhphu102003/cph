#include<bits/stdc++.h>
#define ll long long

using namespace std;

void kmp(string pattern, string destination){
    int i = 0 , j = 1;
    int len = pattern.length();
    vector<int> ls(len,0);
    while (j<len)
    {
        if(pattern[i] == pattern[j]){
            ls[j] = i+1;
            i++;
            j++;
        }else{
            if(i>0){
                i = ls[i-1];
            }else{
                ls[j] = 0;
                j++;
            }
        }
    }
    i = 0 ,j = 0;
    while (j< destination.length())
    {
        if(pattern[i] == destination[j]){
            i++;
            j++;
            if(i==len){
                cout<<j - i +1 <<endl;
                return;
            }
        }else if(j < destination.length() && destination[j] != pattern[i]){
            if(i !=0){
                i = ls[i-1];
            }else{
                j++;
            }
        }
    }
    cout<<-1<<endl;
}

void solve(){
    string des;
    cin>>des;
    int k;
    cin>>k;
    while (k--)
    {
        string pattern;
        cin>>pattern;
        kmp(pattern,des);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    solve();
    return 0;
}