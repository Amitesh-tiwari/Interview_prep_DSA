Given an array of digit strings nums and a digit string 
target, return the number of pairs of indices (i, j) 
(where i != j) such that the concatenation of nums[i] + 
nums[j] equals target.

//code
int numOfPairs(vector<string>& nums, string target){
        int n = nums.size();
        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i != j){
                    if(nums[i] + nums[j] == target){
                        count++;
                    }
                }
            }
        }
        return count;
}