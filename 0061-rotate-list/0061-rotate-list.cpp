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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head) return head;
        int count = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            count++;
            tail = tail->next;
        }
        k = k%count;
        if(k == 0) return head;

        ListNode* newTail = head;
        int till = count - k - 1;
        while(till){
            newTail = newTail->next;
            till--;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        tail->next = head;
        return newHead;
    }
};