K Largest Element
You are given an unsorted array containing ‘N’ integers.
You need to find ‘K’ largest elements from the given 
array. Also, you need to return the elements in 
non-decreasing order.

//code
// C++ code to implement the binary search approach
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

// Function to find the Kth largest element in the array
// using binary search
int findKthLargest(int arr[], int n, int k)
{
    int low = INT_MAX, high = INT_MIN;

    // Find the minimum and maximum elements in the array
    for (int i = 0; i < n; i++) {
        low = min(low, arr[i]);
        high = max(high, arr[i]);
    }

    // Perform binary search on the range of elements
    // between low and high
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        // Count the number of elements greater than mid in
        // the array
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                count++;
            }
        }

        // If there are at least K elements greater than
        // mid, search the right half
        if (count >= k) {
            low = mid + 1;
        }
        // Otherwise, search the left half
        else {
            high = mid - 1;
        }
    }

    // Return the Kth largest element
    return high;
}

// Function to print the K largest elements in the array
void printKLargest(int arr[], int n, int k)
{
    // Find the Kth largest element
    int kthLargest = findKthLargest(arr, n, k);

    // Print the K largest elements in decreasing order
    for (int i = 0; i < n; i++) {
        if (arr[i] >= kthLargest) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Driver code
int main()
{
    int arr[] = { 12, 5, 787, 1, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "K largest elements: ";
    printKLargest(arr, n, k);

    return 0;
}
// This code is contributed by Veerendra_Singh_Rajpoot
