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
    TreeNode* solve(TreeNode* root, int val){
        if(root == NULL) return NULL;
        if(root->val == val) return root;

        TreeNode* temp1 = NULL;
        if(root->val > val) temp1 = searchBST(root->left,val);
        else if(root->val < val) temp1 = searchBST(root->right,val);
        return temp1;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};