#include<iostream>

using namespace std;

void insertionSort(int a[], int n){
    for (int  i = 1; i < n; i++)
    {
        int key =  a[i];
        int j = i-1;
        while (j>=0 && a[j]> key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}


int main(){
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}