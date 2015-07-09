/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    TreeLinkNode *next(TreeLinkNode* p){
        if (!p) return NULL;
        while(p){
            if (p->left) return p->left;
            if (p->right) return p->right;
            p = p->next;
        }
        return p;
    }
    void connect(TreeLinkNode *root) {
        TreeLinkNode* cur = root;
        while(cur){
            if (cur->left){
                if (cur->right) cur->left->next = cur->right;else
                cur->left->next = next(cur->next);
            }
        if (cur->right){
            cur->right->next = next(cur->next);
            }
        cur = cur->next;
        if (!cur){
            cur = next(root);
            root = cur;
        }
        
        }
    }
};