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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL && fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow) break;
        }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            if(fast != NULL) fast = fast->next;
        }
        return slow;
    }
};