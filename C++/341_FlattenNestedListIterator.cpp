#include "leetcode.h"

class NestedIterator {
public:
    // 341. Flatten Nested List Iterator
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; i--) {
            nodes.push(nestedList[i]);
        }
    }

    int next() {
        int ret = nodes.top().getInteger();
        nodes.pop();
        return ret;
    }

    bool hasNext() {
        while(!nodes.empty()){
            auto cur = nodes.top();
            if (cur.isInteger()) {
                return true;
            }
            vector<NestedInteger>& tmp = cur.getList();
            nodes.pop();
            for(int i = tmp.size() - 1; i >=0; i--){
                nodes.push(tmp[i]);
            }
        }
       return false;
    }
private:
    stack<NestedInteger> nodes;
};

int main() {
    Solution s1;
    vector<int> nums = {2,3,1,4, 5};
    int n = 7;
    auto ans = s1.countBits(n);
    showV(ans);
    int tmp = n&(n-1);
    cout << tmp << endl;
    //cout << ans << endl;
}
