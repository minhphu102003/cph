#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool canRead(vector<int>& a, int n, int time){
    int person1 = 0, person2 = 0;
    for (int i = 0; i < n; i++) {
        if (person1 <= person2) {
            person1 += a[i];  // Người 1 đọc sách
        } else {
            person2 += a[i];  // Người 2 đọc sách
        }
    }
    
    return max(person1, person2)*2 <= time;
}

void solve(vector<int>& a, int n){
    int left = accumulate(a.begin(),a.end(), 0); // Thời gian tối thiểu để đọc hết n cuốn sách
    int right = *max_element(a.begin(), a.end()) *2 ; // Thời gian tối đa để có thể đọc hết n cuốn sách
    while (left< right)
    {
        int mid  = (left + right)/2;
        if(canRead(a,n,mid)){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    cout<<left;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B008.inp","r",stdin);
    freopen("B008.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    solve(a,n);
    return 0;
}