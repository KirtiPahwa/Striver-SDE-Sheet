class Node
{
public:
    int key;
    int val;
    int freq;
    Node *next;
    Node *prev;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class List
{
public:
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void insert(Node *node)
    {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }
    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};
class LFUCache
{
public:
    unordered_map<int, List *> freqList;
    unordered_map<int, Node *> mp;
    int minFreq;
    int capacity;
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            int ans = mp[key]->val;
            updateFreqList(mp[key]);
            return ans;
        }
    }
    void updateFreqList(Node *node)
    {
        int freq = node->freq;
        freqList[freq]->remove(node);
        if (freqList[freq]->size == 0 && minFreq == freq)
        {
            minFreq++;
            freqList.erase(freq);
        }
        freq++;
        node->freq++;
        if (freqList.find(freq) == freqList.end())
        {
            List *list = new List();
            freqList[freq] = list;
        }
        freqList[freq]->insert(node);
    }
    void removeLFU()
    {
        mp.erase(freqList[minFreq]->tail->prev->key);
        freqList[minFreq]->remove(freqList[minFreq]->tail->prev);
        if (freqList[minFreq]->size == 0)
        {
            freqList.erase(minFreq);
        }
    }
    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }
        if (mp.find(key) == mp.end())
        {
            if (mp.size() == capacity)
            {
                removeLFU();
            }
            if (freqList.find(1) == freqList.end())
            {
                List *list = new List();
                freqList[1] = list;
            }
            Node *node = new Node(key, value);
            node->freq = 1;
            freqList[1]->insert(node);
            mp[key] = node;
            minFreq = 1;
        }
        else
        {
            Node *node = mp[key];
            node->val = value;
            updateFreqList(node);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */