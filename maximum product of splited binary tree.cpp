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
    int maxProduct(TreeNode* root) {
        long int res=0;
        int totalsum=Totalsum(root);
        prodsum(root,totalsum,res);
        return res%1000000007;
    }

    long int Totalsum(TreeNode* root)
    {
        if(!root) return 0;
        return Totalsum(root->left)+Totalsum(root->right)+root->val;
    }

    long int prodsum(TreeNode* root,long int totalsum,long int& res)
    {
        if(!root) return 0;
        long int subsum=0;
        subsum+=prodsum(root->left,totalsum,res);
        subsum+=prodsum(root->right,totalsum,res);
        subsum+=root->val;
        //if(subsum*(totalsum-subsum)>res)
        res=max(res,subsum*(totalsum-subsum));
            //res=subsum*(totalsum-subsum);
        return subsum;


    }
};
