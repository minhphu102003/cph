#include<bits/stdc++.h>
#define ll long long 
using namespace std;


// ! Sự khác biệt giữa truyền theo giá trị và theo tham chiếu với std::vector:
// ?việc sử dụng & (tham chiếu) là cần thiết để tránh sao chép không cần thiết 
// ? và đảm bảo các thay đổi ảnh hưởng trực tiếp đến dữ liệu gốc.

ll query(vector<int>& FenwickTree, int index) {
    ll sum = 0;
    while (index > 0) {
        sum += FenwickTree[index];
        index -= index & -index; // Di chuyển đến chỉ số thấp hơn
    }
    return sum;
}

void update(vector<int>& FenwickTree, int index, int value) {
    while (index < FenwickTree.size()) {
        FenwickTree[index] += value;
        index += index & -index; // Di chuyển đến chỉ số cao hơn
    }
}

ll countInversion(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    // Sao chép và sắp xếp mảng mà không cần xóa phần tử trùng lặp
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    // Tạo Fenwick Tree
    vector<int> FenwickTree(sortedArr.size() + 1, 0);
    ll result = 0;
    for (int i = n - 1; i >= 0; i--) {
        // Tìm chỉ số phần tử trong mảng chuẩn hóa
        int pos = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin() + 1;
        // Đếm số nghịch đảo
        result += query(FenwickTree, pos - 1);
        update(FenwickTree, pos, 1);
    }
    return result;
}

// source : Fenwick tree : [https://youtu.be/KChpxPuKqoI?si=3g3InUi793Iey3V3]

int main() {
    freopen("B003.inp", "r", stdin);
    freopen("B003.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countInversion(arr) << endl;

    return 0;
}
