#include<bits/stdc++.h>
#define ll long long
using namespace std;

// từ two sum trên leetcode chuyển về kiểu tương tự với O(n^2) với target thay vì một index giờ chứa 2 index  + 2 index của 2 for lồng nữa là 4

void solve(int n,int x){
    int a[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    map<int, pair<int,int>> b;
    for (int  i = 0; i < n-1; i++)
    {
        for (int  j = i+1; j < n; j++)
        {
            int target = x - a[i] - a[j];
            if(b.find(target) != b.end()){
                // index từ nhỏ đến lớn
                cout<<b[target].first + 1<<" "<<b[target].second + 1<<" "<<i +1<<" "<<j + 1;
                return;
            }
        }
        for(int k = i -1;k>=0;k--){
            // k bỏ vào first để cout nó ra từ nhỏ đến lớn
            b[a[i] + a[k]] = {k,i};
        }
    }
    cout<<"IMPOSSIBLE";
}

// Lưu mảng vào pair dùng sort thử
void solveSort(int n,int x){
    vector<pair<int,int>> a(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i].first;
        a[i].second = i +1 ;
    }
    
    sort(a.begin(), a.end());

    for (int  i = 0; i < n-3; i++)
    {
        for (int  j = i + 1; j < n-2; j++)
        {
            int target = x  - a[i].first - a[j].first;
            int left = j + 1, right = n-1;
            while (left< right)
            {
                int sum = a[left].first + a[right].first;
                if(sum == target){
                    // Nhưng mà ở đây không thể biến index mà xếp cho asc hoặc desc vì bị sort
                    cout<<a[i].second<<" "<<a[j].second<<" "<<a[left].second<<" "<<a[right].second;
                    return;
                }else if(sum>target){
                    right--;
                }else{
                    left++;
                }
            }      
        }
    }
    cout<<"IMPOSSIBLE";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n>>x;
    // solve(n,x);
    solveSort(n,x);
    return 0;
}