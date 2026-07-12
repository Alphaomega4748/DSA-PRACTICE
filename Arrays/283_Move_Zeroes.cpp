#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0; i<n;i++){
        cin>>nums[i];     //vecto<int>arr;
    }
   vector<int> temp;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            temp.push_back(nums[i]);
        }
    }

    int nz = temp.size();

    for (int i = 0; i < nz; i++) {
        nums[i] = temp[i];
    }

    for (int i = nz; i < n; i++) {
        nums[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}