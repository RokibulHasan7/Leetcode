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

/// BFS solution

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> Q;
        int depth = 0;
        
        if(root != NULL){
            Q.push(root);
        }
        while(!Q.empty()){
            depth++;
            int sz = Q.size();
            
            for(int i = 0; i < sz; i++){
                root = Q.front();
                Q.pop();
                if(root -> left != NULL){
                    Q.push(root -> left);
                }
                if(root -> right != NULL){
                    Q.push(root -> right);
                }
            }
        }
        return depth;
    }
};