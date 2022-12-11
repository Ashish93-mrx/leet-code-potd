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
    int maxPathSum(TreeNode* root) {
       int maxsm=INT_MIN;
       dfs(root, maxsm);
       return maxsm;
    }

    int dfs(TreeNode* root, int& maxsm)
    {
        if(!root)
            return 0;
        
        int left=max(0,dfs(root->left,maxsm));
        int right=max(0,dfs(root->right,maxsm));
        maxsm=max(maxsm,right+left+root->val);
        return max(right,left)+root->val;
    }
};
