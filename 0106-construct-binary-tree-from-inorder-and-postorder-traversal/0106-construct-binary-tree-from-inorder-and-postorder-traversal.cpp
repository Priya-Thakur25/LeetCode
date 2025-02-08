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
    int search(vector<int>& in, int ele) {
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == ele)
                return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& post, vector<int>& in, int& postIn, int inStart,
                    int inEnd, int size) {
        if (postIn < 0 || inStart > inEnd)
            return NULL;

        TreeNode* node = new TreeNode(post[postIn]);
        int ele = post[postIn];
        postIn--;
        int position = search(in, ele);

        node->right = solve(post, in, postIn, position + 1, inEnd, size);
        node->left = solve(post, in, postIn, inStart, position - 1, size);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        int index = size-1;
        return solve(postorder, inorder, index, 0, size - 1, size);
    }
};