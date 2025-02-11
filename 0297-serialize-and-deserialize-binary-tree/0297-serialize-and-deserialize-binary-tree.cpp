/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node) s += "#,";
            else s += to_string(node->val) + ",";
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s.empty()) return NULL;
        queue<TreeNode*>q;
        stringstream ss(s);
        string data = "";
        getline(ss,data,',');
        TreeNode* root = new TreeNode(stoi(data));
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            getline(ss, data, ',');
            if(data == "#") front->left = NULL;
            else{
                TreeNode* temp = new TreeNode(stoi(data));
                front->left = temp;
                q.push(temp);
            }
            getline(ss,data,',');
            if(data == "#") front->right = NULL;
            else{
                TreeNode* temp = new TreeNode(stoi(data));
                front->right = temp;
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));