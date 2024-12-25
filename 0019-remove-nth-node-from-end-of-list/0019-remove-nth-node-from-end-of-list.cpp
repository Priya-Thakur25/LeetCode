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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         int sum = 0;
         ListNode* temp = head;
         ListNode* temp2 = head;
         while(temp != NULL){
            sum++;
            temp = temp->next;
         }

         sum = sum-n;
         temp = head;
         while(sum--){
            temp2 = temp;
            temp = temp->next;
         }
         temp2->next = temp->next;
         if(temp == head) head = head->next;
         return head;
    }
};