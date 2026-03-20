class LRUCache {
public:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> itrMap;
    list<pair<int, int>> lru;

    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        auto it = itrMap.find(key);

        if (it == itrMap.end())
            return -1;

        int value = it->second->second;
        lru.erase(it->second);
        lru.push_front({key, value});

        itrMap.erase(it);
        itrMap[key] = lru.begin();
        return value;
    }

    void put(int key, int value) {
        auto it = itrMap.find(key);

        if (itrMap.find(key) != itrMap.end()) {
            lru.erase(it->second);
            itrMap.erase(it);
        }

        lru.push_front({key, value});
        itrMap[key] = lru.begin();

        if (itrMap.size() > capacity) {
            auto it = itrMap.find(lru.rbegin()->first);
            itrMap.erase(it);
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */