#include <iostream>
#include <climits>
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
    bool validate(TreeNode* root,
                  long long minVal,
                  long long maxVal) {

        if (!root)
            return true;

        if (root->val <= minVal ||
            root->val >= maxVal)
            return false;

        return validate(root->left,
                        minVal,
                        root->val)
            &&
               validate(root->right,
                        root->val,
                        maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root,
                        LLONG_MIN,
                        LLONG_MAX);
    }
};