#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(int a[],int n, int k,int x){
    // chúng ta dùng hàng đợi 2 đầu với số đầu tiên chứa giá trị so sánh và giá trị
    // giá trị thứ 2 chứa giá trị thực sự của từng phần tử trong mảng 
    priority_queue<pair<int,int>> dq;
    for (int  i = 0; i < n; i++)
    {
        dq.push({abs(x-a[i]),a[i]});
        if(dq.size()>k){
            dq.pop();
        }
    }
    // Đưa ra k phần tử gần nhất với x
    vector<int> result;
    while (!dq.empty()) {
        result.push_back(dq.top().second);
        dq.pop();
    }
    
    // Đảo ngược kết quả để trả về các phần tử theo thứ tự ban đầu
    sort(result.begin(), result.end());
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << "\n";
    
}
// !Xác định k số nguyên gần x nhất trong mảng n phần tử 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B008.inp","r",stdin);
    freopen("B008.out","w",stdout);
    int n,k,x;
    cin>>n>>k>>x;

    int a[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    solve(a,n,k,x);
    return 0;
}