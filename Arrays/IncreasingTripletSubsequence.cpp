Given an integer array nums, return true if there exists a
 triple of indices (i, j, k) such that i < j < k and 
 nums[i] < nums[j] < nums[k]. If no such indices exists, 
 return false.

//code

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return false;
        int smallest = INT_MAX;
        int middle = INT_MAX;
        
        for(int i=0;i<n;i++){
            if(nums[i] > middle)
                return true;
            else if(nums[i] > smallest && nums[i] < middle)
                middle = nums[i];
            else if(nums[i] < smallest)
                smallest = nums[i];
        }
        return false;
        
    }
};