Given the root of a binary tree, check whether it is a 
mirror of itself (i.e., symmetric around its center).

//code
bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isMirror(root->left,root->right);
    }
    
    bool isMirror(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
            return true;
        if(root1==NULL || root2==NULL)
            return false;
        if(root1->val!=root2->val)
            return false;
        return isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
    }