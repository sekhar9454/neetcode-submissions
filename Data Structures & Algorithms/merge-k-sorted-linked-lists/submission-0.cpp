/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head  = new ListNode();
        ListNode* tr  = head;
        int n  = lists.size();
        while(true){
            int idx  = -1 , val = INT_MAX;
            for(int i= 0 ; i < n ; i++){
                if(lists[i] && lists[i]->val < val) {
                    idx = i;
                    val = lists[i]->val;
                }
            }
            if(idx == -1) break;

            tr->next = new ListNode(val);
            tr = tr->next;

            lists[idx] = lists[idx]->next;
        }

        return head->next;
    }
};
