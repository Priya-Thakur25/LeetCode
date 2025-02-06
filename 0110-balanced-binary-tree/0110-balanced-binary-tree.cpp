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
    int Height(TreeNode* root){
        if(root == NULL) return 0;
        return max(Height(root->left), Height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return 1;

        int LeftH = Height(root->left);
        int RightH = Height(root->right);

        bool diff = (abs(LeftH-RightH) <= 1);
        bool Leftkaans = isBalanced(root->left);
        bool rightkaans = isBalanced(root->right);

        if(diff && Leftkaans && rightkaans) return true;
        return false;
    }
};