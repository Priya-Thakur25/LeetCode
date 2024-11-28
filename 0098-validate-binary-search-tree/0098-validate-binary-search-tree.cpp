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
bool checkBST(TreeNode* root, long long left, long long right){
    if(root == NULL){
        return 1;
    }
    bool ans = 0;
    if(root->val > left && root->val < right){
         ans = checkBST(root->left, left, root->val) && checkBST(root->right, root->val, right);
    }
    return ans;
}
    bool isValidBST(TreeNode* root) {
        long long left = -2147483657;
        long long  right = 2147483657;
        return checkBST(root, left, right);
    }
};