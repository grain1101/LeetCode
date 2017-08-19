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
#include <set>
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
        cout << r;
    cout << endl;
}


class Solution {
public:
    // 151. Reverse Words in a String
    void reverseWords(string &s) {
        int index = 0, i;
        for(i = 0; i < s.size(); i++){
            if (s[i] != ' ') break;
        }
        for(i; i < s.size(); i++){
            if (s[i] != ' '){
                if (index != 0 && i > 0 && s[i - 1] == ' ') s[index++] = ' ';
                s[index++] = s[i];
            }
        }
        s.resize(index);
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++){
            int j = i;
            while(j < s.size() && s[j] != ' ') j++;
            int p = i;
            int q = j - 1;
            i = j;
            while(p < q){
                swap(s[p++], s[q--]);
            }
        }
        return;
    }
};

int main() {
    Solution s1;
    string s = "   a     ";
    s1.reverseWords(s);
    cout << s << endl;
}
