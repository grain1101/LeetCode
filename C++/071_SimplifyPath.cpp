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
    // 71. Simplify Path
    string simplifyPath(string path) {
        stack<string> content;
        string tmp;
        for(int i = 0; i < path.size(); i++){
            if (path[i] == '/' && tmp.size() != 0){
                if (tmp == ".") continue;
                else if (tmp == ".." && !content.empty()) content.pop();
                else {
                    content.push(tmp);
                    tmp = "";
                }
            } else {
                tmp += path[i];
            }
        }
        string ans ;
        while(content.size() != 0){
            ans += "/" + content.top();
            content.pop();
        }
        return ans;
    }
};

int main() {
    auto result = s1
    cout << result << endl;
    return 0;
}
