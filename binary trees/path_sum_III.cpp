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
    long long ans = 0, targ;
    map<long long,long long> lookup;

    void dfs(TreeNode* root, long long root_sum) {
        if(root == NULL) return;
        root_sum += root->val;
        ans += lookup[root_sum];
        lookup[root_sum + targ] += 1;
        dfs(root->left, root_sum);
        dfs(root->right, root_sum);
        lookup[root_sum + targ] -= 1;
    }

    long long pathSum(TreeNode* root, int targetSum) {
        lookup[targetSum] = 1;
        targ = targetSum;
        dfs(root, 0);
        return ans;
    }
};