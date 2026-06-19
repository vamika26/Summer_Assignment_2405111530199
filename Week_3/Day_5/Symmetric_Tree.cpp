#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;

        if (left == NULL || right == NULL)
            return false;

        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return isMirror(root->left, root->right);
    }
};