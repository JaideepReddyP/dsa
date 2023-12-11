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
    int ans;
    int maxPath(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxPath(root->left);
        int right = maxPath(root->right);

        ans = max(ans, max(left, 0) + max(right, 0) + root->val);

        return max(0, max(left, right)) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxPath(root);
        return ans;
    }
};