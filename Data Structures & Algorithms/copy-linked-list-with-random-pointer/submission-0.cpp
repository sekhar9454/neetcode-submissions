/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*>mp;

        Node* h , *tr = head;
        Node* tr_cp = h;

        mp[nullptr] = nullptr;
        while(tr!=nullptr){
            tr_cp = new Node(tr->val);
            mp[tr] = tr_cp;
            tr = tr->next;
        }

        tr = head , tr_cp = h;

        while(tr!=nullptr){
            tr_cp = mp[tr];
            tr_cp->next = mp[tr->next];
            tr_cp->random = mp[tr->random];

            tr = tr->next;
            // tr_cp = tr_cp->next;
        }


        return mp[head];
    }
};
