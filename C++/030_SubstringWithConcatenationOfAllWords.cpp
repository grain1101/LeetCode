#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 30. Substring with Concatenation of All Words
    // Use two unordered_map to store words.
    // **need do more times.
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.size()==0 || words.size()==0 || words[0].size() > s.size()) return result;
        unordered_map<string, int> counts;
        for(string word : words){
            counts[word]++;
        }
        int n = s.size();
        int num = words.size();
        int len = words[0].size();
        for(int i=0;i<n-num*len+1;i++){
            unordered_map<string, int> seen;
            int j=0;
            for(;j<num;j++){
                string word = s.substr(i+j*len, len);
                if (counts.find(word) != counts.end()){
                    seen[word]++;
                    if (seen[word] > counts[word]) break;
                }
                else break;
            }
            if (j == num) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1, 1, 2};
    string s = "()[[]{}";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(0);
    ListNode *p = head;
    int n = 3;
    vector<ListNode*> lists;

    // 2. Run
    Solution s1;
    auto result = s1.removeDuplicates(nums);
    // 3. Compare output
    cout << result << endl;
    return 0;
}
