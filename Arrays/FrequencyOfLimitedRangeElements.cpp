You are given an array arr[] containing positive integers.
 These integers can be from 1 to p, and some numbers may 
 be repeated or absent. Your task is to count the frequency
  of all numbers that lie in the range 1 to n.

Note:

Do modify the array in-place changes in arr[], such that
arr[i] = frequency(i) and assume 1-based indexing.
The elements greater than n in the array can be ignored 
when counting.

//code
void frequencyCount(vector<int>& arr, int N, int P) {
    vector<int> freq(N, 0); // Auxiliary array to store frequencies
    
    for (int i = 0; i < N; i++) {
        if (arr[i] <= N) {
            freq[arr[i] - 1]++; // Increment frequency for the number
        }
    }
    
    arr = freq; // Update the input array with frequencies
}