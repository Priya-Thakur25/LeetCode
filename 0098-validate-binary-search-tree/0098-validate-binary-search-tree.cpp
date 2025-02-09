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
    bool solve(TreeNode* root, long long  mini, long long maxi){
        if(root == NULL) return 1;
        bool leftkaans = 0, rightkaans = 0, ans = 0;
        if(root->val < maxi && root->val > mini) ans = 1;
        leftkaans = solve(root->left, mini, root->val);
        rightkaans = solve(root->right, root->val, maxi);
        return ans && leftkaans && rightkaans;
    }
    bool isValidBST(TreeNode* root) {
    long long mini = -2147483657, maxi = 2147483657;
    return solve(root,mini,maxi);
    }
};