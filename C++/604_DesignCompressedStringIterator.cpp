#include "leetcode.h"

// 604. Design Compressed String Iterator
// "L1e2t1C1o1d1e1"
class StringIterator {
public:
    StringIterator(string compressedString) {
        idx = 0;
        cnt = 0;
        len = 0;
        s = compressedString;
    }

    char next() {
        //cout << idx < s.size() << endl;
        while(idx < s.size()){
                cout << idx << " ";
            char ret;
            if (cnt == 0){
                int p = idx + 1;
                while(p < s.size() && isdigit(s[p])){
                    p++;
                }
                cnt = stoi(s.substr(idx + 1, p - idx - 1));
                len = p - idx - 1;
                ret = s[idx];
            }else {
                ret = s[idx];
            }

            cnt--;
            if (cnt == 0) idx += len + 1;
            return ret;
        }
        return ' ';
    }

    bool hasNext() {
        if (idx < s.size() || cnt > 0) return true;
        return false;
    }
private:
    int idx;
    int cnt;
    int len;
    string s;
};


int main() {
    string s = "L1e2t1C1o1d1e1";
    StringIterator *s1 = new StringIterator(s);
    cout << s1->next() << endl;
    cout << s1->next() << endl;
    cout << s1->next() << endl;
    cout << s1->next() << endl;
    cout << s1->next() << endl;
    cout << s1->next() << endl;
    cout << s1->hasNext() << endl;
    cout << s1->next() << endl;
    cout << s1->hasNext() << endl;
}
