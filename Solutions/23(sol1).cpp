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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        
        vector<pair<int, ListNode*>> vec;
        for(int i = 0; i < lists.size(); i++){
            ListNode* curr = lists[i];
            
            while(curr){
                vec.push_back(make_pair(curr -> val, curr));
                curr = curr -> next;
            }
        }
        
        if(vec.size() == 0){
            return NULL;
        }
        
        sort(vec.begin(), vec.end());
        int n = vec.size();
        vec[n - 1].second -> next = NULL;
        
        for(int i = 0; i < n - 1; i++){
            vec[i].second -> next = vec[i + 1].second;
        }
        
        return vec[0].second;
    }
};
