Given an unsorted array arr[] of size n. Rotate the 
array to the left (counter-clockwise direction) by d 
steps, where d is a positive integer. 

Note: Consider the array as circular.

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void reverse(int arr[],int start,int end){
        while(start<end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
    void rotateArr(int arr[], int d, int n){
        // code here
        if(d>n) d=d%n;
         reverse(arr,0,d-1);
         reverse(arr,d,n-1);
         reverse(arr,0,n-1);
    }
};