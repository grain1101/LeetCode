#include "leetcode.h"
/**
use two data structure: hash map and vector.
unordered_map<val, idx>
vector, swap(remove, end) O(1)remove end;
Caution: update unordered_map[end] idx;
Leetcode: 380_Insert Delete GetRandom O(1)
*/


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(nullptr));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mapping.find(val) != mapping.end()) return false;
        mapping[val] = v.size();
        v.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mapping.find(val) == mapping.end()) return false;
        mapping[v[v.size() - 1]] = mapping[val];
        swap(v[mapping[val]], v[v.size() - 1]);
        v.pop_back();
        mapping.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
private:
    unordered_map<int, int> mapping;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
    Solution s1;
    int n = 5;
    vector<int> nums(n);
    vector<int> freq(n);
    for(int i = 0; i < n; i++){
        nums[i] = i;
        freq[i] = rand()% n;
    }
    showV(nums);
    showV(freq);
    cout << s1.pickRandom(nums, freq) << endl;
}
