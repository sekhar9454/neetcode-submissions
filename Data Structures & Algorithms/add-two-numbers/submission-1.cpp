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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* dummy = new ListNode();
        ListNode* head2 = dummy;

        while(l1!=nullptr && l2!=nullptr){
            int a = (l1->val);
            int b = (l2->val);
            dummy->next = new ListNode((a+b+c)%10);
            c = (a+b+c)/10;
            dummy= dummy->next;

            l1 = l1->next;
            l2 = l2->next;
        }


        ListNode* tr = (l1)?l1:l2;

        while(tr!=nullptr){
            dummy->next = new ListNode((tr->val + c)%10);

            c = (tr->val + c)/10;

            tr = tr->next;
            dummy = dummy->next;
        }


        if(c!=0) dummy->next = new ListNode(c);

        return head2->next;
    }
};
