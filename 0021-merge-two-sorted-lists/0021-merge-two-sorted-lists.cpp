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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* point = new ListNode(0);
        ListNode* temp = point;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        // int sum = 1;
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
            } else if (temp2->val < temp1->val) {
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }
            // temp->next = NULL;
        }
        while (temp1 != NULL) {
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
        while (temp2 != NULL) {
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return point->next;
    }
};