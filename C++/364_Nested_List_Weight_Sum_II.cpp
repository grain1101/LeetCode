#include "leetcode.h"
/**
364_Nested_List_Weight_Sum_II.cpp
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.
Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e.,
the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1: [[1,1],2,[1,1]] = (four 1's at depth 1, one 2 at depth 2)

Example 2: [1,[4,[6]]] = 1*3 + 4*2 + 6*1 = 17
*/


class Solution  {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int ret = 0;
        vector<int> v;
        for(auto n : nestedList){
            helper(n, 0, v);
        }
        for(int i = 0; i < v.size(); i++){
            ret += v[i] * (v.size() - i);
        }
        return ret;
    }
    void helper(NestedInteger& cur, int depth, vector<int>& v){
        if (v.size() <= depth) v.push_back({0});
        if (cur.isInteger()) v[depth] += cur.getInteger();
        else{
            for(auto next : cur){
                helper(next, depth + 1, v);
            }
        }
    }
    // BFS
    int depthSumInverse_weighted(vector<NestedInteger>& nestedList) {
        int unweighted = 0, weighted = 0;
        queue<vector<NestedInteger>> q;
        q.push(nestedList);
        while(!q.empty()){
            int len = q.size();
            while(len--){
                auto cur = q.front();
                q.pop();
                for(auto n : cur){
                    if (n.isInteger()) unweighted += n.getInteger();
                    else q.push(n);
                }
            }
            weighted += unweighted;
        }
        return weighted;
    }
};


int main() {
    Solution s1;

}
