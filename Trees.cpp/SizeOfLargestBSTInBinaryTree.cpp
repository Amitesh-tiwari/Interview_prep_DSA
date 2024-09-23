Size of Largest BST in Binary Tree
You are given a binary tree with 'N' nodes. Your task is 
to return the size of the largest subtree of the binary 
tree which is also a BST.

//code
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Returns tree if the given tree is BST
// else false
bool isValidBST(Node *root, int lb, int ub) {
    if (!root)
        return true;
    if (root->data >= ub || root->data <= lb)
        return false;
    return isValidBST(root->left, lb, root->data) && 
           isValidBST(root->right, root->data, ub);
}

// Returns Size of a Tree
int size(Node *root) {
    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

// Finds the size of the largest BST
int largestBst(Node *root) {
  
    // IF tree is empty
    if (!root)
        return 0;
    
    // Whole tree is BST
    if (isValidBST(root, INT_MIN, INT_MAX)) 
        return size(root);
  
    //  Whole tree is nnt BST
    return max(largestBst(root->left), 
               largestBst(root->right));
}

int main() {
    Node *root = new Node(50);
    root->left = new Node(75);
    root->right = new Node(45);
    root->left->left = new Node(40);
    cout << largestBst(root) << endl;
    return 0;
}
