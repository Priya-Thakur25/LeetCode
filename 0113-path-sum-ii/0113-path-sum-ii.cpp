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
    void solve(TreeNode* root, int target, int sum, vector<int>temp, vector<vector<int>>&final){
        if(root == NULL) return;
        sum += root->val;
        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(target == sum) final.push_back(temp);
            else return;
        }
        solve(root->left,target,sum,temp,final);
        solve(root->right,target,sum,temp,final);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>final;
        vector<int>temp;
        solve(root,targetSum,0,temp,final);
        return final;
    }
};