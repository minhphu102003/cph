#include<iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = (low -1);
    for(int j = low; j<high;j++){
        if (a[j]< pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return (i+1);
}

void quickSort(int a[], int low, int high){
    if( low < high){
        int mid = partition(a,low,high);

        quickSort(a,low, mid-1);
        quickSort(a, mid + 1, high);
    }
}

int main(){
    int a[10];
    cout << "Nhập 10 số nguyên: ";
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }

    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n - 1);

    cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}