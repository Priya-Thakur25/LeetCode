/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p) return p;
        if(root == q) return q;

        TreeNode* lefti = lowestCommonAncestor(root->left, p, q);
        TreeNode* righti = lowestCommonAncestor(root->right, p, q);

        if(lefti != NULL && righti != NULL) return root;
        if(lefti == NULL && righti != NULL) return righti;
        if(lefti != NULL && righti == NULL) return lefti;
        return NULL;
    }
};