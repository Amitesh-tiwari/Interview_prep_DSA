Given two integer arrays preorder and inorder where 
preorder is the preorder traversal of a binary tree 
and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.

//code
class Solution {    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int index;
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i]==preorder[0]){
                index = i;
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightInorder(inorder.begin()+index+1, inorder.end());
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+1+leftInorder.size());
        vector<int> rightPreorder(preorder.begin()+1+leftInorder.size(), preorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};