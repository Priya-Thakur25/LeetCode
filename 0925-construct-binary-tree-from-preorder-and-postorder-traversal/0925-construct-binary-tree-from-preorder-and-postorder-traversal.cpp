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
    TreeNode*  solve(int prestart, int postind, int preend, vector<int>&preorder, vector<int>&postorder){
        if(prestart > preend) return NULL;
        TreeNode* node = new TreeNode(preorder[prestart]);
        if(prestart == preend) return node;
        int element = preorder[prestart+1]; 
        int j = postind;
        while(postorder[j] != element){
            j++;
        }
        int size = j - postind + 1;
        node->left = solve(prestart+1,postind, prestart+size, preorder, postorder);
        node->right = solve(prestart+size+1,j+1,preend, preorder, postorder);
        return node;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(0,0,preorder.size()-1,preorder,postorder);
    }
};