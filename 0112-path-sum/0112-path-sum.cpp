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
    bool solve(TreeNode* root, int target, int sum){
        if(root == NULL) return 0;
        sum += root->val;
        if(sum == target && root->left == NULL && root->right == NULL) return true;

        bool ans1 = solve(root->left, target, sum); 
        bool ans2 = solve(root->right, target, sum);
        return (ans1 || ans2);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }
};