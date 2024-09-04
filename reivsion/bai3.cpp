#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll mergeAndCount(vector<int>& a, int left, int mid, int right) {
    vector<int> leftArr(a.begin() + left, a.begin() + mid + 1);
    vector<int> rightArr(a.begin() + mid + 1, a.begin() + right + 1);

    ll result = 0;
    int i = 0, j = 0, k = left;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            a[k++] = leftArr[i++];
        } else {
            a[k++] = rightArr[j++];
            result += leftArr.size() - i; 
        }
    }

    while (i < leftArr.size()) a[k++] = leftArr[i++];
    while (j < rightArr.size()) a[k++] = rightArr[j++];

    return result;
}

// Hàm sắp xếp và đếm số nghịch đảo bằng thuật toán Merge Sort
ll mergeSortAndCount(vector<int>& a, int left, int right) {
    ll result = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        result += mergeSortAndCount(a, left, mid);
        result += mergeSortAndCount(a, mid + 1, right);
        result += mergeAndCount(a, left, mid, right);
    }
    return result;
}


//sử dụng merge sort để đếm cặp ngịch thể
int main() {
    freopen("B003.inp", "r", stdin);

    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Đếm số nghịch đảo
    ll inversionCount = mergeSortAndCount(A, 0, n - 1);

    // Ghi kết quả vào file B003.out
    freopen("B003.out", "w", stdout);
    cout << inversionCount << endl;

    return 0;
}



