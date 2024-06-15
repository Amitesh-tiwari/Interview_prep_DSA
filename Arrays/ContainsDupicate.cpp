Given an integer array nums, return true if any value appears 
at least twice in the array, 
and return false if every element is distinct.

//code

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        for(int index =0;index < nums.size(); index++){
            if(nums[index] == nums[index-1]){
                return true;
            }
        }
        return false;
    }
};