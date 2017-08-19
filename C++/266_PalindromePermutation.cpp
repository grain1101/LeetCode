class Palindrome {
public:
    // 266_PalindromePermutation hash map
    // Given a string, determine if a permutation of the string could form a palindrome.
     bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for(auto c : s) m[c]++;
        int cnt = 0;
        for(auto it = m.begin(); it!=m.end(); it++){
            if (it->second % 2) cnt++;
        }
        return cnt == 0 || (cnt == 1 && s.size() % 2 == 1);
     }
     // 266_PalindromePermutation set
     bool canPermutePalindrome(string s) {
        set<char> s;
        for(auto c : s) {
            if (s.find(c) == s.end()) s.insert(c);
            s.erase(c);
        }
        return s.size() <= 1;
     }
};
