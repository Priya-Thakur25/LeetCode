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
    void solve(vector<int>&ans, TreeNode* root){
        if(root == NULL) return;
        solve(ans, root->left);
        ans.push_back(root->val);
        solve(ans, root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        solve(ans, root);
        int n = ans.size();
        int s=0, e=n-1;
        while(s < e){
            int sum = ans[s] + ans[e];
            if(sum == k) return 1;
            if(sum > k) e--;
            else s++;
        }
        return 0;
    }
};