#include<iostream>


using namespace std;

void heapfy(int a[],int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && a[l]> a[largest]){
        largest = l;
    }
    if(r<n && a[r]> a[largest]){
        largest = r;
    }
    if(largest != i){
        swap(a[i],a[largest]);
        heapfy(a,n,largest);
    }
}


void heapSort(int a[], int n){
    for(int i = n/2 -1 ;i>=0;i--){
        heapfy(a,n,i);
    }
    for(int i = n -1 ;i>=0;i--){
        swap(a[0], a[i]);
        heapfy(a,i,0);
    }
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}