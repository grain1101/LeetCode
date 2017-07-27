#include "leetcode.h"
/**
use two data structure: hash map and vector.
unordered_map<val, set<idx>>
m
vector, swap(remove, end) O(1)remove end;
Caution: update unordered_map[end] idx;
Leetcode: 381. Insert Delete GetRandom O(1) - Duplicates allowed
*/


class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(nullptr));
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = false;
        if (m.find(val) == m.end()) flag = true;
        m[val].insert(v.size());
        v.push_back(val);
        return flag;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    // O(1) remove;
    // swap(position, end);
    // v.pop_back();
    bool remove(int val) {
        // m[value] = unordered_set<ind>(idx);
        if (m.find(val) == m.end()) return false;
        int r = *m[val].begin();    // find one position of val in unordered_set;
        m[val].erase(r);            // erase from unordered_set
        if (m[val].empty()) m.erase(val);   // if the unordered_set is empty, hashmap need to erase it.
        int vSize = v.size() - 1;
        int endValue = v[vSize];
        m[v[vSize]].insert(r);      // insert end element's new idx(position) into hashmap;
        m[v[vSize]].erase(vSize);
        if (m[v[vSize]].empty()) m.erase(v[vSize]);
        swap(v[r], v[vSize]);
        v.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand() % v.size()];
    }
private:
    vector<int> v;
    unordered_map<int, unordered_set<int>> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
    RandomizedCollection obj;
    vector<string> action = {"insert","remove","insert","remove","getRandom","getRandom","getRandom","getRandom",
                            "getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"};
    vector<int> para = {{0},{0},{-1},{0},{},{},{},{},{},{},{},{},{},{}};
    for(int i = 0; i < action.size(); i++){
        if (action[i] == "insert"){
            cout << obj.insert(para[i]);
        }
        else if (action[i] == "remove"){
            cout << obj.remove(para[i]);
        }
        else {
            cout << obj.getRandom();
        }
        cout << endl;
        //cout << "show: ";
        //obj.show();
    }
}
