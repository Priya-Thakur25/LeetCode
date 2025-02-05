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
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        TreeNode* leftkaans = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightkaans = lowestCommonAncestor(root->right, p, q);

        if(leftkaans == NULL && rightkaans == NULL) return NULL;
        else if(leftkaans != NULL && rightkaans == NULL) return leftkaans;
        else if(leftkaans == NULL && rightkaans != NULL) return rightkaans;
        else return root;
    }
};