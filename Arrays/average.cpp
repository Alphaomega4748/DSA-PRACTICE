#include <bits/stdc++.h>
using namespace std;

int average(int arr[], int n){
    int sum =0;

    if(n==0){
        return 0;
    }

      for(int i=0;i<n;i++){
         sum += arr[i];
      }
      return sum/n;
}


int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int avg = average(arr, n);

    cout << avg << endl;

    return 0;
}