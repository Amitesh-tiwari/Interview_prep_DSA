Given an integer array nums where the elements are sorted 
in ascending order, convert it to a height-balanced 
binary search tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Conversion(vector<int> nums, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = Conversion(nums,start,mid-1);
        
        root->right = Conversion(nums,mid+1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return Conversion(nums,0,n-1);
        
    }
};