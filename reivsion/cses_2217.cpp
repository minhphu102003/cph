#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B008.inp","r",stdin);
    // freopen("B008.out","w",stdout);
    int n,k;
    cin>>n>>k;
    // ý tưởng là ta sẽ tạo 2 mảng một mảng chứa index và một mảng chứa giá trị 
    int a[n+1] = {0};
    int index[n+2] = {0};
    int temp = 0;
    for (int  i = 1; i <= n; i++)
    {
        cin>>temp;
        index[temp] = i;
        a[i] = temp;
    }
    // sau khi nhập xong các phần tử vào mảng ta bắt đầu đếm
    int c = 1;
    int l = 1;
    for (int  i = 1; i <= n; i++)
    {
        if(l>index[i]){
            c++;
        }
        l = index[i];
    }
    while (k--)
    {
        		int x,y; cin>>x>>y;
		int r = a[x], s = a[y];
		swap(a[x], a[y]);
		if (index[r-1] <= index[r] && index[r-1] > y) c++;
		if (index[r-1] > index[r] && index[r-1] <= y) c--;
		if (index[r] <= index[r+1] && y > index[r+1]) c++;
		if (index[r] > index[r+1] && y <= index[r+1]) c--;		
		index[r] = y;
		if (index[s-1] <= index[s] && index[s-1] > x) c++;
		if (index[s-1] > index[s] && index[s-1] <= x) c--;
		if (index[s] <= index[s+1] && x > index[s+1]) c++;
		if (index[s] > index[s+1] && x <= index[s+1]) c--;	
		index[s] = x;
		cout<<c<<endl;
    }
    
    return 0;
}