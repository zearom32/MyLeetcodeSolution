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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*,int>> q;
        q.emplace(root,0);
        while(q.size()){
            auto& m = q.top();
            if (m.first == NULL){
                q.pop();
                continue;
            }
            switch(m.second){
                case 0:
                    m.second++;
                    q.emplace(m.first->left,0);
                    break;
                case 1:
                    m.second++;
                    q.emplace(m.first->right,0);
                    break;
                case 2:
                    q.pop();
                    ans.push_back(m.first->val);
                    break;
            }
        }
    
        return ans;
    }
};