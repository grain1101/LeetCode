#include "leetcode.h"
/*
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// 385. Mini Parser
class Solution {
public:
    // "324", "[123,[456,[789]]]",
    NestedInteger deserialize(string s) {
        int idx = 0;
        if (s[idx] == '['){
            return parseLists(s, idx);
        } else {
            return parseNumbers(s, idx);
        }
    }
    NestedInteger parseLists(const string& s, int& idx){
        idx++; // '['
        NestedInteger root;
        while(idx < s.size()){
            char c = s[idx];
            if (c == '['){
                root.add(parseLists(s, idx));
            } else if (c == '-' || isdigit(c)){
                root.add(parseNumbers(s, idx));
            } else if (c == ','){
                idx++;
            } else if (c == ']'){
                idx++;
                break;
            }
        }
        return root;
    }
    NestedInteger parseNumbers(const string& s, int& idx){
        int positive = 1;
        if (s[idx] == '-') {
            positive = -1;
            idx++;
        }
        int n = 0, j = idx;
        while(idx < s.size() && isdigit(s[idx])) idx++;
        n = stoi(s.substr(j, idx - j));
        return NestedInteger(n * positive);
    }
};


int main() {
    Solution s1;
    int n = 234;
    auto ans = s1.lexicalOrder(n);
    cout << ans << endl;
}
