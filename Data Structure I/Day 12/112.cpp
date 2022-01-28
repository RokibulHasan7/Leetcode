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
    bool isLeaf(TreeNode* root){
        if(root -> left == NULL && root -> right == NULL){
            return true;
        }
        return false;
    }
    bool check(TreeNode* root, int currSum, int targetSum){
        if(root == NULL){
            return false;
        }
        
        if(isLeaf(root) == true && currSum + root -> val == targetSum){
            return true;
        }
        
        bool left = check(root -> left, currSum + root -> val, targetSum);
        bool right = check(root -> right, currSum + root -> val, targetSum);
        
        if(left || right){
            return true;
        }
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        return check(root, 0, targetSum);
    }
};