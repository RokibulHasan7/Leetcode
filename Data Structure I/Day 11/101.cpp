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
    bool isSame(TreeNode* one, TreeNode* two){
        if(one == NULL && two == NULL){
            return true;
        }
        if((one == NULL && two != NULL) || (one != NULL && two == NULL)){
            return false;
        }
        if(one -> val != two -> val){
            return false;
        }
        
        return isSame(one -> left, two -> right) && isSame(one -> right, two -> left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root -> left, root -> right) && isSame(root -> right, root -> left);
    }
};