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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tr = head , *cur = head , *prev;
        int k = n;

        while(k--){
            tr = tr->next;
        }

        if (tr == nullptr)
            return head->next;


        while(tr!=nullptr){
            tr = tr->next;
            prev = cur;
            cur = cur->next;
        }

        prev->next = cur->next;

        return head;


    }
};
