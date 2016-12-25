/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *last;
    TreeNode* a[2];
    int count;
    void dfs(TreeNode *r){
        if (r == NULL)
        return;
        dfs(r->left);
        if (last != NULL){
            if (count == 0 && last->val > r->val)
            a[count++] = last,a[1] = r;
            if (count == 1 && last->val > r->val)
            a[1] = r;
        }
        last = r;
        dfs(r->right);
    }
    void swap1(TreeNode* p, TreeNode* q){
        int tmp = p->val;
        p->val = q->val;
        q->val = tmp;
    }
    void recoverTree(TreeNode *root) {
        a[0] = a[1] = NULL;
        last = NULL;
        count = 0;
        dfs(root);
        swap1(a[0],a[1]);
    }
};