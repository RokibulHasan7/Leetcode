/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> Ans;
        if(root != NULL){
            Q.push(root);
            vector<int>v;
            v.push_back(root -> val);
            Ans.push_back(v);
        }
        while(!Q.empty()){
            int sz = Q.size();
            vector<int>v;
            for(int i = 0; i < sz; i++){
                root = Q.front();
                Q.pop();
                if(root -> left != NULL){
                    Q.push(root -> left);
                    v.push_back(root->left->val);
                }
                if(root -> right != NULL){
                    Q.push(root -> right);
                    v.push_back(root->right->val);
                }
            }
            if(v.size() > 0){
                Ans.push_back(v);
            }
        }
        
        return Ans;
    }
};