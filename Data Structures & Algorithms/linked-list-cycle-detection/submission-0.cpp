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
    bool hasCycle(ListNode* head) {
        ListNode* s = head, *f = head;

        do{
            if(f == nullptr || f->next == nullptr) return false;

            s = s->next;
            f = f->next->next;
        }while(s != f);

        return true;
    }
};
