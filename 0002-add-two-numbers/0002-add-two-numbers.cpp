/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* point = new ListNode(0);
        ListNode* temp = point;
        int carry = 0;
        while (temp1 != NULL && temp2 != NULL) {
            ListNode* Node = new ListNode(0);
            int sum = 0;
            sum = temp1->val + temp2->val;
            sum = carry == 1 ? (carry = 0, sum+1) : sum;
            if (sum < 10) {
                Node->val = sum;
            } else if (sum >= 10) {
                carry = 1;
                Node->val = (sum % 10);
            }
            temp->next = Node;
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (temp1 != NULL) {
            while (temp1 != NULL) {
                int sum = temp1->val;
                ListNode* Node = new ListNode(0);
                sum = carry == 1 ? sum + 1 : sum;
                if (sum < 10) {
                    Node->val = sum;
                    carry = 0;
                } else if (sum >= 10) {
                    Node->val = sum % 10;
                    carry = 1;
                }
                temp->next = Node;
                temp = temp->next;
                temp1 = temp1->next;
            }
        } else if (temp2 != NULL) {
            while (temp2 != NULL) {
                int sum = temp2->val;
                ListNode* Node = new ListNode(0);
                sum = carry == 1 ? sum + 1 : sum;
                if (sum < 10) {
                    Node->val = sum;
                    carry = 0;
                } else if (sum >= 10) {
                    Node->val = sum % 10;
                    carry = 1;
                }
                temp->next = Node;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }

        if (carry == 1) {
            ListNode* Node = new ListNode(0);
            Node->val = 1;
            temp->next = Node;
            temp = temp->next;
        }

        return point->next;
    }
};