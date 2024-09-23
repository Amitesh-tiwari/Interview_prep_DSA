Height of Binary Tree
You are given an arbitrary binary tree consisting of 'N' 
nodes where each node is associated with a certain value.
You need to find out the height of the tree.
Height of a binary tree is the maximum number of edges 
fee traverse from the root to one of the leaf nodes.


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

//Returns "maxDepth" which is the number
//of nodes along the longest path from 
//the root node down to the farthest
//leaf node.
int maxDepth(Node *node)
{
    if (node == nullptr)
        return 0;

    // compute the depth of left and right
    // subtrees
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);

    // use the larger one
    return max(lDepth, rDepth) + 1;
}

// Driver code
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << maxDepth(root);
    return 0;
}
