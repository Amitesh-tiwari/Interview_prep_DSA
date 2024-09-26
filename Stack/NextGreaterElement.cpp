The next greater element of some element x in an array is 
the first greater element that is to the right of x in 
the same array.

You are given two distinct 0-indexed integer arrays nums1
and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such 
that nums1[i] == nums2[j] and determine the next greater 
element of nums2[j] in nums2. If there is no next greater
element, then the answer for this query is -1.

Return an array ans of length nums1.length such that 
ans[i] is the next greater element as described above.

//code
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=0; i<nums2.size(); i++) {
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++) {
            if(mp.find(nums1[i]) != mp.end()) {
                ans.push_back(mp[nums1[i]]);
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};