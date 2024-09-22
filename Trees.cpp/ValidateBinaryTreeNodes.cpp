Q1. Validate Binary Tree Nodes
You are given ‘N’ binary tree nodes numbered from 0 to 
N - 1 where node ‘i’ has two children LEFT_CHILD[i] and 
RIGHT_CODE[i]. Return ‘True’ if and only if all the given
nodes form exactly one valid binary tree. If node ‘i’ has
no left child then 'LEFT_CHILD[i]' will equal -1, 
similarly for the right child.

//code
// C++ code for the above approach:
#include <bits/stdc++.h>
using namespace std;

bool isBinaryTree(int N, vector<vector<int> >& edges)
{
	if (N == 0) {
		return false;
	}

	unordered_map<int, int> inDegree;
	unordered_map<int, int> childrenCount;

	for (vector<int>& edge : edges) {
		int from = edge[0];
		int to = edge[1];

		inDegree[to]++;
		childrenCount[from]++;

		if (inDegree[to] > 1 || childrenCount[from] > 2) {

			// More than two children or more
			// than one parent, not a binary
			// tree.
			return false;
		}
	}

	int rootCount = 0;
	for (int i = 0; i < N; i++) {
		if (inDegree[i] == 0) {
			rootCount++;
			if (rootCount > 1) {

				// More than one root, not a
				// binary tree.
				return false;
			}
		}
	}

	return rootCount == 1;
}

// Drivers code
int main()
{
	int N = 4;
	vector<vector<int> > edges
		= { { 0, 1 }, { 0, 2 }, { 0, 3 } };

	// Function Call
	if (isBinaryTree(N, edges))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}

     