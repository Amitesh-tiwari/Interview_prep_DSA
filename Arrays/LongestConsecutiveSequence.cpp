Given an unsorted array of integers nums, 
return the length of the longest consecutive 
elements sequence.

You must write an algorithm that runs in O(n) time.
//code

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        if(n == 0)
            return 0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
             st.insert(nums[i]);
        }
       
        for( auto it : st){
            if(st.find(it - 1) == st.end()){
                int count = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x+1;
                    count = count + 1;
                }
                longest = max(longest,count);
                
            }
        }
        
        return longest;
        
       
        
    }
};