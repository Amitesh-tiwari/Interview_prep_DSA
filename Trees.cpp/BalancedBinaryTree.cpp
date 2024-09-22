Balanced Binary Tree
You are given an integer 'H'. Your task is to count and 
print the maximum number of balanced binary trees possible
with height 'H'.
The balanced binary tree is one in which, for every node,
the difference between the left and right subtree heights
is less than or equal to 1.
You have to print the answer with modulo 1e9+7.

//code
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBalancedBinaryTrees(int h) {
        if (h == 0) return 1;
        if (h == 1) return 1;
        int mod = 1e9 + 7;
        long long dp[h + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= h; i++) {
            dp[i] = (dp[i - 1] * ((2 * dp[i - 2]) % mod + dp[i - 1]) % mod) % mod;
        }
        return dp[h];
    }
};
int main() {
    Solution solution;
    int height = 3; // Example height
    int result = solution.countBalancedBinaryTrees(height);
    cout << "Number of balanced binary trees of height " << height << " is: " << result << endl;
    return 0;
}

//another approach
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, long long> memo;
    const int MOD = 1e9 + 7;

    long long countBalancedBinaryTreesHelper(int h) {
        if (h == 0 || h == 1) return 1;
        if (memo.find(h) != memo.end()) return memo[h];

        long long left = countBalancedBinaryTreesHelper(h - 1);
        long long right = countBalancedBinaryTreesHelper(h - 2);

        memo[h] = (left * ((2 * right) % MOD + left) % MOD) % MOD;
        return memo[h];
    }

    int countBalancedBinaryTrees(int h) {
        return countBalancedBinaryTreesHelper(h);
    }
};

int main() {
    Solution solution;
    int height = 3; // Example height
    int result = solution.countBalancedBinaryTrees(height);
    cout << "Number of balanced binary trees of height " << height << " is: " << result << endl;
    return 0;
}