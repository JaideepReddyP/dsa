#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int balanced(TreeNode* root) {
        if(root == NULL) return 0;
        int height_left = balanced(root->left);
        int height_right = balanced(root->right);

        if(height_left == -1 || height_right == -1 || abs(height_left-height_right) > 1) return -1;

        return 1+max(height_left, height_right);
    }

    bool isBalanced(TreeNode* root) {
        return balanced(root) != -1;
    }
};