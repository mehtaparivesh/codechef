class node
{
public:
    node *next = NULL, *prev = NULL;
    int val, key;
};

class LRUCache
{
public:
    unordered_map<int, pair<list<int>::iterator, int>> m;
    list<int> dll;
    int cap;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    void ff(int key)
    {
        dll.erase(m[key].first);
        dll.push_front(key);
        m[key].first = dll.begin();
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;

        ff(key);
        return m[key].second;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            m[key].second = value;
            ff(key);
        }
        else
        {
            dll.push_front(key);
            m[key] = {dll.begin(), value};
            cap--;
        }

        if (cap < 0)
        {
            m.erase(dll.back());
            dll.pop_back();
            cap++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */