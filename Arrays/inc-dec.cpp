#include <bits/stdc++.h>
using namespace std;

void Rearrange(int arr[], int n){
    sort(arr, arr+n);
    int mid = n/2;
    for(int i=0; i<mid; i++){
        cout<<arr[i]<<" ";
    }

    for(int i=n-1; i>=mid; i--){
             cout<<arr[i]<<" ";
    }
}



int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Rearrange(arr, n);

    return 0;
}