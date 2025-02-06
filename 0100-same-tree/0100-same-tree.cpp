/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == NULL && q == NULL))
            return 1;
        else if ((p == NULL || q == NULL) || (p->val != q->val))
            return false;

        bool one = isSameTree(p->left, q->left);
        bool two = isSameTree(p->right, q->right);
        return one && two;
    }
};