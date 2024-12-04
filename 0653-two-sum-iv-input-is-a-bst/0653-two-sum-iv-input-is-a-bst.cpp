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
void inorder(TreeNode* root, vector<int>&ans){
    if(root == NULL) return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root, ans);
        int e=0,s = 0;
        int n = ans.size()-1;
        for(s=0,e=n; s<e; ){
            if(ans[s]+ans[e] == k) return true;
            if(ans[s]+ans[e] > k) e--;
            else s++;
        }
        return false;
    }
};