#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> temp = arr;

    sort(temp.begin(), temp.end());

    unordered_map<int, int> rank;
    int r = 1;

    for (int num : temp) {
        if (rank.find(num) == rank.end()) {
            rank[num] = r;
            r++;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = rank[arr[i]];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}