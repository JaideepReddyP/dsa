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
    TreeNode* ans;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return false;
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        bool curr = (root == p) || (root == q);

        if((left && right) || (curr && left) || (curr && right)) {
            ans = root;
            return true;
        }
        return left || right || curr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = root;
        dfs(root, p, q);
        return ans;
    }
};