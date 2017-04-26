#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
#include <string>
#include<list>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}
void showV(auto& result){
    for(auto r : result)
        cout << r << " ";
    cout << endl;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 210. Course Schedule II
    // BFS topology order
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        if (prerequisites.size() == 0) {
            for(int i = numCourses - 1; i >=0; i--){
                ans.push_back(i);
            }
            return ans;
        }
        generateGraph(numCourses, prerequisites);
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i].first]++;
        }
        queue<int> zeros;
        for(int i = 0; i < numCourses; i++){
            int v = 0;
            for(int j = 0; j < numCourses; j++){
                if (inDegree[j] == 0) zeros.push(j);
            }
            if (zeros.empty()) return {}
            while(zeros.size()){
                int node = zeros.front();
                zeros.pop();
                ans.push_back(node);
                inDegree[node] = -1;
                for(auto v : graph[node]){
                    inDegree[v]--;
                    if (inDegree[v] ==0) zeros.push(v);
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> graph;
    void generateGraph(int numcourse, const vector<pair<int, int>>& prerequisites) {
        graph.assign(numcourse, vector<int>());
        for(auto p : prerequisites){
            graph[p.second].push_back(p.first);
        }
    }
};



int main() {
    Solution s1;
    vector<int> nums = {10,2,3};
    auto ans = s1.minSubArrayLen(6, nums);
    cout << ans << endl;
}
