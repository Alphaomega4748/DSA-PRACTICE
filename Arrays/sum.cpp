#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n){
    int Sum =0;
    for(int i=0; i<n; i++){
        Sum += arr[i];
    }

    return Sum;
}


int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = sum(arr, n);

    cout << ans << endl;

    return 0;
}