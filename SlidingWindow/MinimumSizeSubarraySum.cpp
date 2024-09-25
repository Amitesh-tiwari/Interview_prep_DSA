Given an array of positive integers nums and a positive 
integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. 
If there is no such subarray, return 0 instead.

//code
class Solution {
    public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                ans = min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans==INT_MAX?0:ans;
    }
    
}
