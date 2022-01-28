/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* LCA(TreeNode* root, int mn, int mx){
        if(root -> val >= mn && root -> val <= mx){
            return root;
        }
        if(root -> val > mn){
            return LCA(root -> left, mn, mx);
        }
        return LCA(root -> right, mn, mx);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root,min(p -> val, q -> val), max(p -> val, q -> val));
    }
};