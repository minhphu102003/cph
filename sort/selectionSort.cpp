#include<iostream>
 
using namespace std;

void selectionSort(int a[], int n){
    for (int  i = 0; i < n-1; i++)
    {
        int min = i;
        for(int j = i +1 ; j<n;j++){
            if(a[j]< a[min])
                min = j;
        }
        if(min != i){
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    
}

int main(){
    int a[10];
    for (int  i = 0; i < 10; i++)
    {
        cin>>a[i];
    }
    selectionSort(a,10);
    for (int  i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}