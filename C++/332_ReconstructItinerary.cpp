#include "leetcode.h"

class Solution {
public:
    // 332. Reconstruct Itinerary
    // Eulerian path
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto t : tickets){
            targets[t.first].insert(t.second);
        }
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());

//        st.push("JFK");
//        dfs(st);
        // same as
//        reverse(route.begin(), route.end());
//        return route;
    }
private:
    unordered_map<string, multiset<string>> targets;
    vector<string> route;
    stack<string> st;
    void visit(string airport){
        while(targets[airport].size()){
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }
    void dfs(stack<string>& st){
        if (st.empty()) return;
        string top = st.top();
        if (targets[top].empty()){
            route.push_back(top);
            st.pop();
        }else {
            st.push(*targets[top].begin());
            targets[top].erase(targets[top].begin());
        }
    }
};

int main() {
    Solution s1;
    auto ans = s1.isValidSerialization(s);
    cout << ans << endl;
}
