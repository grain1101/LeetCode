#include "leetcode.h"

// 599. Minimum Index Sum of Two Lists
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.size() > list2.size()) return findRestaurant(list2, list1);
        unordered_map<string, int> map1, map2;
        for(int i = 0; i < list1.size(); i++){
            map1[list1[i]] = i;
        }
        for(int i = 0; i < list2.size(); i++){
            map2[list2[i]] = i;
        }
        vector<pair<int, string>> ret;
        for(int i = 0; i < list1.size(); i++){
            if (map2.find(list1[i]) != map2.end()){
                ret.push_back({i+map2[list1[i]], list1[i]});
            }
        }
        sort(ret.begin(), ret.end());
        vector<string> ans;
        ans.push_back(ret[0].second);
        for(int i = 1; i < ret.size(); i++){
            if (ret[i].first == ret[0].first) ans.push_back(ret[i].second);
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<string> list1 = {"Shogun", "KFC"};
    vector<string> list2 = {"KFC", "Shogun", "Burger King"};
    auto ans = s1.findRestaurant(list1, list2);
    showV(ans);
    //cout << ans << endl;
}
