#include<bits/stdc++.h>
#define ll long long

using namespace std;

// sử dụng two pointer
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int t = n + m;

    // Kiểm tra nếu một trong hai mảng rỗng
    if (nums1.empty()) return m % 2 ? nums2[m / 2] : (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
    if (nums2.empty()) return n % 2 ? nums1[n / 2] : (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;

    int pivotFirst = 0, pivotSecond = 0;
    int currentValue = 0, preValue = 0;

    for (int i = 0; i <= t / 2; i++) {
        preValue = currentValue;
        if (pivotFirst < n && (pivotSecond >= m || nums1[pivotFirst] < nums2[pivotSecond])) {
            currentValue = nums1[pivotFirst++];
        } else {
            currentValue = nums2[pivotSecond++];
        }
    }

    if (t % 2) {
        return currentValue;
    } else {
        return (preValue + currentValue) / 2.0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    vector<int> nums1;
    vector<int> nums2;
    
    double result = findMedianSortedArrays(nums1, nums2);
    cout << fixed << setprecision(5) << result << endl;
    return 0;
}