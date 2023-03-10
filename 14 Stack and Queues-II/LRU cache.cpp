class Node
{
public:
    int data;
    int val;
    Node *next;
    Node *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
    }
};
class LRUCache
{

public:
    Node *head;
    Node *tail;
    int size;
    unordered_map<int, Node *> mp;
    LRUCache(int capacity)
    {
        size = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            int ans = mp[key]->data;
            update(mp[key]);
            return ans;
        }
    }
    void insertAtBeginning(Node *node)
    {
        node->prev = head;
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
    }
    void update(Node *temp)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        insertAtBeginning(temp);
    }
    void deleteLRU()
    {
        Node *deleteNode = tail->prev;
        mp.erase(tail->prev->val);
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
        delete (deleteNode);
    }
    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            temp->data = value;
            update(temp);
        }
        else
        {
            if (mp.size() == size)
            {
                deleteLRU();
            }
            Node *newNode = new Node();
            newNode->data = value;
            newNode->val = key;
            mp[key] = newNode;
            insertAtBeginning(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */