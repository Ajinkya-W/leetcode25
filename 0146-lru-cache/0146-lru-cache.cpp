class LRUCache {
public:
    int capacity;
    list<pair<int, int>> lru; // key value
    unordered_map<int, list<pair<int, int>>::iterator>
        keyItrMap; // key to lru iterator
    LRUCache(int cap) : capacity(cap) {}
    int maxCapacity() { return this->capacity; }
    int get(int key) {
        if (keyItrMap.count(key)) {
            int value = keyItrMap[key]->second;
            lru.erase(keyItrMap[key]);
            keyItrMap.erase(key);
            lru.push_back({key, value});
            keyItrMap[key] = prev(lru.end());
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        auto itr = keyItrMap.find(key);
        if (itr != keyItrMap.end()) {
            lru.erase(keyItrMap[key]);
            lru.push_back({key, value});
            keyItrMap[key] = prev(lru.end());
        } else {
            if (maxCapacity() == keyItrMap.size()) {
                auto& front = lru.front();
                keyItrMap.erase(front.first);
                lru.pop_front();
            }
            lru.push_back({key, value});
            keyItrMap[key] = prev(lru.end());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */