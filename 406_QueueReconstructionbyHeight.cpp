#include "leetcode.h"

// 406. Queue Reconstruction by Height
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
            //  [7,0],[7,1],[6,1],[5,0],[5,2],[4,4]
        };
        sort(people.begin(), people.end(), cmp);
        vector<pair<int, int>> ret;
        for(auto& p : people){
            ret.insert(ret.begin() + p.second, p);
//            for(auto p : ret){
//                cout << "[" << p.first << " " << p.second <<"] ";
//            }
//            cout << endl;
        }
        return ret;
    }
};



int main() {
    Solution s1;
    vector<pair<int,int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    auto ans = s1.reconstructQueue(people);
    //cout << ans << endl;
}
