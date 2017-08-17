class Solution{
public:
    // 267_Palindrome Permutation II
     // Given a string s, return all the palindromic permutations (without duplicates) of it.
     // Return an empty list if no palindromic permutation could be form.
     // For example:Given s = "aabb", return ["abba", "baab"].  Given s = "abc", return [].
     vector<string> generatePalindromes(string s) {
        unordered_map<char, int> m;
        for(auto c : s) m[c]++;
        string mid = "", l = "";
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second % 2 == 1){
                if (!mid.empty()) return {};
                mid = it->first;
            }
            for(int i = 0; i < it->second / 2; i++) {
                l += it->first;
            }
        }
        // get all permutation of l(left)
        // return l + mid + reverse(l)
        sort(l.begin(), l.end());
        vector<string> ret;
        do{
            ret.push_back(l + mid + string(l.rbegin(), l.rend()));
        }while(nextPermutation(l));
        return ret;
     }
     bool nextPermutation(string& s) {
        int n = s.size();
        for(int i = n - 1; i >=0; i--) {
            if (i + 1 < n && s[i] < s[i + 1]) {
                int j = n - 1;
                for(; j > i; j--) {
                    if (s[j] > s[i]) break;
                }
                swap(s[i], s[j]);
                reverse(s.begin() + i + 1, s.end());
                return true;
            }
        }
        return false;
     }
};
