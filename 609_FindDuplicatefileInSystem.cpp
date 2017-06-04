#include "leetcode.h"

// 609. Find Duplicate File in System
class Solution {
public:
    // ["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mapping;
        for(auto s : paths){
            int i = 0;
            while(s[i] != ' ') i++;
            string root = s.substr(0, i);
            for(; i < s.size(); i++){
                if (s[i] == ' ') continue;
                int j = i;
                while(j < s.size() && s[j] != '(') j++;
                string path = root + '/' + s.substr(i, j - i);
                int k = j;
                while(k < s.size() && s[k] != ')') k++;
                string content = s.substr(j, k - j);
                mapping[content].push_back(path);
                i = k;
            }
        }
        vector<vector<string>> ret;
        for(auto it = mapping.begin(); it != mapping.end(); it++){
            if (it->second.size() > 1)
                ret.push_back(it->second);
        }
        return ret;
    }
};

int main() {
    Solution s1;
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    auto ans = s1.findDuplicate(paths);
    show(ans);
}
