Sort an array in wave form
You have been given an unsorted array ‘ARR’.
Your task is to sort the array in such a way that the
array looks like a wave array.

//code
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i += 2) {
        swap(arr[i], arr[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

vector<int> waveFormArray(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i += 2) {
        swap(arr[i], arr[i + 1]);
    }
    return arr;
}