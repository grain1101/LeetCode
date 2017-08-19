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
    // 68. Text Justification
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int p = 0; // ans[i] start word index
        int l = 0; // the line's characters length
        for(int i = 0; i < words.size(); i++){
            int len = l + (i - p) + words[i].size() ;
            if(len > maxWidth || i == words.size()-1){
                //cout << "len:" << ans.size() + 1 << endl;
                int carry = (len <= maxWidth);
                bool lastline = carry && (i == words.size()-1);
                int wsBlock = i - 1 - p + carry;
                int wsNum = maxWidth - l;
                if(carry) wsNum -= words[i].size();
                if (lastline && len < maxWidth) wsBlock++;
                string s = "";
                while(p <= i - 1 + carry){
                    s += words[p];
                    //cout << wsNum << " " << wsBlock << endl;
                    if(wsNum){
                        int ws = wsNum/wsBlock + (wsNum%wsBlock?1:0);
                        if (lastline && wsBlock>1) ws = 1;
                        s.append(ws, ' ');
                        wsNum -= ws;
                        wsBlock--;
                    }

                    p++;
                }
                //cout << s << endl;
                ans.push_back(s);

                p = i;
                l = words[i].size();
                if(len > maxWidth && i == words.size()-1){
                    string s;
                    s += words[i];
                    s.append(maxWidth - words[i].size(), ' ');
                    ans.push_back(s);
                }

            }else {
                //cout << i << endl;
                l += words[i].size();
            }
        }
        //if(p == words.size() - 1) ans.push_back(words[p]);
        return ans.size()==0?words:ans;
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int n = 60;
    auto result = s1.fullJustify(words, n);
    for(auto row : result){
        cout << row << endl;
    }
//    cout << result << endl;
    return 0;
}
