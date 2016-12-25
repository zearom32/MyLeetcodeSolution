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
int ans =-0x7fffffff;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* root){
        if (!root) return 0;
        int lmax = dfs(root->left);
        int rmax = dfs(root->right);
        int k = lmax + rmax + root->val;
        ans = max(ans,k);
        return max(0,max(lmax+root->val,rmax+root->val));
    }
};