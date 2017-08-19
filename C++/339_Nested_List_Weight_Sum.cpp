#include "leetcode.h"
/**
	339_Nested_List_Weight_Sum
	 [[1,1],2,[1,1]]
	 [1,[4,[6]]] = 1 * 1 + 4 * 2 + 6 * 3;
*/


class Solution  {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int ret = 0;
        dfs(nestedList, 1, ret);
        return ret;
    }
    void dfs(const vector<NestedInteger>& nestedList, int depth, int& ret){
        for(auto n : nestedList){
            if (n.isInteger()) ret += n.getInteger() * depth;
            else {
                dfs(n.getList(), depth + 1, ret);
            }
        }
    }
};


int main() {
    Solution s1;

}
