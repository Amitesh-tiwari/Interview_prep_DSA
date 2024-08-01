Given the root of a binary tree, return the level order 
traversal of its nodes' values. (i.e., from left to right,
level by level).

//code
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }