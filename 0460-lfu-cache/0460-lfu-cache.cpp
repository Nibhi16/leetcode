class LFUCache {
private:
    struct Node {
        int key, val, freq;
        Node(int k, int v, int f) : key(k), val(v), freq(f) {}
    };

    int capacity, minFreq;
    unordered_map<int, list<Node>::iterator> keyNode;   // key -> pointer to node
    unordered_map<int, list<Node>> freqList;            // freq -> list of nodes (LRU order)

    void updateFreq(int key) {
        auto it = keyNode[key];
        int freq = it->freq;
        int val = it->val;

        // Remove from current freq list
        freqList[freq].erase(it);
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // Add to next freq list
        freqList[freq + 1].push_front(Node(key, val, freq + 1));
        keyNode[key] = freqList[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || keyNode.find(key) == keyNode.end())
            return -1;

        updateFreq(key);
        return keyNode[key]->val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // If key exists — update value and frequency
        if (keyNode.count(key)) {
            keyNode[key]->val = value;
            updateFreq(key);
            return;
        }

        // If cache is full — evict LFU key
        if (keyNode.size() == capacity) {
            auto &listRef = freqList[minFreq];
            auto it = listRef.back();

            keyNode.erase(it.key);
            listRef.pop_back();
            if (listRef.empty())
                freqList.erase(minFreq);
        }

        // Insert new key with freq = 1
        freqList[1].push_front(Node(key, value, 1));
        keyNode[key] = freqList[1].begin();
        minFreq = 1;
    }
};
