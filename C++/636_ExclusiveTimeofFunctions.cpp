#include "leetcode.h"

struct Info{
    int id;
    string status;
    int time;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n, 0);
        vector<Info> func(logs.size());
        stack<Info> st;
        s2Info(logs, func);
        for(auto f : func){
            if (f.status == "start") {
                st.push(f);
            }
            else {
                auto start = st.top();
                st.pop();
                int len = f.time - start.time + 1;
                ret[f.id] += len;
                if (!st.empty()){
                    auto pre = st.top();
                    ret[pre.id] -= len;
                }
            }
        }
        return ret;
    }
    void s2Info(vector<string>& logs, vector<Info>& func){
        for(int f = 0; f < logs.size(); f++){
            string s = logs[f];
            int j = 0;
            int part = 0;
            int first = s.find(':');
            int second = s.find(':', first + 1);
            func[f].id = stoi(s.substr(0, first));
            func[f].status = s.substr(first + 1, second - first - 1);
            func[f].time = stoi(s.substr(second + 1, s.size() - second));
        }
    }
};

int main() {
    Solution s1;

    int n = 2;
    vector<string> logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};

    auto ans = s1.exclusiveTime(n, logs);
    showV(ans);

}
