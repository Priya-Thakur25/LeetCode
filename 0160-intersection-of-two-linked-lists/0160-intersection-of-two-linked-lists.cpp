/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // ListNode* temp1 = headA;
        // ListNode* temp2 = headB;
        // ListNode* ans = NULL;
        // while (temp1 != temp2) {
        //     else if (temp1 == NULL) {
        //         temp1 = headB;
        //     }
        //     else if (temp2 == NULL) {
        //         temp2 = headA;
        //     }
        //     temp1 = temp1->next;
        //     temp2 = temp2->next;
        // }
        // if (temp1 == temp2) {
        //     ans = temp1;
        // }
        // return ans;

        //Another way of writing in small manner
        ListNode* temp1 = headA;
        ListNode*  temp2 = headB;
        while(temp1 != temp2){
            temp1 = (temp1 == NULL) ? headB : temp1->next;
            temp2 = (temp2 == NULL) ? headA : temp2->next;
        }
        return temp1;
    }
};