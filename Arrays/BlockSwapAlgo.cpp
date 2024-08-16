Given an unsorted array arr[] of size n. Rotate the 
array to the left (counter-clockwise direction) by d 
steps, where d is a positive integer. 

Note: Consider the array as circular.

// Helper function to swap elements in the array
void swap(int arr[], int fi, int si, int d);

// Block Swap Algorithm
void rotateArr(int arr[], int d, int n) {
    if (d == 0 || d == n)
        return;

    if (n - d == d) {
        swap(arr, 0, n - d, d);
        return;
    }

    if (d < n - d) {
        swap(arr, 0, n - d, d);
        rotateArr(arr, d, n - d);
    } else {
        swap(arr, 0, d, n - d);
        rotateArr(arr + n - d, 2 * d - n, d);
    }
}

// Helper function to swap elements in the array
void swap(int arr[], int fi, int si, int d) {
    for (int i = 0; i < d; i++) {
        int temp = arr[fi + i];
        arr[fi + i] = arr[si + i];
        arr[si + i] = temp;
    }
}
}