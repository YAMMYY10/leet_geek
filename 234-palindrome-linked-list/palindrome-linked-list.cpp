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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode *currp=head;
        ListNode *prevp=NULL;
        ListNode *nextp;
        while(currp!=NULL){
            nextp=currp->next;
            currp->next=prevp;
            prevp=currp;
            currp=nextp;
        }
        return prevp;
    }
    bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) 
        return true; 
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  
        fast = fast->next->next;  
    }
    ListNode* newHead = reverseLinkedList(slow);
    ListNode* first = head;  
    ListNode* second = newHead; 
    while (second != NULL) {
        if (first->val != second->val) {
            reverseLinkedList(newHead);  
            return false;
        }
        first = first->next; 
        second = second->next;  
    }
    reverseLinkedList(newHead);  
    return true;         
    }
};