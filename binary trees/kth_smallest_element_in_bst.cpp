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
    int cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        return func(root, k);
    }

    int func(TreeNode* root, int k) {
        if(root == NULL) return -1;
        
        int left = func(root->left, k);
        if(left != -1) return left;

        if(++cnt == k) return root->val;

        int right = func(root->right, k);
        if(right != -1) return right;

        return -1;
    }
};