/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        //FIRST APPROACH USING HASHMAP

        // unordered_map<Node*,Node*>mp;
        // Node* temp = head;
        // while(temp != NULL){
        //     Node* newNode = new Node(temp->val);
        //     mp[temp] = newNode;
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp != NULL){
        //     Node* node = mp[temp];
        //     node->next = mp[temp->next];
        //     node->random = mp[temp->random];
        //     temp = temp->next;
        // }

        // return mp[head];

        //SECOND INSERT-IN-BETWEEN APPROACH
        Node* temp = head;
        while(temp != NULL){
            Node* node = new Node(temp->val);
            Node* nextNode = temp->next;
            temp->next = node;
            node->next = nextNode;
            temp = temp->next->next;
        }

        temp = head;
        while(temp != NULL){
            Node* node = temp->next;
            node->random = temp->random ? temp->random->next : NULL;
            temp = temp->next->next;
        }

        temp = head;
        Node* ans = NULL;
        if(temp) ans = temp->next;
        while(temp != NULL){
            Node* node = temp->next;
            temp->next = node->next;
            if(temp->next) node->next = temp->next->next;
            temp = temp->next;
        }
        return ans;
    }
};