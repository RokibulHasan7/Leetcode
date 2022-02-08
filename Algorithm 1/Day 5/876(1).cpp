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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode * root = head;
        while(root){
            cnt++;
            root = root -> next;
        }
        
        int target = (cnt / 2);
        
        while(head && target){
            head = head -> next;
            target--;
        }
        return head;
    }
};