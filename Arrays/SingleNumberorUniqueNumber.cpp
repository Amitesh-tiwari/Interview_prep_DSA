Given a non-empty array of integers nums, 
every element appears twice except for one.
 Find that single one.

//code
#include <vector>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for(int index = 1; index < nums.size(); index++){
            result = result ^ nums[index];
        }
        return result;
    }
};