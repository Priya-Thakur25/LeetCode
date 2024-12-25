// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<int> largestValues(TreeNode* root) {
//         vector<int>ans;
//         queue<TreeNode*>q;
//         if(root != NULL)
//             q.push(root);
//         while(!q.empty()){
//             int maxNode = INT_MIN;
//             int n = q.size();
//             while(n--){
//                 TreeNode* frontNode = q.front();
//                 q.pop();
//                 maxNode = max(maxNode, frontNode->val);
//                 if(frontNode->left) q.push(frontNode->left);
//                 if(frontNode->right) q.push(frontNode->right);
//             }
//             ans.push_back(maxNode);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> ans;
    
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    
    void dfs(TreeNode* node, int depth) {
        if (node == NULL) {
            return;
        }
        
        if (depth == ans.size()) {
            ans.push_back(node->val);
        } else {
            ans[depth] = max(ans[depth], node->val);
        }
        
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};