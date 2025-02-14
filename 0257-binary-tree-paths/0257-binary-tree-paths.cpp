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
    void PrintPath(TreeNode* root, vector<string>& vec, string s) {
        if (root == NULL) return;

        // Append current node value as a string
        if (!s.empty()) s += "->";
        s += to_string(root->val);

        // If it's a leaf node, store the path
        if (root->left == NULL && root->right == NULL) {
            vec.push_back(s);
            return;
        }

        // Recursive calls for left and right subtree
        PrintPath(root->left, vec, s);
        PrintPath(root->right, vec, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>vec;
        string s = "";
        PrintPath(root, vec, s);
        return vec;
    }
};