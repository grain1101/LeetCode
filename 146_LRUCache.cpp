#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
#include <cassert>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}
void showV(auto& result){
    for(auto r : result)
        cout << r;
    cout << endl;
}
struct LRUNode {
    int key;
    int val;
    LRUNode *prev;
    LRUNode *next;
    LRUNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr){}
 };

class LRUCache {
public:
    // 146. LRU Cache
    LRUCache(int capacity) : _capacity(capacity),
                             _size(0),
                             _dummy(new LRUNode(-1, -1)){
        _dummy->prev = _dummy;
        _dummy->next = _dummy;
    }
    ~LRUCache(){
        delete _dummy;
    }
    void deleteFromList(LRUNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

    }
    void insertToListHead(LRUNode *node){
        node->next = _dummy->next;
        _dummy->next->prev = node;
        _dummy->next = node;
        node->prev = _dummy;
    }
    int get(int key) {
        if (_hashIndex.find(key) == _hashIndex.end()){
            return -1;
        }
        // update (key, value) to list head
        LRUNode *node = _hashIndex[key];
        if (node->prev == _dummy) return node->val;
        deleteFromList(node);
        insertToListHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (_hashIndex.find(key) != _hashIndex.end()){
            LRUNode *oldNode = _hashIndex[key];
            deleteFromList(oldNode);
            oldNode->val = value;
            insertToListHead(oldNode);
        } else {
            LRUNode *newNode = new LRUNode(key, value);
            _hashIndex[key] = newNode;
            if (_size < _capacity){
                insertToListHead(newNode);
                _size++;
            } else {
                LRUNode *tmp = _dummy->prev;
                _hashIndex.erase(tmp->key);
                deleteFromList(_dummy->prev);

                delete tmp;
                insertToListHead(newNode);
            }
        }
    }
private:
    int _capacity;
    int _size;
    unordered_map<int, LRUNode*> _hashIndex;
    LRUNode *_dummy;
};

int main() {
    LRUCache cache =  LRUCache( 2 /* capacity */ );


    cache.put(2, 1);
    cache.put(3, 2);
    assert(cache.get(3)==2);       // returns 1
    assert(cache.get(2) == 1);       // returns -1 (not found)
    cache.put(4, 3);    // evicts key 2
    assert(cache.get(2) == 1);       // returns -1 (not found)
    assert(cache.get(3) == -1);       // returns 3
    assert(cache.get(4) == 3);       // returns 4
}
