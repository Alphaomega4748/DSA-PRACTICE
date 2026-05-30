#include <bits/stdc++.h>
using namespace std;
int LargestElement(int arr[], int n){
    int Largest = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>Largest){
        Largest = arr[i];
        }
    }
    return Largest;
}


int main() {
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int max = LargestElement(arr,n);
    cout<<"largest element is:"<<max;

    return 0;
}