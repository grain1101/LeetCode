#include "leetcode.h"

// 535. Encode and Decode TinyURL
class Solution {
    static int id;
public:
    Solution(){
        init();
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longURL2key.find(longUrl) == longURL2key.end()) {
            longURL2key[longUrl] = id++;
            key2LongURL.push_back(longUrl);
        }
        return id2Hash(longURL2key[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return key2LongURL[hash2Id(shortUrl)];
    }
private:
    vector<string> key2LongURL;
    unordered_map<string, int> longURL2key;
    const int hashLen = 6;
    const int base = 62;
    const string idx2char = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<int> char2idx;
    void init(){
        id = 0;
        char2idx.assign(128, 0);
        for(int i = 0; i < idx2char.size(); i++){
            char2idx[idx2char[i]] = i;
        }
    }

    // convert i to 62 base;
    string id2Hash(int id){
        string ret(hashLen, '0');
        for(int i = 0; i < hashLen; i++){
            ret[i] = idx2char[id % base];
            id = id/ base;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    int hash2Id(string s){
        int ret = 0;
        for(int i = 0; i < hashLen; i++){
            ret = ret * base + char2idx[s[i]];
        }
        return ret;
    }
};

int Solution::id = 0;

int main() {
    Solution solution;
    cout << solution.decode(solution.encode("https://leetcode.com/problems/design-tinyurl"))<< endl;
    cout << solution.decode(solution.encode("https://leetcode.com/problems/design-tinyurl1"))<< endl;
    cout << solution.decode(solution.encode("https://leetcode.com/problems/design-tinyur2l"))<< endl;
    cout << solution.decode(solution.encode("https://leetcode.com/problems/design-tinyur3l"))<< endl;
    //showV(ans);
    //cout << ans << endl;
}
