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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int maxi = 0;
        while (!q.empty()) {
            long long mini = q.front().second;
            int size = q.size();
            int first, last;
            for (int i = 0; i < size; i++) {
                long long curr = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0)
                    first = curr;
                if (i == size - 1)
                    last = curr;

                if (node->left)
                    q.push({node->left, 2 * curr + 1});
                if (node->right)
                    q.push({node->right, 2 * curr + 2});
            }
            maxi = max(maxi, last - first + 1);
        }
        return maxi;
    }
};