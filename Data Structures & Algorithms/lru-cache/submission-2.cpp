class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;

    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(0, 0);   // dummy head
        tail = new Node(0, 0);   // dummy tail

        head->next = tail;
        tail->prev = head;
    }

    // Remove a node from the list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert a node right after head (MRU position)
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            remove(node);
            insert(node);

            return;
        }

        if (mp.size() == cap) {
            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }

        Node* node = new Node(key, value);

        insert(node);

        mp[key] = node;
    }
};