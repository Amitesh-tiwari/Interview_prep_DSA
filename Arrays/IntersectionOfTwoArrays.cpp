Given two integer arrays nums1 and nums2, 
return an array of their intersection.
 Each element in the result must appear as many times as 
 it shows in both arrays and you may return the result
  in any order.

//code

#include <vector>
class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            vector<int> result;
            int i=0,j=0;
            int n1 = nums1.size();
            int n2 = nums2.size();
            while(i<n1 && j<n2){
                if(nums1[i] == nums2[j]){
                    result.push_back(nums1[i]);
                    i++;
                    j++;
                }
                else if(nums1[i] > nums2[j]){
                    j++;
                }
                else{
                    i++;
                }
            }
            return result;
        }       
};