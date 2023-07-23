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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> Ans;
        if(n % 2 == 0){
            return Ans;
        }
        
        if(n == 1){
            Ans.push_back(new TreeNode(0));
            return Ans;
        } else {
            for(int i = 1; i < n; i += 2){
                vector<TreeNode*> leftTree = allPossibleFBT(i);
                vector<TreeNode*> rightTree = allPossibleFBT(n - i - 1);

                for(TreeNode* lt : leftTree){
                    for(TreeNode* rt: rightTree){
                        Ans.push_back(new TreeNode(0, lt, rt));
                    }
                }
            }
        }
        return Ans;
    }
};
