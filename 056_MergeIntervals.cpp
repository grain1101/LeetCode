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
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
}
class Solution {
  public:
    // 56. Merge Intervals
    static bool cmp(const Interval a, const Interval b) {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0) return {};
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(),cmp);
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start >= ans[ans.size()-1].start && intervals[i].end <= ans[ans.size() -1].end){
                continue;
            }
            if(intervals[i].start < ans[ans.size()-1].start && intervals[i].end > ans[ans.size() -1].end){
                ans[ans.size()-1].start = intervals[i].start;
                ans[ans.size()-1].end = intervals[i].end;
            }
            if(intervals[i].start <= ans[ans.size()-1].end && intervals[i].end > ans[ans.size() -1].end){
                ans[ans.size()-1].end = intervals[i].end;
            }
            if(intervals[i].start > ans[ans.size()-1].end){
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    auto result = s1.merge(intervals);
//    for(auto r : result){
//        for(auto t : r){
//            cout << t<<endl;
//        }
//        cout << endl;
//    }
    cout << result << endl;
    return 0;
}
