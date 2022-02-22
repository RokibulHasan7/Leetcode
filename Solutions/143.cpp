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
    ListNode* rev(ListNode* head){
        if(head == NULL){
            return NULL;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;     
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL){
            return;
        }
        /// Find middle Node
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode* secHead = slow -> next;
        slow -> next = NULL;
        
        /// Reverse 2nd list
        secHead = rev(secHead);
        ListNode* tmp1 = head;
        ListNode* tmp2 = secHead;
        
        while(tmp1 && tmp2){
            ListNode* curr1 = tmp1 -> next;
            ListNode* curr2 = tmp2 -> next;
            
            tmp1 -> next = tmp2;
            tmp2 -> next = curr1;
            tmp1 = curr1;
            tmp2 = curr2;
        }
    }
};
