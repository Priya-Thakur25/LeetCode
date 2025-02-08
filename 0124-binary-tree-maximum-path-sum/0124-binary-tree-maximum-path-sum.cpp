/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi = INT_MIN;
    int PathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int lefti = max(0,PathSum(root->left));
        int righty = max(0,PathSum(root->right));
        maxi = max(maxi, lefti+righty+root->val);
        return max(lefti,righty)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        PathSum(root);
        return maxi;
    }
};