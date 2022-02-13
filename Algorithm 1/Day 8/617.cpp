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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* newNode = new TreeNode();
        
        if(root1 == NULL && root2 == NULL){
            return NULL;
        }
        
        if(root1 && root2){
            newNode -> val = root1 -> val + root2 -> val;
        }
        else if(root1){
            newNode -> val = root1 -> val;
        }
        else if(root2){
            newNode -> val = root2 -> val;
        }
        
        newNode -> left = mergeTrees(root1 ? root1 -> left : NULL, root2 ? root2 -> left : NULL);
        newNode -> right = mergeTrees(root1 ? root1 -> right : NULL, root2 ? root2 -> right : NULL);
        
        return newNode;
    }
};