#include "leetcode.h"

// 399. Evaluate Division
class Solution {
typedef pair<string, string> PSS;
typedef pair<int, double> Edge;
public:
    vector<double> calcEquation(vector<PSS> equations, vector<double>& values, vector<PSS> queries) {
        generateNodes(equations);
        buildGraph(equations, values);
        vector<double> ret;
        for(const auto& q : queries){
            ret.push_back(calculate(q));
        }
        return ret;
    }
private:
    unordered_map<string, int> str2idx;
    vector<string> strs;
    vector<vector<Edge>> graph;
    vector<int> isZero;
    vector<double> mark;
    // build two mappings from string to idx and idx to string.
    void generateNodes(const vector<PSS>& equations){
        set<string> sets;
        for(const auto& e : equations){
            sets.insert(e.first);
            sets.insert(e.second);
        }
        strs.clear();
        for(const auto& s : sets){
            strs.push_back(s);
        }
        for(int i = 0; i < strs.size(); i++){
            str2idx[strs[i]] = i;
        }
    }
    void buildGraph(const vector<PSS>& equations, const vector<double>& values){
        graph.assign(strs.size(), vector<Edge>());
        isZero.assign(strs.size(), 0);
        for(int i = 0; i < equations.size(); i++){
            const auto& p = equations[i];
            int u = str2idx[p.first];
            int v = str2idx[p.second];
            if (values[i] == 0){
                isZero[u] = 1;
                continue;
            }
            graph[u].push_back({v, values[i]});
            graph[v].push_back({u, 1 / values[i]});
        }
    }
    double calculate(const PSS& q){
        // f/f; (-1);
        if (str2idx.find(q.first) == str2idx.end() || str2idx.find(q.second) == str2idx.end()) return -1.0;

        // a/a; a==0 (-1)|| a!=0 (1)
        int a = str2idx[q.first];
        int b = str2idx[q.second];
        if (a == b) return isZero[a] == 1 ? -1.0 : 1.0;

        // a/b; b==0 (-1)|| a==0 (0)|| a!=0&&b!=0 dfs(a,b)
        if (isZero[b]) return -1.0;
        if (isZero[a]) return 0;
        mark.assign(strs.size(), -1);
        dfs(a, b, 1);
        return mark[b];
    }
    void dfs(int r, int d, double c){
        if (mark[r] != -1) return;
        mark[r] = c;
        if (r == d) return;
        for(const auto& e : graph[r]){
            dfs(e.first, d, c * e.second);
        }
    }
};



int main() {
    Solution s1;
    string num = "101002";
    int k = 2;
    auto ans = s1.removeKdigits(num, k);
    cout << ans << endl;
}
