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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,vector<pair<int,int>>>mp;
        queue<pair<pair<int,int>,TreeNode*>>q;

        q.push({{0,0},root});
        while(!q.empty()){
            TreeNode* tem = q.front().second;
            pair<int,int>lvl = q.front().first;
            q.pop();
            mp[lvl.second].push_back({lvl.first,tem->val});
            if(tem->left) q.push({{lvl.first+1,lvl.second-1}, tem->left});
            if(tem->right) q.push({{lvl.first+1,lvl.second+1}, tem->right});
        }
        for(auto m: mp){
            vector<int>temp;
            sort(m.second.begin(), m.second.end());
            for(auto v: m.second){
                temp.push_back(v.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};