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
    ListNode* endHalf(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            fast  = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* curr = head;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return true;
        }

        ListNode* endOfFirstHalf = endHalf(head);
        ListNode* startOfSecondHalf = reverseList(endOfFirstHalf -> next);

        bool Ans = true;
        ListNode* one = head;
        ListNode* two = startOfSecondHalf;
        while(Ans && two != NULL){
            if(one -> val != two -> val){
                Ans = false;
            }
            one = one -> next;
            two = two -> next;
        }
        endOfFirstHalf -> next = reverseList(startOfSecondHalf);
        return Ans;
    }
};
