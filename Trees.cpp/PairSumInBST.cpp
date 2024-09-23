Pair Sum in BST.
You are given a Binary Search Tree (BST) and a target 
value ‘K’. Your task is to check if there exist two unique
elements in the given BST such that their sum is equal 
to the given target ‘K’.
A binary search tree (BST) is a binary tree data structure
which has the following properties.

//code
#include <iostream>
#include <unordered_set>
using namespace std;

// Data structure to store a BST node
struct Node {
    int data;
    Node* left = nullptr, *right = nullptr;
    Node(int data) : data(data) {}
};

// Recursive function to insert a key into a BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to find a pair with a given sum in a BST
bool findPair(Node* root, int target, unordered_set<int>& set) {
    if (root == nullptr) {
        return false;
    }
    if (findPair(root->left, target, set)) {
        return true;
    }
    if (set.find(target - root->data) != set.end()) {
        cout << "Pair found (" << target - root->data << ", " << root->data << ")" << endl;
        return true;
    } else {
        set.insert(root->data);
    }
    return findPair(root->right, target, set);
}

int main() {
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    Node* root = nullptr;
    for (int key : keys) {
        root = insert(root, key);
    }
    int target = 28;
    unordered_set<int> set;
    if (!findPair(root, target, set)) {
        cout << "Pair does not exist" << endl;
    }
    return 0;
}
