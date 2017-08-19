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
    // 207. Course Schedule
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;
        vector<int> inDegree(numCourses, 0);
        int visited = 0;
        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i].second]++;
        }
        generateGraph(numCourses, prerequisites);
        for(int i = 0; i < numCourses; i++){
            int nodes = 0;
            while(nodes < numCourses && inDegree[nodes] != 0){
                nodes++;
            }
            if (nodes == numCourses) return false;
            inDegree[nodes] = -1;
            visited++;
            if (visited == numCourses) return true;
            for(auto v : graph[nodes]){
                inDegree[v]--;
            }
        }
        return true;
    }

private:
    vector<vector<int>> graph;
    void generateGraph(const int numCourses, const vector<pair<int, int>>& prerequisites){
        graph.assign(numCourses, vector<int>());
        for(auto p : prerequisites){
            graph[p.first].push_back(p.second);
        }
    }
};


int main() {
    Solution s1;
    string s = "egg";
    string t = "t2a";
    vector<pair<int,int>> pre(2);
    pre[0] = {0,1};
    pre[1] = {1,2};
    //pre[2] = {2};
    auto ans = s1.canFinish(3, pre);
    cout << ans << endl;
}
