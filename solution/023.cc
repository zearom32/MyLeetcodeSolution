/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


typedef ListNode* T;

struct cmp
{
    int operator()(const T&a, const T&b)
    {
        return a->val > b->val;
    }
};


class Solution {
public:

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode* >, cmp> q;
        ListNode* head = NULL;
        ListNode* now = NULL;
        for (auto p = lists.begin(); p != lists.end(); p++)
        {
            if (*p)
                q.push(*p);
        }
        while (q.size())
        {
            ListNode* r = q.top();
            q.pop();
            if (r->next) q.push(r->next);
            if (head == NULL) { head = r; now = r; }
            else
            {
                now->next = r;
                now = r;
            }
        }
        return head;
    }
};