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
    void inorder(TreeNode* curr){
        if(curr == NULL){
            return;
        }
        inorder(curr->left);
        Ans.push_back(curr->val);
        inorder(curr->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return Ans;
    }
};