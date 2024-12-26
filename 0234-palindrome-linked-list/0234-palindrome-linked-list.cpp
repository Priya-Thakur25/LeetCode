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
bool checkPalindrome(ListNode* head1, ListNode* head2){
    if(head1 == NULL || head2 == NULL) return true;
    if(head1 != NULL && head2 != NULL && head1->val != head2->val) return false;    
    return checkPalindrome(head1->next, head2->next);
}

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
        ListNode* slow = head;
        ListNode* fast =  head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }

        ListNode* temp2 = slow->next;
        slow->next = NULL;
        ListNode* Node2 = reverse(temp2);
        return checkPalindrome(head, Node2);
    }
};