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
ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr != NULL){
        ListNode* temp = curr->next;
         curr->next = prev;
         prev = curr;
         curr = temp;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        int count = 0;
        while(curr != NULL){
            count++;
            prev = curr;
            curr = curr->next;
        }
        
        prev = NULL;
        curr = head;
        ListNode* LL1 = head;
        int i=0;
        while(i != count/2){
            prev = curr;
            curr = curr->next;
            i++;
        }
        if(count > 1){
            prev->next = NULL;   
        }

        if(count/2 > 1){
            LL1 = reverse(head);
        }
        else{
            LL1 = head;
        }

        ListNode* LL2;
        if(count%2 == 0){
           LL2 = curr;   
        }
        else{
            LL2 = curr->next;
        }
        while(LL2 != NULL){
            if(LL1->val != LL2->val){
                return false;
            }
            LL1 = LL1->next;
            LL2 = LL2->next;
        }

        return true;

    }
};