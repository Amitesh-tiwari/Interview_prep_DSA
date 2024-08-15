Problem Statement: Rearrange the array such that the 
first half is arranged in increasing order, and the
 second half is arranged in decreasing order

 //code
    void rearrangeArray(int arr[], int n) {
        sort(arr, arr + n);
        int temp[n];
        int start = 0, end = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                temp[i] = arr[start++];
            } else {
                temp[i] = arr[end--];
            }
        }
            arr[i] = temp[i];
    }
// Time complexity: O(nlogn)
// Space complexity: O(n)
//another method
int main(){
    vector<int> arr = {3,4,5,0,6,4,6};
    int n = arr.size();
    sort(arr.begin(), arr.begin());
    int mid = n/2-1;
    for(int i = 0;i<mid;i++){
        cout<<arr[i]<<" ";
    }
    for(int i = n-1;i>mid;i--){
        cout<<arr[i]<<" ";
    }
}