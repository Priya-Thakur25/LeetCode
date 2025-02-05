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
    int Height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int Lefti = Height(root->left);
        int righty = Height(root->right);
        int diff = abs(Lefti - righty);
        bool currkaans = (diff <= 1);

        bool leftans = isBalanced(root->left);
        bool rightans = isBalanced(root->right);

        return (currkaans && leftans && rightans);
       
    }
};