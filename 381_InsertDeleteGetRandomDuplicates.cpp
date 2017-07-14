#include "leetcode.h"
/**
use two data structure: hash map and vector.
unordered_map<val, idx>
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
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int r = *m[val].begin();
        m[val].erase(r);
        if (m[val].empty()) m.erase(val);
        int vSize = v.size() - 1;
        m[v[vSize]].insert(r);
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
    void show(){
        showV(v);
        cout << "m:";
        for(auto p : m) {
            cout << p.first << endl;
            cout << "p.second ";
            showV(p.second);
        }
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
