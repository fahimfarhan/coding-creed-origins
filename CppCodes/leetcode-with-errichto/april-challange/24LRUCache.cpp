#include <bits/stdc++.h>
using namespace std;

/**
 * @brief: I had read about lru in class. never implemented it before
 * I understand some of errichto's implementation
 * 
*/
class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    list<int> accessed;
    int capacity;

    void erase(int key) {
        auto it = mp.find(key);
        if(it != mp.end() ) {
            accessed.erase(it->second.second);
            mp.erase(it);
        }
    }

    void push(int key, int v) {
        accessed.push_back(key);
        mp[key] = {v, prev(accessed.end())};
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if( it == mp.end() ) {
            return -1;
        }
        int oldValue = it->second.first;
        erase(key);
        push(key, oldValue);
        return oldValue;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end() ) {
            erase(key);
        }       
        if( mp.size() == capacity) {
            if(!accessed.empty()) {
                erase(accessed.front());
            }
        }

        push(key, value);
    }
};


int main() {
    return 0;
}