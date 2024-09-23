Print Nodes at Distance K From a Given Node
You are given an arbitrary binary tree, a node of the tree
, and an integer 'K'. You need to find all such nodes 
which have a distance K from the given node and return 
the list of these nodes.
Distance between two nodes in a binary tree is defined as
the number of connections/edges in the path between the
two nodes.

//code
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        parent[root] = nullptr;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        q.push(target);
        visited.insert(target);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (level == k) {
                    result.push_back(node->val);
                }
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parent[node] && visited.find(parent[node]) == visited.end()) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            level++;
            if (level > k) {
                break;
            }
        }
        return result;
    }
};
