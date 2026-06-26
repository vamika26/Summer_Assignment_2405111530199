#include <iostream>
#include <sstream>
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

class Codec {
public:

    void preorder(TreeNode* root, string &s) {
        if (root == NULL) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    TreeNode* build(stringstream &ss) {
        string val;
        getline(ss, val, ',');

        if (val == "N")
            return NULL;

        TreeNode* root = new TreeNode(stoi(val));

        root->left = build(ss);
        root->right = build(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};