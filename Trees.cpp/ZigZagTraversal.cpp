Given the root of a binary tree, return the zigzag level 
order traversal of its nodes' values. (i.e., from left 
to right, then right to left for the next level and 
alternate between).

//code
class Solution {
public:
    void zigzag(TreeNode* root, vector<vector<int>>& ans, int level){
        if(root==NULL)
            return;
        if(ans.size()==level)
            ans.push_back({});
        if(level%2==0)
            ans[level].push_back(root->val);
        else
        ans[level].insert(ans[level].begin(), root->val);
        zigzag(root->left, ans, level+1);
        zigzag(root->right, ans, level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        zigzag(root, ans, 0);
        return ans;
    }
};