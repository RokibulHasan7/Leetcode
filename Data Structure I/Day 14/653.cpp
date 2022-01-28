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
    map<int,int> mp;
    bool ok = false;
    void preorder(TreeNode* root, int k){
        if(root == NULL){
            return;
        }
        mp[root -> val]++;
        if(mp[k - root -> val] > 0 && root -> val * 2 != k){
            ok = true;
        }
        if(root -> val * 2 == k && mp[k - root -> val] > 1){
            ok = true;
        }
        preorder(root -> left, k);
        preorder(root -> right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        preorder(root, k);
        return ok;
    }
};