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
class FindElements {
public:
    TreeNode* tree;
    void rightTree(TreeNode* root){
        if(root == NULL) return;
        if(root->left){
            root->left->val = root->val * 2 + 1;
            rightTree(root->left);
        }
        if(root->right){
            root->right->val = root->val * 2 + 2;
            rightTree(root->right);
        }
    }

    bool finding(TreeNode* root, int target){
        if(root && root->val == target) return 1;
        if(root == NULL) return 0;
        return finding(root->left,target) || finding(root->right,target);
    }

    FindElements(TreeNode* root) {
        root->val = 0;
        tree = root;
        rightTree(root);
    }
    
    bool find(int target) {
        return finding(tree,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */