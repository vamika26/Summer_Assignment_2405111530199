#include <iostream>
#include <vector>
#include <unordered_map>
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
private:
    unordered_map<int, int> inorderMap;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right)
            return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};