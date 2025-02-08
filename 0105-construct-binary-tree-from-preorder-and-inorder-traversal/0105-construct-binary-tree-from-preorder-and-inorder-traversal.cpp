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
    int search(vector<int>&in, int ele){
        for(int i=0; i<in.size(); i++){
            if(in[i] == ele) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>&pre, vector<int>&in, int& preIn, int inStart, int inEnd, int size){
        if(preIn >= size || inStart > inEnd) return NULL;

        TreeNode* node = new TreeNode(pre[preIn]);
        int ele = pre[preIn];
        preIn++;
        int position = search(in, ele);

        node->left = solve(pre,in,preIn,inStart,position-1,size);
        node->right = solve(pre,in,preIn,position+1,inEnd,size);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int index = 0;
        return solve(preorder, inorder, index, 0, size-1, size);
    }
};