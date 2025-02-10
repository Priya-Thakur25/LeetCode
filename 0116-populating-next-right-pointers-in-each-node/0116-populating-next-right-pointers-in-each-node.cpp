/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root == NULL)
            return root;
        q.push(root);
        q.push(NULL);
        while (q.size() > 1) {
            Node* frontNode = q.front();
            q.pop();
            if(frontNode) frontNode->next = q.front();
            if (!frontNode) {
                q.push(NULL);
            } else {
                if (frontNode->left)
                    q.push(frontNode->left);
                if (frontNode->right)
                    q.push(frontNode->right);
            }
        }
        return root;
    }
};