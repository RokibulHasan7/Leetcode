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
    vector<int> Ans;
    void preorder(TreeNode* curr){
        if(curr == NULL){
            return;
        }
        Ans.push_back(curr->val);
        preorder(curr->left);
        preorder(curr->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return Ans;
    }
};