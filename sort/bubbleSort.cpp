#include<iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int a[], int n){
    bool isSwap;
    for (int  i = 0; i < n-1; i++)
    {
        isSwap = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j + 1]){
                swap(a[j],a[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            break;
        }
        
    }
    
}


int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}