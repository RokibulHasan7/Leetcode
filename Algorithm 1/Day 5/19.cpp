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
        int cnt = 0;
        ListNode* root = head;
        
        while(root -> next){
            root = root -> next;
            cnt++;
        }
        
        cnt = cnt - n + 1;
        ///cout<<cnt<<endl;
        if(cnt == 0){
            head = head -> next;
            return head;
        }
        
        ListNode* tmp = head;
        while(cnt && tmp){
            ListNode *temp = tmp -> next -> next;
            if(cnt == 1){
                tmp -> next = temp;
                break;
            }
            tmp = tmp -> next;
            cnt--;
        }
        
        return head;
    }
};