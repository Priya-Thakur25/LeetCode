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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum = 0;
        while (q.size() > 1) {
            TreeNode* frontNode = q.front();
            if (frontNode)
                sum += frontNode->val;
            q.pop();
            if (!frontNode) {
                q.push(NULL);
                sum = 0;
            } else {
                if (frontNode->left)
                    q.push(frontNode->left);
                if (frontNode->right)
                    q.push(frontNode->right);
            }
        }
        return sum;
    }
};