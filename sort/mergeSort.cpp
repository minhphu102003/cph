#include<iostream>

using namespace std;


void merge(int a[], int left, int mid, int right){
    int n1 = mid - left +1 ;
    int n2 = right - mid;
    int L[n1] , R[n2];
    for (int  i = 0; i < n1; i++)
    {
        L[i] = a[i+ left];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[i+mid + 1];
    }
    int i = 0;
    int j = 0;
    int k = left;
    
    while(i<n1 && j< n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k++] = L[i++];
    }
    while (j<n2)
    {
        a[k++] = R[j++];
    }
}

void mergeSort(int a[], int l ,int r){
    if( l < r){
        int mid = l +  (r  -  l) /2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1 , r);
        merge(a,l ,mid, r);
    }
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, arr_size - 1);
    cout << "Sorted array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    return 0;
}