#include <bits/stdc++.h>
using namespace std;
#include<vector>

int SmallestElement(vector<int>arr){
    int n = arr.size();

    int smallest = INT_MAX;

    for(int i=0; i<n; i++){
        smallest = min(arr[i],smallest );
    }

    return smallest;
}

int main() {
 int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n; i++){
  cin>>arr[i];
}

int min = SmallestElement(arr);

cout<<"minimum values is :"<<min<<endl;

    return 0;
}