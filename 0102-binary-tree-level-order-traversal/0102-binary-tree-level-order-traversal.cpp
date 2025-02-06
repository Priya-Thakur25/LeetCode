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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<int>temp;
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(q.size() > 1){
            TreeNode* node = q.front();
            if(node) temp.push_back(node->val);
            q.pop();
            if(node == NULL){
                ans.push_back(temp);
                q.push(NULL);
                temp.clear();
            }
            else{
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};