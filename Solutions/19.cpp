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
        int sz = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            sz++;
            tmp = tmp -> next;
        }
        if(sz == n){
            head = head -> next;
            return head;
        }
        
        tmp = head;
        int curr = 0;
        ListNode* prev = NULL;
        while(tmp != NULL){
            curr++;
            int diff = sz - curr;
            if(diff == n){
                tmp -> next = tmp -> next -> next; 
                break;
            }
            tmp = tmp -> next;
        }
        return head;
    }

};
