Given an integer array nums, rotate the array to the 
right by k steps, where k is non-negative.

//code
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(int i = 0;i<nums.size();i++){
            temp[(i+k)%nums.size()] = nums[i];
        }
        nums = temp;
    }
};
//another approach
void reverse(int arr[] , int start, int end){
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    void rotateArray(int arr[], int d, int n){
        d = d%n;
        reverse(arr,0,d-1);
        reverse(arr,d,n-1);
        reverse(arr,0,n-1);
    }
}